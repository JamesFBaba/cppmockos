/**
 * AbstractFile.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for AbstractFile abstract class.
*/

#ifndef ABSTRACT_FILE_H
#define ABSTRACT_FILE_H
#include "mockos/AbstractFileVisitor.h"
#include "mockos/Constants.h"

#include <vector>
#include <string>

class AbstractFile {
public:
    virtual std::vector<char> read() = 0;
    virtual int write(std::vector<char> v) = 0;
    virtual int append(std::vector<char> v) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual ~AbstractFile() = default;

    virtual void accept(AbstractFileVisitor* visitor) = 0;
    virtual AbstractFile* clone(std::string newName) = 0;
};

#endif //ABSTRACT_FILE_H
