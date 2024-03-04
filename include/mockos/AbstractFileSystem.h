/**
 * AbstractFileSystem.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for AbstractFileSystem class.
*/

#ifndef ASTRACT_FILE_SYSTEM_H
#define ASTRACT_FILE_SYSTEM_H


#include "AbstractFile.h"
#include <set>
class AbstractFileSystem {
public:
    virtual int addFile(std::string fileName, AbstractFile * file) = 0;
    virtual int deleteFile(std::string fileName) = 0;
    virtual AbstractFile* openFile(std::string fileName) = 0;
    virtual int closeFile(AbstractFile* file) = 0;
    virtual std::set<std::string> getFileNames() = 0;
};

#endif //ASTRACT_FILE_SYSTEM_H
