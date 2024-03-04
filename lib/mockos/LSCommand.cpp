/**
 * LSCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for LSCommand class.
*/

#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
#include <mockos/SimpleFileSystem.h>

#include <iostream>
#include <iomanip>

LSCommand::LSCommand(AbstractFileSystem* sys) : system(sys) {}

void LSCommand::displayInfo() {
    std::cout << "ls outputs the names of all files currently in the file system. ls can be invoked with the command: ls [-m]" << std::endl;
}

int LSCommand::execute(std::string option = "") {
    // Retrieve all file names
    std::set<std::string> names = system->getFileNames();
    if (option == "") { // No additional options provided
        // Set the max width per name (given in doc) 
        const int width = 20;

        // Print out the set, two items per line
        std::set<std::string>::iterator it;
        int i = 1;
        for (it = names.begin(); it != names.end(); ++it) {
            std::string s = *it; // Current string to print
            std::cout << std::left << std::setw(width) << s ; // Print string with spacing after it, left aligned

            if (i % 2 == 0) {
                std::cout << std::endl; // Every other printed value add new line
            } 
            ++i;
        }
        std::cout << std::endl; // Make sure next command has a new line

        
        return SUCCESS;
    }
    else if (option == "-m") {
        // Set the max width per name (given in doc) 
        
        std::set<std::string>::iterator it;
        for (it = names.begin(); it != names.end(); ++it) {
            std::string s = *it; // Current string to print
            AbstractFile* f = system->openFile(s);
            MetadataDisplayVisitor m;
            f->accept(&m);
            system->closeFile(f);
        }
        return SUCCESS;
    }
    else {
        return INVALID_CMD_OPTION;
    }

}