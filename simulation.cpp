#include "simulation.h"
#include "book.h"
#include "ebook.h"
#include "magazine.h"
#include "bookcollection.h"
#include "file_operation.h"
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
    int number_of_books = 27; // std::stoi(parameters[3]);

    std::cout << "Given parameters:\n";
    std::cout << "Time of simulation\t\t" << time_max << std::endl;
    std::cout << "Number of sellers\t\t" << number_of_sellers << std::endl;
    std::cout << "Initial number of clients\t" << number_of_clients << std::endl;
    std::cout << "Initial number of books\t\t" << number_of_books << std::endl
              << std::endl
              << "Start simulation\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // stworzenie listy obiektów typu sprzedawca
    // stworzenie listy obiektów typu klient

    Book b1("Joanne K. Rowling", "Harry Potter and the Philosopher's Stone", 1, "fiction", 151.96, "available");
    Book b2("Joanne K. Rowling", "Harry Potter and the Chamber of Secrets", 2, "fiction", 151.96, "available");
    Book b3("Joanne K. Rowling", "Harry Potter and the Prisoner of Azkaban", 3, "fiction", 151.96, "available");
    Book b4("Joanne K. Rowling", "Harry Potter and the Goblet of Fire", 4, "fiction", 151.96, "available");
    std::cout << "\t To będzie wprowadzony magazyn\n";
    Magazine m1("autor", "magazine", 5, "news", 35.1, "available", 10, "2020");
    //  Ebook e1("Joanne K. Rowling", "Harry Potter and the Philosopher's Stone", 5, "fiction", 21.99, "available", "pdf");
    //

    m1.print();

    Bookcollection bc;
    bc.add_book(b1);
    bc.add_book(b2);
    bc.add_book(b3);
    bc.add_book(b4);
    // bc.add_ebook(e1);
    // bc.add_magazine(m1);

    std::cout << bc.size() << std::endl;
    bc.print_list();

    while (time < time_max) // simulation loop
    {

        std::cout << "TIME[s]: " << time << ",  Action : "
                  << "Client number x _activity_ book titled y" << std::endl; // print in terminal simulation results
        file << time << std::endl;                                            // save to file simulation result
        std::this_thread::sleep_for(std::chrono::seconds(1));
        time++;
    }
    file.close();
}