/**
 * RemoveCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for RemoveCommand class.
*/

#include "mockos/RemoveCommand.h"
#include <iostream>

RemoveCommand::RemoveCommand(AbstractFileSystem* sys) : system(sys) {}

void RemoveCommand::displayInfo() {
    std::cout << "rm removes a file. remove can be invoked with the command: remove <filename>" << std::endl;
}

int RemoveCommand::execute(std::string fileName) {
    return system->deleteFile(fileName); // deletes the file from the system, returns outcome of system->deleteFile()
}