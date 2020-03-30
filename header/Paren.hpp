#ifndef RSHELL_PAREN_HPP
#define RSHELL_PAREN_HPP

#include "../header/Token.hpp"
class Paren : public Token{
protected:
    string x;
public:
    Paren(){};
    Paren(string s){x = s;};
    string getType(){return "CNT";}
    string getToken(){return x;};
    bool run(){};
};
#endif //RSHELL_PAREN_HPP
