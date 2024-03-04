/**
 * SimpleFileSystem.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for SimpleFileSystem class.
*/

#ifndef SIMPLE_FILE_SYSTEM_H
#define SIMPLE_FILE_SYSTEM_H

#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
public:
    int addFile(std::string fileName, AbstractFile * file);
    int deleteFile(std::string fileName);
    AbstractFile* openFile(std::string fileName);
    int closeFile(AbstractFile* file);
    std::set<std::string> getFileNames();
    ~SimpleFileSystem();
private:
    std::map<std::string, AbstractFile*> files_;
    std::set<AbstractFile*> openFiles_;
};

#endif //SIMPLE_FILE_SYSTEM_H