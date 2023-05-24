#include "simulation.h"
#include "book.h"
#include "ebook.h"
#include "magazine.h"
#include "bookcollection.h"
#include "file_operation.h"
#include "clients_list.h"
#include "client.h"
// #include "seller.h"
#include "sellers_list.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <thread>
#include <vector>
#include <memory>

Simulation::Simulation() {}

void Simulation::do_simulation(std::vector<std::string> parameters)
{
    /*
    File_operation file_in("simulation_start.txt"); // read from file_in
    std::vector<std::string> start_table = file_in.open_file("simulation_start.txt");
    int time_max = std::stoi(start_table[0]);
    // std::cout << "time max \t" << time_max << std::endl;
    */
    std::ofstream file; // write to file
    file.open("simulation_results.txt", std::ios::out);
    file << "Simulation results: " << std::endl;

    int time = 0;
    int time_max = std::stoi(parameters[0]);
    int number_of_sellers = std::stoi(parameters[1]);
    int number_of_clients = std::stoi(parameters[2]);
    // int number_of_actions = 3; // tutaj do przemyślenia(zmienienia) 1-pytanie, 2-zakup

    std::cout << "Given parameters:\n";
    std::cout << "Time of simulation\t\t" << time_max << std::endl;
    std::cout << "Number of sellers\t\t" << number_of_sellers << std::endl;
    std::cout << "Initial number of clients\t" << number_of_clients << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // stworzenie listy obiektów typu sprzedawca
    std::srand(std::time(nullptr));
    SellersList list_of_sellers;
    list_of_sellers.make_list(number_of_sellers);
    list_of_sellers.print_list();
    // stworzenie listy obiektów typu klient
    ClientsList list_of_clients;
    list_of_clients.make_list(number_of_clients);
    list_of_clients.print_list();
    // std::cout << "\n";

    std::string text = "books.txt";
    File_operation File_b(text);
    std::vector<std::vector<std::string>> M = File_b.open_book_file(text);
    // File_b.print_book_file(M);
    int number_of_books = (int)M.size();
    std::cout << "Initial number of books\t\t" << number_of_books << std::endl
              << std::endl
              << "List of books:\n";

    Bookcollection collection_of_books; // initialize book collection
    collection_of_books.make_list_from_file(M);
    collection_of_books.print_list();

    // int randomAction = 0;
    //unsigned int client_id = 1, x = 1; //, new_client_id; // first client to service
    // random book for all clients
    int randomBook_id = 0;
    for(auto &client_ptr : list_of_clients.get_clients())
    {
        randomBook_id = std::rand() % number_of_books + 1;
        client_ptr -> set_id_of_book(randomBook_id);
    }

    //randomBook_id = std::rand() % number_of_books;
    int number_of_now_servicing_clients = std::min(number_of_clients, number_of_sellers);
    // int numbers_of_iteration = number_of_now_servicing_clients;
    ClientsList now_servicing_clients;
    ClientsList clients_in_queue;
    clients_in_queue = now_servicing_clients.pass_client_to_queue(list_of_clients, number_of_now_servicing_clients, list_of_sellers);


    std::cout << "\nSIMULATION STARTED\n";
    bool end = false;
    while (time < time_max) // simulation loop
    {
        std::cout << "\nTIME[s]: " << time << "\n";
        for(auto &client_ptr : now_servicing_clients.get_clients())
        {
            Book book = collection_of_books.find_book_by_isbn(client_ptr -> get_book_id());
            std::cout << client_ptr -> get_name() << ' ' << client_ptr -> get_surname() << " with ID: "
            << client_ptr -> get_id() << ' ' << "Wants to " << client_ptr -> get_activity() << ":\n";
            std::cout << book.get_author() << ' ' << book.get_title() << "\n";
            //file << client_ptr -> get_name() << ' ' << client_ptr -> get_surname() << " with ID: "
            //<< client_ptr -> get_id() << ' ' << "Wants to " << client_ptr -> get_activity() << ":\n";
            //std::cout << book.get_author() << ' ' << book.get_title() << "\n";
            client_ptr -> set_actual_state();
            if(client_ptr -> get_state() == State::serviced)
            {
                Seller seller = list_of_sellers.find_seller_by_id(client_ptr -> get_seller_id());
                if(client_ptr -> get_purpose() == Purpose::ask)
                {
                    seller.answer_question(book);
                }
                else
                {
                    seller.bill_presentation(book, client_ptr -> get_purpose());
                }
                if(clients_in_queue.get_clients().empty())
                {
                    end = true;
                    break;
                }
                std::shared_ptr<Client> new_client = clients_in_queue.get_clients().front();
                new_client -> set_seller(seller.get_id());
                if(new_client -> get_purpose() == Purpose::ask)
                {
                    new_client -> set_state(State::servicing3);
                }
                else if(new_client -> get_purpose() == Purpose::order)
                {
                    new_client -> set_state(State::servicing2);
                }
                else if(new_client -> get_purpose() == Purpose::buy)
                {
                    new_client -> set_state(State::servicing1);
                }
                now_servicing_clients.add_client_as_ptr(new_client);
                now_servicing_clients.delete_client(client_ptr -> get_id());
                clients_in_queue.delete_client(new_client -> get_id());
            }
            else std::cout << "\n";
        }
            /*
            x = client_id;
            client_id = list_of_clients.return_first_client();
            // std::cout << " x, client_id = " << x << " " << client_id << "   ";
            //    new_client_id = cl.return_first_client();
            if (x == client_id) // servicing the same client which is in previous loop
            {
                list_of_clients.simulation_step(client_id, collection_of_books.get_state(randomBook_id));
                // bc.change_availability(randomBook, randomAction);
            }
            else // start servicing the new client so theres need to choose new book
            {
                // for (int i = 0; i < number_of_sellers; i++)
                //{
                //  Client a = cl.find_client_by_id(client_id);

                randomBook_id = std::rand() % number_of_books; // choosing book
                list_of_clients.simulation_step(client_id, collection_of_books.get_state(randomBook_id));
                // bc.change_availability(randomBook, randomAction);
            }
            */

            //std::cout << " Client nr " << client_id
            //        << " wants to " << list_of_clients.activity(client_id) << /* enumToString(a.get_purpose()) <<*/ " book titled: " << collection_of_books.print_title(randomBook_id)
             //       << " and obtained response price: " << collection_of_books.calculate_book_price(randomBook_id) << " client is: " << list_of_clients.get_state(client_id) << " by " << std::endl; // print in terminal simulation results

            //file << "TIME[s]: " << time << " Client nr " << client_id
            //    << " wants to " << list_of_clients.activity(client_id) << /* enumToString(a.get_purpose()) <<*/ " book titled: " << collection_of_books.print_title(randomBook_id)
             //   << " and obtained response price: " << collection_of_books.calculate_book_price(randomBook_id) << " client is: " << list_of_clients.get_state(client_id) << " by " << std::endl; // save to file simulation result

           // std::this_thread::sleep_for(std::chrono::seconds(1));
            // client_id++;
        time++;
        if(end)
        {
            std::cout << "All clients have been served\nEnd of simulation\n";
            break;
        }
    }
    // std::cout << "\nEnd of simulation, books status:\n";
    // bc.print_list();
    file.close();
}
