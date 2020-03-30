#ifndef RSHELL_AND_HPP
#define RSHELL_AND_HPP

#include "Paren.hpp"

class And : public Token {
public:
    Token* left = NULL;
    Token* right = NULL;
    And(){};
    string getToken(){return "&&";}
    string getType(){return "CNT";}
    bool run(){
        if(this->left->getType() == "CNT")
            this->left->run();
        else {
            Executable *one = new Executable();
            one->makechar(this->left);
            bool succeeded = one->exe();
            if(this->right->getType() == "CNT")
                this->right->run();
            else {
                if (!succeeded) {
                    Executable *two = new Executable();
                    two->makechar(this->right);
                    return two->exe();
                }
            }
            return true;
        }
    };
};

#endif //RSHELL_AND_HPP
