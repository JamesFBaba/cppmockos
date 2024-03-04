/**
 * SizeCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for SizeCommand class.
*/

#include "mockos/SizeCommand.h"
#include "mockos/SizeVisitor.h"

#include <iostream>
#include <sstream>

SizeCommand::SizeCommand(AbstractFileSystem* sys) : system(sys) {}

void SizeCommand::displayInfo() {
    std::cout << "size returns information about system space usage. size can be invoked with the command: size" << std::endl;
}

int SizeCommand::execute(std::string fileName) {
    // Retrieve all file names
    std::set<std::string> names = system->getFileNames();
    std::set<std::string>::iterator it;
    int system_size = 0;
    SizeVisitor* v = new SizeVisitor; // Custom size visitor for size command

    // Iterate through files and use visitor to get statistics
    for (it = names.begin(); it != names.end(); ++it) {
        std::string s = *it; 
        AbstractFile* f = system->openFile(s);
        system_size += f->getSize();
        f->accept(v);
        system->closeFile(f);
    }

    // Print stats using vector returned from v->getStats()
    std::cout << "Number of text files: " << v->getStats()[NUM_TXT] << std::endl;
    std::cout << "Number of image files: " << v->getStats()[NUM_IMG] << std::endl;
    std::cout << "Total space required by text files: " << v->getStats()[SPACE_TXT] << std::endl;
    std::cout << "Total space required by image files: " << v->getStats()[SPACE_IMG] << std::endl;
    std::cout << "Largest text file: " << v->getStats()[LARGEST_TXT] << std::endl;
    std::cout << "Largest image file: " << v->getStats()[LARGEST_IMG] << std::endl;

    std::cout << "Total space required for system is: " << v->getStats()[SPACE_TXT] + v->getStats()[SPACE_IMG] << std::endl;

    delete v; // Prevent memory leak
    return SUCCESS;
}