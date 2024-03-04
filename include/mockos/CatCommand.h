/**
 * CatCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for CatCommand class.
*/

#ifndef CAT_COMMAND_H
#define CAT_COMMAND_H

#include "AbstractCommand.h"

class CatCommand : public AbstractCommand {
private:
    AbstractFileSystem* system;
public:
    CatCommand(AbstractFileSystem* sys);
    void displayInfo() override;
    int execute(std::string fileName) override;
};

#endif //CAT_COMMAND_H