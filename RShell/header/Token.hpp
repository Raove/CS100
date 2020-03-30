#ifndef RSHELL_TOKEN_HPP
#define RSHELL_TOKEN_HPP

#include <string>

using namespace std;

class Token {
public:
    Token* left = NULL;
    Token* right = NULL;
    Token(){};

    virtual string getToken() = 0;
    virtual string getType() = 0;
    virtual bool run() = 0;
};

#endif //RSHELL_TOKEN_HPP
