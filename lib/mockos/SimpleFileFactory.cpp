/**
 * SimpleFileFactory.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for SimpleFileFactory class.
*/

#include "mockos/SimpleFileFactory.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"

AbstractFile* SimpleFileFactory::createFile(std::string fileName) {

    // Find index of beginning of file extension
    int pos = fileName.rfind('.');
    if (pos != std::string::npos) { // Make sure index was found
        std::string extension = fileName.substr(pos); // parse extension 
        
        // Create file based on extension
        if (extension == ".img") {
            ImageFile* img = new ImageFile(fileName);
            return img;
        }
        if (extension == ".txt") {
            TextFile* txt = new TextFile(fileName);
            return txt;
        }
    }
    return nullptr;
}