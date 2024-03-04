/**
 * CatCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for CatCommand class.
*/

#include "mockos/CatCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"

#include <iostream>
#include <sstream>

CatCommand::CatCommand(AbstractFileSystem* sys) : system(sys) {}

void CatCommand::displayInfo() {
    std::cout << "cat writes to a file. cat can be invoked with the command: cat <filename> [-a]" << std::endl;
}

int CatCommand::execute(std::string args) {
    
    // Extract file name from input
    std::istringstream iss(args);
    std::string file_name;
    std::string arg;
    iss >> file_name;

    
    // Track if write or append
    bool write = true;

    // Check if additional arguments were provided
    if (iss >> arg) {
        if (arg != "-a") { // Cat only accepts -a
            return INVALID_CMD_OPTION;
        }
        else { // -a has been provided.
            write = false;
        }
    }

    // Open file
    AbstractFile* file = system->openFile(file_name);

    // Make sure file was found before reading from it
    if (file == nullptr) {
        return FILE_DOES_NOT_EXIST;
    }

    // Print unformatted file 
    std::vector<char> contents = file->read();
    for (char c : contents) {
        std::cout << c;
    }
    std::cout << std::endl;

    // Prompt user for input, based on append or write
    if (write) {
        std::string out = "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving";
        std::cout << out << std::endl;
    }
    else {
        std::string out = "Enter data you would like to append to the file. Enter :wq to save the file and exit, enter :q to exit without saving";
        std::cout << out << std::endl;
    }
    

    // Vars to keep track of state and text to append
    bool quit = false;
    bool save = false;
    std::vector<char> new_text;

    // Loop until user quits
    while (!quit) {

        // Get user input
        std::string in;
        std::getline(std::cin, in);

        // Check what should happen based on input
        if (in == ":q") { // User has quit, exit loop without saving
            quit = true;
        }
        else if (in == ":wq") { // User has quit and saved
            if (new_text.size() > 0) {
                new_text.pop_back(); // remove newline

            }
            quit = true; // record that user has requested to quit and save
            save = true;
        }
        else { // User has added more text
            for (char c : in) {
                new_text.push_back(c); // Add each char to the append vector
            }
            new_text.push_back('\n'); // Add newline character to show line end
        }
    }

    int result = SUCCESS;

    if (save) { // Update file if user choose to save
        if (write) { // Write file if user choose to write
            result = file->write(new_text);
        }
        else { // Append file if user choose to write
            result = file->append(new_text);
        }
    }
    

    // Close file before returning
    system->closeFile(file);
    return result;
}