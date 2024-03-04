/**
 * CatDSParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function definitions for CatDSParsingStrategy class.
*/

#include "mockos/CatDSParsingStrategy.h"

std::vector<std::string> CatDSParsingStrategy::parse(std::string args) {
    // Extract file name from input
    std::istringstream iss(args);
    std::string file_name;
    std::string first_arg, second_arg, third_arg;
    std::vector<std::string> parse_vec;
    if (iss >> file_name) {
        std::string cat_command = file_name, ds_command = file_name;
        iss >> first_arg;
        iss >> second_arg;
        iss >> third_arg;
        if (!third_arg.empty()) { // Checks for incorrect args
            return parse_vec;
        }
        if (first_arg == "-a" || second_arg == "-a") { // Checks for -a arg
            cat_command = cat_command + " -a";
        }
        if (first_arg == "-d" || second_arg == "-d") { // Checks for -d arg
            ds_command = ds_command + " -d";
        }
        if (!first_arg.empty() && first_arg != "-a" && first_arg != "-d") { // Checks for incorrect args
            return parse_vec;
        }
        if (!second_arg.empty() && second_arg != "-a" && second_arg != "-d") { // Checks for incorrect args
            return parse_vec;
        }
        // Adds commands to vector
        parse_vec.push_back(cat_command);
        parse_vec.push_back(ds_command);
    }
    return parse_vec;
}