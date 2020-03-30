#ifndef RSHELL_TOKENIZER_HPP
#define RSHELL_TOKENIZER_HPP

#include "../header/Token.hpp"
#include "../header/ShuntingYard.hpp"

class Tokenizer {
public:
    vector<Token*> Token_vector;
    vector<Command*> Commands;
    vector<Argument*> Arguments;
    vector<Token*> Connectors;
    Tokenizer(){};
    void Tokenize(vector<string> commands){
        //cout << "Start tokenizer" << endl;

        /*
        cout << "Vector size: " << commands.size() << endl;
        try {
            for (int i = 0; i < commands.size(); i++) {
                cout << "String : |" << commands[i] << "|" << endl;
            }
        }
        catch (exception e){}
         */

        //cout << "Vector size: " << commands.size() << endl;
        for(int i = 0; i < commands.size(); i++){
            string cmd = "";
            string arg = "";
            string cnt = "";
            bool rachel = false;
            bool cmddone = false;
            bool argdone = false;
            bool cntdone = false;
            string temp = commands[i];
            //cout << "string: |" << temp << "|" << endl;
            /*
            for(int j = 0; j < temp.size(); j++){
                try {
                if(temp.at(j) == '('){
                    //cout << "connector: |" << cnt << "|" << endl;
                    Token_vector.push_back(new Connector("("));
                }
                else if(temp.at(j) == ')'){
                    //cout << "connector: |" << cnt << "|" << endl;
                    Token_vector.push_back(new Connector(")"));
                }
                else if(temp.at(j) == '['){
                    j++;
                    Token_vector.push_back(new Command("test"));
                    cmddone = true;
                    do{
                        arg += temp.at(j);
                        j++;
                    }while(temp.at(j) != ']');
                    Token_vector.push_back(new Argument(arg));
                    argdone = true;
                }
                if(!cmddone) {
                    while (temp.at(j) != ' ' || temp.at(j) != '\0') {
                        cmd += temp.at(j);
                        j++;
                    }
                    cmddone = true;
                    Token_vector.push_back(new Command(cmd));
                }
                if(!argdone) {
                    if (temp.at(j) == '\"') {
                        j++;
                        do {
                            arg += temp.at(j);
                            j++;
                        } while (temp.at(j) != '\"');
                        //j++;
                        argdone = true;
                        Token_vector.push_back(new Argument(arg));
                    }
                }
                if(!argdone) {
                    while (temp.at(j) != '&' || temp.at(j) != '|'
                            || temp.at(j) != ';' || temp.at(j) != '\0'
                            || temp.at(j) != ')' || temp.at(j) != '(') {
                        arg += temp.at(j);
                        j++;
                    }
                    argdone = true;
                    Token_vector.push_back(new Argument(arg));
                }
                    if (temp.at(j) == ';') {
                        Token_vector.push_back(new Connector(";"));
                    } else if (temp.at(j) == '\0') {
                        Token_vector.push_back(new Connector("\0"));
                    } else if (temp.at(j) == '&' && temp.at(j + 1) == '&') {
                        Token_vector.push_back(new Connector("&&"));
                    } else if (temp.at(j) == '|' && temp.at(j + 1) == '|') {
                        Token_vector.push_back(new Connector("||"));
                    }
                }
                catch (exception e){
                }
            }
             */

            int j = 0;
            if(temp.at(j) == '('){
                cnt += temp.at(j);
                //cout << "connector: |" << cnt << "|" << endl;
                Token_vector.push_back(new Paren(cnt));
                cnt = "";
                j++;
            }
            if(temp.at(j) == ')'){
                cnt += temp.at(j);
                //cout << "connector: |" << cnt << "|" << endl;
                Token_vector.push_back(new Paren(cnt));
                cnt = "";
                j++;
            }
            if(temp.at(j) == '['){
                j++;
                cmd += "test";
                do{
                    arg += temp.at(j);
                    j++;
                }while(temp.at(j) != ']');
                j++;
            }
            try {
                while (temp.at(j) != ' ' && temp.at(j) != '\0') {
                    cmd += temp.at(j);
                    j++;
                }
            }
            catch (exception e){}
            //cout << "Works up to cmd" << endl;
            if(j >= temp.size())
                goto label;
            if(temp.at(j) == ' '){
                j++; //this is for after the command
            }
            if(temp.at(j) == '&' || temp.at(j) == '|'
               || temp.at(j) == ';' || temp.at(j) == '\0'
               || temp.at(j) == ')' || temp.at(j) == '('){
                goto labelconnector;
            }
            try {
                if (temp.at(j) == '\"') {
                    j++;
                    do {
                        arg += temp.at(j);
                        j++;
                    } while (temp.at(j) != '\"');
                    j++;
                }
            }
            catch(exception e){}

            //cout << "Works up to arg" << endl;
            try {
                while (temp.at(j) != '&' && temp.at(j) != '|'
                       && temp.at(j) != ';' && temp.at(j) != '\0'
                       && temp.at(j) != ')' && temp.at(j) != '(') {
                    arg += temp.at(j);
                    j++;
                }
                if(temp.at(j) == ')'){
                    cnt += temp.at(j);
                    //cout << "cmd: |" << cmd << "|" << endl;
                    //cout << "arg: |" << arg << "|" << endl;
                    //cout << "connector: |" << cnt << "|" << endl;
                    Token_vector.push_back(new Command(cmd));
                    Token_vector.push_back(new Argument(arg));
                    Token_vector.push_back(new Paren(cnt));
                    cmd = "";
                    arg = "";
                    cnt = "";
                    rachel = true;
                    j++;
                }
            }
            catch (exception e){}
            labelconnector:
            //cout << "Works up to arg" << endl;
            try {
                if (temp.at(j) == ';') {
                    cnt += ";";
                    goto label;
                } else if (temp.at(j) == '\0') {
                    cnt += "\0";
                    goto label;
                } else if (temp.at(j) == '&') {
                    cnt += "&&";
                    goto label;
                } else if (temp.at(j) == '|') {
                    cnt += "||";
                    goto label;
                } else if (temp.at(j + 1) == ';') {
                    arg += " ";
                    cnt += "&&";
                    goto label;
                } else if (temp.at(j + 1) == '\0') {
                    arg += " ";
                    cnt += "\0";
                    goto label;
                } else if (temp.at(j + 1) == '&') {
                    arg += " ";
                    cnt += "&&";
                    goto label;
                } else if (temp.at(j + 1) == '|') {
                    arg += " ";
                    cnt += "||";
                    goto label;
                }
            }
            catch (exception e){}
            //cout << "Works up to cnt" << endl;
            /*
            try {
                if (temp.at(j) == '&' || temp.at(j) == '|'
                    || temp.at(j) == ';' || temp.at(j) == ']')
                    cnt += temp.at(j);
                else
                    cnt += '\0';
                try {
                    if (temp.at(j + 1) == '&' || temp.at(j + 1) == '|') {
                        j++;
                        cnt += temp.at(j);
                    }
                }
                catch (exception e) {}
            }
            catch (exception e){}
             */
            /*
            if(temp.at(j+1) == '&' || temp.at(j+1) == '|' || temp.at(j+1) == ';')
                cnt += temp.at(j + 1);
                */

            label:

            try {
                if (arg.at(arg.size() - 1) == ' ') {
                    arg.replace(arg.size() - 1, 1, "");
                }
            }
            catch (exception e){}

            if(cnt == ""){
                cnt += "\0";
            }

            if(!rachel) {
                //cout << "cmdr: |" << cmd << "|" << endl;
                //cout << "argr: |" << arg << "|" << endl;
                //cout << "connectorr: |" << cnt << "|" << endl;
                if(cmd != "") {
                    Token_vector.push_back(new Command(cmd));
                }
                if(arg != "") {
                    Token_vector.push_back(new Argument(arg));
                }
                else
                    Token_vector.push_back(new Argument("\0"));
                if(cnt == "&&")
                    Token_vector.push_back(new And());
                else if(cnt == "||")
                    Token_vector.push_back(new Or());
                else if(cnt == ";")
                    Token_vector.push_back(new Semicolon());
                //cout << Commands.at(i)->getToken() << " | ";
                //cout << "\"" << Connectors.at(i)->getToken() << "\"" << endl;
                cmd = "";
                arg = "";
                cnt = "";
            }
            else{
                //cout << "connectorr: |" << cnt << "|" << endl;
                if(cnt == "&&")
                    Token_vector.push_back(new And());
                else if(cnt == "||")
                    Token_vector.push_back(new Or());
                else if(cnt == ";")
                    Token_vector.push_back(new Semicolon());
                cnt = "";
            }

        }
        //cout << endl;
        //cout << "Tokenizer Works" << endl;
        for(int i = 0; i < Token_vector.size();  i++){
            //cout << Token_vector[i]->getToken() << "-";
        }
        //cout << endl;
        //ShuntingYard* Shunt = new ShuntingYard();
        //Shunt->ShuntingYardRun(Token_vector);
        return;
    };
    vector<Token*> tokenized(){
        return Token_vector;
    };
};


#endif //RSHELL_TOKENIZER_HPP
