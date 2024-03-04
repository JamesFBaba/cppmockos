/**
 * MacroCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for MacroCommand class.
*/

#include "mockos/MacroCommand.h"
#include "mockos/AbstractFileSystem.h"


MacroCommand::MacroCommand(AbstractFileSystem* sys) : system(sys) {}

void MacroCommand::displayInfo() {
    std::cout << "macro command. rename file invoked with: `rn <file_name> <new_name>`. Cat + ds file invoked with: `catds <file_name> [-a] [-d]`." << std::endl;
}

int MacroCommand::execute(std::string fileName) {
    std::vector<std::string> parsed_cmds = parsingStrat->parse(fileName); // Gets parsed string vector
    if (parsed_cmds.empty()) { // If empty, incorrect command
        return INVALID_CMD_ARGS;
    }
    for (int i = 0; i < parsed_cmds.size() && i < commands.size(); ++i) { // Executes commands with corresponding input
        int result = commands[i]->execute(parsed_cmds[i]);
        if (result != SUCCESS) {
            return result;
        }
    }
    return SUCCESS;
}

int MacroCommand::addCommand(AbstractCommand * cmd) { // Adds commands to commands vector
    commands.push_back(cmd);
    if (commands[commands.size()-1] == cmd) {
        return SUCCESS;
    } else {
        return FAILED_TO_INSERT_CMD;
    }
}

int MacroCommand::setParseStrategy(AbstractParsingStrategy *strat) { // parsingStrat setter
    parsingStrat = strat;
    return SUCCESS;
}

