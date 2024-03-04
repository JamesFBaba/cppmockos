/**
 * CopyCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for CopyCommand class.
*/

#include "mockos/CopyCommand.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>

CopyCommand::CopyCommand(AbstractFileSystem* sys) : system(sys) {}

void CopyCommand::displayInfo() {
    std::cout << "cp copies a file that exists in the file system and add the copy to the file system with a different name. copy can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << std::endl;
}

int CopyCommand::execute(std::string args) {
    // Extract file name from input
    std::istringstream iss(args);
    std::string file_name;
    std::string new_file_name;
    iss >> file_name;

    if (iss >> new_file_name) { // checks if user inputted new file name
        AbstractFile* file = system->openFile(file_name);
        if (file == nullptr) {
            system->closeFile(file);
            return FILE_DOES_NOT_EXIST;
        }
        AbstractFile* new_file = file->clone(new_file_name); // clones file

        if (new_file) { // checks if file was created
            // Add file to file system
            int result = system->addFile(new_file->getName(), new_file);
            if (result == SUCCESS) {
                system->closeFile(file);
                return result;
            }
            else { // Could not add file
                delete new_file;
                system->closeFile(file);
                return FAILED_TO_ADD_FILE;
            }
        } else { // Could not create file
            system->closeFile(file);
            return FAILED_TO_CREATE_FILE;
        }
    } else { // No file name added
        return INVALID_CMD_ARGS;
    }
}