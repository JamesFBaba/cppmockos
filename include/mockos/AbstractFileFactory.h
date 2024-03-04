/**
 * AbstractFileFactory.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for AbstractFileFactory abstract class.
*/

#ifndef ASTRACT_FILE_FACTORY_H
#define ASTRACT_FILE_FACTORY_H


#include "AbstractFile.h"
class AbstractFileFactory {
public:
    virtual AbstractFile* createFile(std::string fileName) = 0;
};

#endif //ASTRACT_FILE_FACTORY_H
