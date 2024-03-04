/**
 * LSCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for LSCommand class.
*/

#ifndef LS_COMMAND_H
#define LS_COMMAND_H

#include "AbstractCommand.h"

class LSCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
public:
    LSCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string fileName) override;
};

#endif //LS_COMMAND_H