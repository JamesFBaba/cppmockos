/**
 * TextFile.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for TextFile class.
*/

#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class TextFile : public AbstractFile {
private:
    std::vector<char> fileContents_;
    std::string name_;

public:
    TextFile(std::string name);
    std::vector<char> read();
    int write(std::vector<char> v);
    int append(std::vector<char> v);
    unsigned int getSize();
    std::string getName();

    void accept(AbstractFileVisitor* visitor);
    AbstractFile* clone(std::string newName);

};

#endif //TEXT_FILE_H

