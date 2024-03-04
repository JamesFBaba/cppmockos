/**
 * TextFile.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for TextFile class.
*/


#include "mockos/TextFile.h"

TextFile::TextFile(std::string name) : AbstractFile(), name_(name) {}

std::vector<char> TextFile::read() {
    return fileContents_;
}
int TextFile::write(std::vector<char> v) {
    fileContents_ = v;
    return SUCCESS;
}
int TextFile::append(std::vector<char> v) {
    fileContents_.insert(fileContents_.end(), v.begin(), v.end());
    return SUCCESS;
}
unsigned int TextFile::getSize() {
    int size = fileContents_.size();
    return size;
}
std::string TextFile::getName() {
    return name_;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_txt(this);
}

AbstractFile *TextFile::clone(std::string newName) { // Prototype pattern to clone
    std::string new_name_with_extension = newName + ".txt"; // adds file extension to new name
    TextFile* newFile = new TextFile(new_name_with_extension);
    int result = newFile->write(this->fileContents_); // Attempts to copy contents of new file
    if (result == SUCCESS) {
        return newFile;
    }
    delete newFile; // Prevent memory leak
    return nullptr;
}