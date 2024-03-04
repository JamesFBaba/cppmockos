/**
 * RemoveCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for RemoveCommand class.
*/

#ifndef REMOVE_COMMAND_H
#define REMOVE_COMMAND_H

#include "AbstractCommand.h"

class RemoveCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
public:
    RemoveCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string fileName) override;
};

#endif //REMOVE_COMMAND_H