/**
 * BasicDisplayVisitor.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for BasicDisplayVisitor class.
*/

#include"mockos/BasicDisplayVisitor.h"
#include"mockos/ImageFile.h"
#include"mockos/TextFile.h"
#include <iostream>

// Visitor for displaying .txt files
void BasicDisplayVisitor::visit_txt(TextFile* txt) {
    // Read in raw data from file
    std::vector<char> fileContents = txt->read();

    // iterate through data and print every char out
    for (int i = 0; i < fileContents.size(); ++i) {
        std::cout << fileContents[i];
    }

    // Add an extra line at the end
    std::cout << std::endl;
}

// Visitor for displaying .img files
void BasicDisplayVisitor::visit_img(ImageFile* img) {

    // use getSize() to determine width/height of image
    int size = img->getSize();
    size = std::sqrt(size);
    
    // Read in raw data from file
    std::vector<char> fileContents = img->read();

    // Iterate through the image grid
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            // Calculate the index the "current" pixel is stored at and print it
            int pos = size * j + i;
            std::cout << fileContents[pos];
        }
        // Print line so next row is separate
        std::cout << std::endl;
    }
}
