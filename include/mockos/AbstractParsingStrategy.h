/**
 * AbstractParsingStrategy.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for AbstractParsingStrategy class.
*/

#ifndef ABSTRACT_PARSING_STRATEGY_H
#define ABSTRACT_PARSING_STRATEGY_H

#include <string>
#include <vector>

class AbstractParsingStrategy {
public:
    virtual std::vector<std::string> parse(std::string str) = 0;
};

#endif //ABSTRACT_PARSING_STRATEGY_H
