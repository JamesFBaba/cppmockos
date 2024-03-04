/**
 * MacroCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for MacroCommand class.
*/

#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractParsingStrategy.h"
#include <iostream>

class MacroCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* parsingStrat;
public:
    MacroCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string fileName) override;
    int addCommand(AbstractCommand * cmd);
    int setParseStrategy(AbstractParsingStrategy* strat);
};



#endif //MACRO_COMMAND_H
