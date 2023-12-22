// Airline Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "Database.h"

using namespace std;

Database d;



int main()
{
    bool running = true;
    string cmd;

    cout << "Mariam's Airline Database, type 'help' for more information! type 'exit' to terminate the program!" << endl;

    while (running) {

        // log the command input
        getline(cin, cmd);

//changes it to lowercase, so it's recognized no matter what
			// std libr function
        std::for_each(cmd.begin(), cmd.end(), [](char & c){
            c = ::tolower(c);
        });

        if (cmd == "exit") // exit if it's 'exit'
            running = false;
        else // run the command
            d.runCommand(cmd);

        cout << endl;
    }
}