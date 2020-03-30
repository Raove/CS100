//Parser source file
// Created by parke on 1/28/2020.
//
#include "Parser.hpp"
#include <string>
#include <iostream>

Parser::Parser(std::string string1) {
}
void Parser::parsed(std::string string1) {
    char command[string1.length()];
    while (true) {
        for (int i = 0; i != string1.length(); i++) {
            command[i] = string1[i];
        };
    };
}
