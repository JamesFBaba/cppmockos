/**
 * CatDSParsingStrategy.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for CatDSParsingStrategy class.
*/

#ifndef CAT_DS_PARSING_STRATEGY_H
#define CAT_DS_PARSING_STRATEGY_H

#include "AbstractParsingStrategy.h"
#include <sstream>

class CatDSParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string args) override;
};

#endif //CAT_DS_PARSING_STRATEGY_H
