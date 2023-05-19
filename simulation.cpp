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
    int number_of_actions = 3; // tutaj do przemyślenia(zmienienia) 1-pytanie, 2-zakup

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
    int randomIndex, randomAction;

    std::cout << "\nSIMULATION STARTED\n";
    while (time < time_max) // simulation loop
    {
        randomIndex = std::rand() % number_of_books;    // choosing book
        randomAction = std::rand() % number_of_actions; // chosing action - asking or buying book
        bc.change_availability(randomIndex, randomAction);
        std::cout << "TIME[s]: " << time << ",  Action : "
                  << "Client <index of client> " << randomAction << " book titled: " << bc.print_title(randomIndex) << std::endl; // print in terminal simulation results
        file << "TIME[s]: " << time << ",  Action : "
             << "Client <index of client> " << randomAction << " book titled: " << bc.print_title(randomIndex) << std::endl; // save to file simulation result
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time++;
    }
    std::cout << "\nEnd of simulation, books status:\n";
    bc.print_list();
    file.close();
}