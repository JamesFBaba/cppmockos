/**
 * ImageFile.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for ImageFile class.
*/

#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H


#include "AbstractFile.h"

class ImageFile : public AbstractFile {
private:
    std::vector<char> fileContents_;
    std::string name_;
    char size_;
public:
    ImageFile(std::string name);
    std::vector<char> read();
    int write(std::vector<char> v);
    int append(std::vector<char> v);
    unsigned int getSize();
    std::string getName();

    void accept(AbstractFileVisitor* visitor);
    AbstractFile* clone(std::string newName);

};

#endif //IMAGE_FILE_H


