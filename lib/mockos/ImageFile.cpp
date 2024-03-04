/**
 * ImageFile.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for ImageFile class.
*/

#include "mockos/ImageFile.h"

ImageFile::ImageFile(std::string name) : AbstractFile(), name_(name), size_(0) {}

std::vector<char> ImageFile::read() { // Reads contents
    std::vector<char> elements = fileContents_;
    if (elements.size() > 0) {
        elements.pop_back();
    }
    return elements;
}

int ImageFile::write(std::vector<char> v) { // Write to image file
    if (v.empty()) {
        return SUCCESS;
    }
    char n_char = v[v.size()-1];
    int n = n_char-'0';

    if (n*n != v.size()-1) { // Checks for valid dimensions
        return INVALID_IMAGE_DIM;
    }

    for (int i = 0; i < v.size()-1; ++i) { // Checks for valid image contents
        if (v[i] != 'X' && v[i] != ' ') {
            return INVALID_IMAGE_CONTENTS;
        }
    }

    fileContents_ = v;
    size_ = n;
    return SUCCESS;
}

int ImageFile::append(std::vector<char> v) { // Append (not supported for images)
    return APPEND_NOT_SUPPORTED_FOR_FILETYPE;
}

unsigned int ImageFile::getSize() { // Gets size of image
    int size = size_*size_;
    return size;
}

std::string ImageFile::getName() { // Gets name of image
    return name_;
}


void ImageFile::accept(AbstractFileVisitor* visitor) { // Visitor accept
    visitor->visit_img(this);
}

AbstractFile *ImageFile::clone(std::string newName) { // Prototype pattern to clone
    std::string new_name_with_extension = newName + ".img"; // adds file extension to new name
    ImageFile* newFile = new ImageFile(new_name_with_extension);
    int result = newFile->write(this->fileContents_);
    if (result == SUCCESS) { // File successfully written to
        return newFile;
    }
    delete newFile; // Deletes file if failed to write to it
    return nullptr;
}
