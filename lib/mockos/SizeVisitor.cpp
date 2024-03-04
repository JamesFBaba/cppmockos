/**
 * SizeVisitor.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for SizeVisitor class.
*/

#include"mockos/SizeVisitor.h"
#include"mockos/ImageFile.h"
#include"mockos/TextFile.h"
#include <iostream>

SizeVisitor::SizeVisitor() : num_txt(0), num_img(0), space_txt(0), space_img(0), largest_txt(0), largest_img(0){}

void SizeVisitor::visit_txt(TextFile* txt) {
    int size = txt->getSize();
    num_txt += 1;
    space_txt += size;
    if (largest_txt < size) {
        largest_txt = size;
    }
}

void SizeVisitor::visit_img(ImageFile* img) {
    int size = img->getSize();
    num_img += 1;
    space_img += size;
    if (largest_img < size) {
        largest_img = size;
    }
}

std::vector<int> SizeVisitor::getStats() {
    return {num_txt, num_img, space_txt, space_img, largest_txt, largest_img};
}