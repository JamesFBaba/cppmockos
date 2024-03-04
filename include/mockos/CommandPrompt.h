/**
 * CommandPrompt.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for CommandPrompt class.
*/

#ifndef COMMAND_PROMPT_H
#define COMMAND_PROMPT_H

#include <map>
#include <iostream>
#include <sstream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CommandPrompt {
private:
    std::map<std::string, AbstractCommand*> commands;
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem* system);
    void setFileFactory(AbstractFileFactory* factory);
    int addCommand(std::string str, AbstractCommand* cmd);
    int run();
protected:
    void listCommands();
    std::string prompt();
};

#endif //COMMAND_PROMPT_H