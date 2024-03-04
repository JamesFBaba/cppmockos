/**
 * CommandPrompt.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for CommandPrompt class.
*/

#include "mockos/CommandPrompt.h"

CommandPrompt::CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr){}

void CommandPrompt::setFileSystem(AbstractFileSystem* system) { // system setter
    fileSystem = system;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* factory) { // factory setter
    fileFactory = factory;
}

int CommandPrompt::addCommand(std::string str, AbstractCommand *cmd) { // Adds commands
    if (commands.emplace(str, cmd).second) { // Attempts to add command
        return SUCCESS;
    } else {
        return FAILED_TO_INSERT_CMD;
    }
}

void CommandPrompt::listCommands() { // Lists commands
    for (const auto& pair : commands) {
        std::cout << pair.first << std::endl;
    }
}

std::string CommandPrompt::prompt() { // Prompts user for command
    std::string userInput;
    std::cout << "Enter a command, q to quit, help for a list of commands, or " << std::endl;
    std::cout << "help followed by a command name for more information about " << std::endl;
    std::cout << "that command." << std::endl;
    std::cout << "$  ";
    std::getline(std::cin, userInput);
    return userInput;
}

int CommandPrompt::run() {
    while(1) {
        std::string input = prompt();
        if (input == "q") { // User quit
            return QUIT;
        } else if (input == "help") {
            listCommands();
        } else {
            size_t spaceFound = input.find(' ');
            if (spaceFound == std::string::npos) { // One-word command
                auto cmdSearch = commands.find(input); // Search map for command
                if (cmdSearch == commands.end()) { // Invalid Command
                    std::cout << "Invalid command: " << input << std::endl;
                } else {
                    AbstractCommand* cmd = cmdSearch->second; // Gets value associated with key
                    int cmdResult = cmd->execute("");
                    if (cmdResult != SUCCESS) { // Command failed
                        std::cout << "Command failed to execute: " << cmdResult << std::endl;
                    }
                }
            } else { // Multi-word command
                std::istringstream iss(input);
                std::string first, second;
                iss >> first;
                if (first == "help") { // command help
                    iss >> second;
                    auto cmdSearch = commands.find(second); // Search map for command
                    if (cmdSearch == commands.end()) { // Invalid Command
                        std::cout << "Invalid command: " << second << std::endl;
                    } else {
                        AbstractCommand* cmd = cmdSearch->second; // Gets value associated with key
                        cmd->displayInfo();
                    }
                } else { // First word is command
                    auto cmdSearch = commands.find(first); // Search map for command
                    if (cmdSearch == commands.end()) { // Invalid Command
                        std::cout << "Invalid command: " << first << std::endl;
                    } else {
                        std::string param;
                        std::getline(iss >> std::ws, param); // Gets rest of line, removes whitespace at beginning
                        AbstractCommand* cmd = cmdSearch->second; // Gets value associated with key
                        int cmdResult = cmd->execute(param);
                        if (cmdResult != SUCCESS) { // Command failed
                            std::cout << "Command failed to execute: " << cmdResult << std::endl;
                        }
                    }
                }
            }
        }
    }
}


