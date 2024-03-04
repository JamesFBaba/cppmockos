/**
 * SimpleFileSystem.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for SimpleFileSystem class.
*/

#include "mockos/SimpleFileSystem.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"

// Add a file to the file system
int SimpleFileSystem::addFile(std::string fileName, AbstractFile * file) {
    if (files_.count(fileName)) { // Verify file does not already exist in file system
        return FILE_ALREADY_EXISTS;
    }
    if (file == nullptr) { // Verify file exists
        return NULL_POINTER;
    }
    files_.insert({fileName, file}); // Add file
    return SUCCESS;
}

// Delete a file from the file system
int SimpleFileSystem::deleteFile(std::string fileName) {
    if (files_.count(fileName)) { // Verify file is in the file system
        AbstractFile* file = files_[fileName]; // Retrieve the file and make sure it's not open
        if (openFiles_.find(file) != openFiles_.end()) {
            return CANNOT_DELETE_OPEN_FILE;
        }
        files_.erase(fileName); 
        delete file;
        return SUCCESS;
    }
    return FILE_DOES_NOT_EXIST;
}

// Open a file from the file system
AbstractFile* SimpleFileSystem::openFile(std::string fileName) {
    if (files_.count(fileName)) { // Verify the fie is in the file system
        AbstractFile* file = files_[fileName]; // Find file, verify it's not open, and insert it. 
        if (openFiles_.find(file) == openFiles_.end()) {
            openFiles_.insert(file);
            return file;
        }
    }
    return nullptr;
}

// Close file from the filesystem
int SimpleFileSystem::closeFile(AbstractFile* file) {
    if (openFiles_.find(file) == openFiles_.end()) { // Verify file isn't closed
        return FILE_NOT_OPEN;
    } else {
        openFiles_.erase(file); // Close file
        return SUCCESS;
    }
}

// Return all file names from file system
std::set<std::string> SimpleFileSystem::getFileNames() {
    // Create a set and iterate through files_, adding each file to set
    std::set<std::string> file_set;
    for (auto i = files_.begin(); i != files_.end(); ++i) {
        file_set.insert(i->first);
    }
    return file_set;
}

// Deletes each file to prevent memory leak
SimpleFileSystem::~SimpleFileSystem() {
    std::map<std::string, AbstractFile*>::iterator it;
    for (it = files_.begin(); it != files_.end(); ++it) {
        delete it->second;
    }
}
