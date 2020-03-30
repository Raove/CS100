#ifndef RSHELL_ARGUMENT_HPP
#define RSHELL_ARGUMENT_HPP

#include "../header/Token.hpp"

class Argument : public Token {
protected:
    string x;
public:
    Argument(){};
    Argument(string s){
        x = s;
    };
    void setToken(string s){x = s;};
    string getToken(){ return x;};
    string getType(){return "ARG";};
    bool run(){};
};

#endif //RSHELL_ARGUMENT_HPP
