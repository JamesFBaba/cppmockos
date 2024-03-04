/**
 * DisplayCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for DisplayCommand class.
*/

#include "mockos/DisplayCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"

#include <iostream>
#include <sstream>

DisplayCommand::DisplayCommand(AbstractFileSystem* sys) : system(sys) {}

void DisplayCommand::displayInfo() {
    std::cout << "ds displays a file. ds can be invoked with the command: cat <filename> [-d]" << std::endl;
}


int DisplayCommand::execute(std::string args) {
    // Extract file name from input
    std::istringstream iss(args);
    std::string file_name;
    std::string arg;
    iss >> file_name;

    // Open file
    AbstractFile* file = system->openFile(file_name);
    if (file == nullptr) {
        return FILE_DOES_NOT_EXIST;
    }


    // Check if additional arguments were provided
    if (iss >> arg) {
        if (arg != "-d") { // ds only accepts -d
            return INVALID_CMD_OPTION;
        }
        else { // -d has been provided. Print unformatted
            std::vector<char> contents = file->read();
            for (char c : contents) {
                std::cout << c;
            }
            std::cout << std::endl;
        }
    }
    else { // print formatted using display visitor
        BasicDisplayVisitor visitor;
        file->accept(&visitor);
    }

    // Close file before returning
    system->closeFile(file);
    return SUCCESS;
}