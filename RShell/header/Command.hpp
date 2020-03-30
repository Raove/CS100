#ifndef RSHELL_COMMAND_HPP
#define RSHELL_COMMAND_HPP

#include "Token.hpp"
#include "Argument.hpp"

class Command : public Token {
private:
    string cmd;
    Argument* arg;
public:
    Command(){};
    Command(string s){
        cmd = s;
    };
    void setArg(Argument* argument){
        arg = argument;
    };
    Argument* getArg(){
        return arg;
    }
    string getToken(){return cmd;}
    string getType(){return "CMD";}
    bool run(){};
};

#endif //RSHELL_COMMAND_HPP
