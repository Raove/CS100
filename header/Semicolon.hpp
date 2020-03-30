#ifndef RSHELL_SEMICOLON_HPP
#define RSHELL_SEMICOLON_HPP

#include "Paren.hpp"

class Semicolon : public Token {
public:
    Token* left = NULL;
    Token* right = NULL;
    Semicolon(){};
    string getToken(){return ";";}
    string getType(){return "CNT";}
    bool run(){
        if(this->left->getType() == "CNT")
            this->left->run();
        else {
            Executable *one = new Executable();
            one->makechar(this->left);
            one->exe();
            if(this->right->getType() == "CNT")
                this->right->run();
            else {
                Executable *two = new Executable();
                two->makechar(this->right);
                return two->exe();
            }
        }
    };
};

#endif //RSHELL_SEMICOLON_HPP
