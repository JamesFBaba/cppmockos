/**
 * SimpleFileFactory.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for SimpleFileFactory class.
*/

#ifndef SIMPLE_FILE_FACTORY_H
#define SIMPLE_FILE_FACTORY_H

#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
    AbstractFile* createFile(std::string fileName);
private:
};

#endif //SIMPLE_FILE_FACTORY_H