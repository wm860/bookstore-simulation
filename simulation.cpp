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
    // stworzenie listy obiektów typu klient
    ClientsList cl;
    cl.make_list(number_of_clients);
    cl.print_list();
    std::cout << "\n";

    std::string text = "books.txt";
    File_operation File_b(text);
    std::vector<std::vector<std::string>> M = File_b.open_book_file(text);
    // File_b.print_book_file(M);
    int number_of_books = (int)M.size();
    std::cout << "Initial number of books\t\t" << number_of_books << std::endl
              << std::endl
              << "List of books:\n";

    Bookcollection bc; // initialize book collection
    bc.make_list_from_file(M);
    bc.print_list();

    std::srand(std::time(nullptr));
    int randomBook_id = 0;
    int randomAction = 0;
    // bool sim_step;
    unsigned int client_id; // first client to service

    std::cout << "\nSIMULATION STARTED\n";
    while (time < time_max) // simulation loop
    {
        std::cout << "TIME[s]: " << time;
        client_id = cl.return_first_client();

        for (int i = 0; i < number_of_sellers; i++)
        {
            // Client a = cl.find_client_by_id(client_id);
            randomBook_id = std::rand() % number_of_books; // choosing book
            cl.simulation_step(client_id, bc.get_state(randomBook_id));
            // bc.change_availability(randomBook, randomAction);

            std::cout << " Client nr " << client_id << " " << /* enumToString(a.get_purpose()) <<*/ " book titled: " << bc.print_title(randomBook_id)
                      << "and obtained response price: " << bc.calculate_book_price(randomBook_id) << std::endl; // print in terminal simulation results

            file << "TIME[s]: " << time << ",  Action : "
                 << " Client <index of client> " << randomAction << " book titled: " /*<< bc.print_title(randomBook)*/ << std::endl
                 << "u sprzedawcy numer :"; // save to file simulation result

            std::this_thread::sleep_for(std::chrono::seconds(1));

            client_id++;
            time++;
        }
    }
    // std::cout << "\nEnd of simulation, books status:\n";
    // bc.print_list();
    file.close();
}