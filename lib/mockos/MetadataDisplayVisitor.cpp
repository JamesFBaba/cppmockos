/**
 * MetadataDisplayVisitor.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for MetadataDisplayVisitor class.
*/

#include"mockos/MetadataDisplayVisitor.h"
#include"mockos/ImageFile.h"
#include"mockos/TextFile.h"

#include <iostream>
#include <iomanip>

const int name_width = 20;
const int type_width = 6;
const int size_width = 3;

void MetadataDisplayVisitor::visit_txt(TextFile* txt) {
    std::string name = txt->getName();
    int size = txt->getSize();
    std::string type = "text";

    std::cout << std::left << std::setw(name_width) << name;
    std::cout << std::left << std::setw(type_width) << type;
    std::cout << std::left << std::setw(size_width) << size;
    std::cout << std::endl;
}

void MetadataDisplayVisitor::visit_img(ImageFile* img) {
    std::string name = img->getName();
    int size = img->getSize();
    std::string type = "image";

    std::cout << std::left << std::setw(name_width) << name;
    std::cout << std::left << std::setw(type_width) << type;
    std::cout << std::left << std::setw(size_width) << size;
    std::cout << std::endl;
}

