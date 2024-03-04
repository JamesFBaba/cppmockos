/**
 * RenameParsingStrategy.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for RenameParsingStrategy class.
*/

#ifndef RENAME_PARSING_STRATEGY_H
#define RENAME_PARSING_STRATEGY_H

#include "mockos/AbstractParsingStrategy.h"
#include <sstream>

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string str) override;
};

#endif //RENAME_PARSING_STRATEGY_H