#ifndef RSHELL_SHUNTINGYARD_HPP
#define RSHELL_SHUNTINGYARD_HPP

#include "../header/Executable.hpp"
#include "Paren.hpp"
#include "../header/Command.hpp"
#include "../header/Argument.hpp"
#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"
#include "../header/And.hpp"
#include "../header/Token.hpp"

#include <stack>
#include <queue>

class ShuntingYard {
private:
    vector<Token*> ToVector;
    stack<Token*> operator_stack;
    queue<Token*> output_queue;
public:
    ShuntingYard(){};
    void ShuntingYardRun(vector<Token*> Tokens){
        //cout << "Shunting starts" << endl;

        try {
            for (int i = 0; i < distance(Tokens.begin(), Tokens.end()) && Tokens[i]->getToken() != "\0"; i++) {
                //cout << "TOKEN START " << endl;

                if (Tokens[i]->getType() == "CMD") {
                    Command* x = (Command*)Tokens[i];
                    if (Tokens[i + 1]->getType() == "ARG") {
                        x->setArg((Argument*)Tokens[i+1]);
                    }
                    output_queue.push((Token*)x);
                    //cout << "CMD IN |" << output_queue.back()->getToken() << "|" << endl;
                }
                //cout << Tokens[i]->getToken() << endl;
                if (Tokens[i]->getToken() == "(") {
                    operator_stack.push(Tokens[i]);
                }
                else if (Tokens[i]->getType() == "CNT" && Tokens[i]->getToken() != ")") {
                    while (!operator_stack.empty() && operator_stack.top()->getToken() != "(") {
                        output_queue.push(operator_stack.top());
                        operator_stack.pop();
                    }
                    //if(Tokens[i]->getToken() != "(")
                        operator_stack.push(Tokens[i]);
                    //cout << "CNT IN |" << output_queue.back()->getToken() << "|" << endl;
                }
                /*
                if (Tokens[i]->getToken() == "(") {
                    operator_stack.push(Tokens[i]);
                }
                 */
                if (Tokens[i]->getToken() == ")") {
                    //cout << "here 3" << endl;
                    while (operator_stack.top()->getToken() != "(") {
                        output_queue.push(operator_stack.top());
                        operator_stack.pop();
                    }
                    if (operator_stack.top()->getToken() == "(") {
                        operator_stack.pop();
                    }
                }
            }
            //cout << "here" << endl;
            if (!operator_stack.empty()) {
                while (!operator_stack.empty()) {
                    if (operator_stack.top()->getToken() != "(")
                        output_queue.push(operator_stack.top());
                    operator_stack.pop();
                }
            }
        }
        catch (exception e){}

        //cout << "Shunting Yard succeeds" << endl;

        /*
        for(int i = 0; i < Tokens.size(); i++){
            if(commands[i] != NULL){
                if(arguments[i] != NULL){
                    commands[i]->setArg(*arguments[i]);
                }
                output.push_back(commands[i]);
            }

            if(connectors[i] != NULL){
                if(connect.empty()){
                    connect.push(connectors[i]);
                }
                else{
                    output.push_back(connect.top());
                    connect.pop();
                    connect.push(connectors[i]);
                }
            }
        }
        */

        while(!output_queue.empty()){
            ToVector.push_back(output_queue.front());
            output_queue.pop();
        }
        /*
        vector<Token*> temp;
        for(int i = ToVector.size(); i > 0; i--){
            temp.push_back(ToVector[i - 1]);
        }
        ToVector = temp;
        */
        /*
        for (int i = 0; i < ToVector.size(); ++i) {
            cout << ToVector[i]->getToken();
            if(ToVector[i]->getType() == "CMD"){
                Command* x = (Command*)ToVector[i];
                Argument* y = x->getArg();
                cout << "[" << y->getToken() << "]";
            }
            cout << "•";
        }
        cout << endl;
        */

        bool state = true;

        /*
        for(int i = 0; i < mirrored.size(); i++){
            if(state){
                if(mirrored[i]->getToken() == ";"){
                    Semicolon* semi = new Semicolon((Command*)mirrored[i+2],
                            (Argument*)mirrored[i+1], (Command*)mirrored[i+4],
                            (Argument*)mirrored[i+3], state);
                    state = semi->run();
                }
            }
        }
         */
        /*
        if(ToVector.size() > 2){
            bool ran = false;
            for(int i = 2; i < ToVector.size(); i++){
                if (ToVector[i]->getToken() == ";") {
                    Semicolon *semi = new Semicolon(ToVector[i-4], ToVector[i-3],
                            ToVector[i-2], ToVector[i-1], ran, ToVector);
                    ran = semi->run();
                } else if (ToVector[i]->getToken() == "&&") {
                    And *a = new And(ToVector[i-4], ToVector[i-3],
                                     ToVector[i-2], ToVector[i-1], ran, ToVector);
                    ran = a->run();
                } else if (ToVector[i]->getToken() == "||") {
                    Or *o = new Or(ToVector[i-4], ToVector[i-3],
                                   ToVector[i-2], ToVector[i-1], ran, ToVector);
                    ran = o->run();
                }
            }
        }
        else {
            Semicolon *semi = new Semicolon(ToVector[0], ToVector[1], true, ToVector);
            semi->singlerun();
        }
        */
        /*
        {
            for (int i = 0; i < connectors.size(); ++i) {
                if (connectors[i]->getToken() == " ;") {
                    Semicolon *semi = new Semicolon(commands[i], commands[i + 1], arguments[i], arguments[i + 1]);
                    //semi->run();
                } else if (connectors[i]->getToken() == "&&") {
                    And *a = new And(commands[i], commands[i + 1], arguments[i], arguments[i + 1]);
                    //a->run();
                } else if (connectors[i]->getToken() == "||") {
                    Or *o = new Or(commands[i], commands[i + 1], arguments[i], arguments[i + 1]);
                    //o->run();
                }
                break;
            }
        }
         */
        //Executable* x = new Executable();
        //x->exe();
        return;
    };
    vector<Token*> Yarded(){
        return ToVector;
    };
};

#endif //RSHELL_SHUNTINGYARD_HPP
