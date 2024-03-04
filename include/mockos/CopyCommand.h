/**
 * CopyCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for CopyCommand class.
*/

#ifndef COPY_COMMAND_H
#define COPY_COMMAND_H

#include "AbstractCommand.h"

class CopyCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
public:
    CopyCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string args) override;
};

#endif //COPY_COMMAND_H