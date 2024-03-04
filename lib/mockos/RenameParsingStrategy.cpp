/**
 * RenameParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for RenameParsingStrategy class.
*/

#include "mockos/RenameParsingStrategy.h"

std::vector<std::string> RenameParsingStrategy::parse(std::string str) {
    std::istringstream iss(str);
    std::string existing_file;
    std::string new_name;
    std::vector<std::string> parse_vec;
    if (iss >> existing_file) { // Extracts first arg
        if (iss >> new_name) { // Extracts second arg
            parse_vec.push_back(existing_file + " " + new_name); // Adds <existing_file> <new_name>
            parse_vec.push_back(existing_file); // Adds <existing_file>
        }
    }
    return parse_vec;
}