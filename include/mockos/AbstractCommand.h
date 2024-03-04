/**
 * AbstractCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for AbstractCommand abstract class.
*/

#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
};

#endif //ABSTRACT_COMMAND_H