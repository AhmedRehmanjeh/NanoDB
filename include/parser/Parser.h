#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <iostream>
#include "storage/CustomVector.h"
#include "stack/CustomStack.h"
#include "logger/Logger.h"

class Parser {
public:
    static int precedence(const std::string& op);
    static CustomVector<std::string> infixToPostfix(const std::string& infix);
};

#endif
