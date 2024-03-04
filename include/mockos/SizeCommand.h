/**
 * SizeCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for SizeCommand class.
*/

#ifndef SIZE_COMMAND_H
#define SIZE_COMMAND_H

#include "AbstractCommand.h"

class SizeCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
public:
    SizeCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string fileName) override;
};

#endif //SIZE_COMMAND_H