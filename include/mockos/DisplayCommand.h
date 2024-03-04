/**
 * DisplayCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for DisplayCommand class.
*/

#ifndef DISPLAY_COMMAND_H
#define DISPLAY_COMMAND_H

#include "AbstractCommand.h"

class DisplayCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
public:
    DisplayCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string fileName) override;
};

#endif //DISPLAY_COMMAND_H