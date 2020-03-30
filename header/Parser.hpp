#ifndef RSHELL_PARSER_H
#define RSHELL_PARSER_H

#include <iostream>
#include <string>
#include <vector>

#include "../header/Executable.hpp"
#include "Paren.hpp"
#include "../header/Token.hpp"
#include "../header/Command.hpp"
#include "../header/Argument.hpp"
#include "../header/Token.hpp"
#include "../header/Tokenizer.hpp"
#include "../header/ShuntingYard.hpp"
#include "../header/Semicolon.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Tree.hpp"


using namespace std;

class Parser {
public:
    vector<string> commands;
    Parser(){};
    Parser(string string_input){
        /*
        if(string_input.at(string_input.size() - 1) == ';' && string_input.at(string_input.size() - 2) != ' '){
            string_input.replace(string_input.size() - 1,1,";");
        }
        else
            string_input.append(";");
            */
        //cout << string_input << endl;
        string command = "";
        string comment = "";
        int count = 0;
        for(int i = 0; i < string_input.size(); i++){
            if(string_input.at(i) != '\n') {
                count++;
                if(string_input.at(i) == '\"'){
                    do{
                        command += string_input.at(i);
                        i++;
                    }while(string_input.at(i) != '\"');
                }
                else if(string_input.at(i) == '['){
                    do{
                        command += string_input.at(i);
                        i++;
                    }while(string_input.at(i) != ']');
                }
                else if (string_input.at(i) == '&'
                && string_input.at(i+1) == '&'){
                    command += "&&";
                    commands.push_back(command);
                    command = "";
                    i += 3;
                }
                else if (string_input.at(i) == '|'
                && string_input.at(i+1) == '|'){
                    command += "||";
                    commands.push_back(command);
                    command = "";
                    i += 3;
                }
                if (string_input.at(i) == '#'){
                    command += ";";
                    commands.push_back(command);
                    //cout << command << endl;
                    command = "";
                    // /////////////////////////////
                    for(; i < string_input.size()-1; i++)
                        comment += string_input.at(i);
                    // /////////////////////////////
                }
                else if (string_input.at(i) == ';'){
                    command += ";";
                    commands.push_back(command);
                    command = "";
                    i++;
                }
                else
                    command += string_input.at(i);
                if(i + 1 >= string_input.size()){
                    //command += " ";
                    commands.push_back(command);
                    command = "";
                    i++;
                }
                //cout << i << " | " << count << endl;
            }
        }
        //EXECUTE HERE

        if(commands.at(commands.size()-1) == "\0")
            commands.pop_back();

        for (int i = 0; i < commands.size(); ++i) {
            //cout << commands.at(i) << "-";
        }
        //cout << "###### " << comment;
        //Executable* x = new Executable();
        //x->exe();
        //cout << "Parser works" << endl;
        //Tokenizer* x = new Tokenizer();
        //x->Tokenize(commands);

        return;
    };
    vector<string> parsed(){
        return commands;
    };
};

#endif //RSHELL_PARSER_H
