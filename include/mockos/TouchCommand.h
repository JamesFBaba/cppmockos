/**
 * TouchCommand.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for TouchCommand class.
*/

#ifndef TOUCH_COMMAND_H
#define TOUCH_COMMAND_H

#include "AbstractCommand.h"

class TouchCommand : public AbstractCommand {
private:
    AbstractFileSystem * system;
    AbstractFileFactory * factory;
public:
  TouchCommand(AbstractFileSystem* sys, AbstractFileFactory* fac);
  void displayInfo() override;
  int execute(std::string fileName) override;
};

#endif //TOUCH_COMMAND_H