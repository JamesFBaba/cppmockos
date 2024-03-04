/**
 * TouchCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for TouchCommand class.
*/

#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>

TouchCommand::TouchCommand(AbstractFileSystem * sys, AbstractFileFactory * fac) : system(sys), factory(fac) {}

void TouchCommand::displayInfo() {
    std::cout << "touch creates a file. touch can be invoked with the command: touch <filename> [-p]" << std::endl;
}

int TouchCommand::execute(std::string fileName) {
    std::istringstream iss(fileName);
    std::string file_name;
    std::string arg;
    iss >> file_name;
    if (iss >> arg) {
        if (arg == "-p") {
            // Get password from user
            std::string pass;
            std::cout << "What is the password?" << std::endl;
            std::getline(std::cin, pass);

            // Create file and proxy
            AbstractFile* file = factory->createFile(file_name);
            if (file == nullptr) {
                return FAILED_TO_CREATE_FILE;
            }
            PasswordProxy* proxy_file = new PasswordProxy(file, pass);

            // Add proxy to file system
            int result = system->addFile(file_name, proxy_file);
            if (result == SUCCESS) {
                return result;
            }
            else {
                delete proxy_file; // Avoid memory leak
                return FAILED_TO_ADD_FILE;
            }
;        }
        else {
            return INVALID_CMD_OPTION;
        }
    }
    else {
        AbstractFile* file = factory->createFile(file_name);
        if (file == nullptr) {
            return FAILED_TO_CREATE_FILE;
        }
        int result = system->addFile(file_name, file);
        if (result == SUCCESS) {
            return result;
        }
        else {
            delete file; // Prevent memory leak
            return FAILED_TO_ADD_FILE;
        }
    }

}