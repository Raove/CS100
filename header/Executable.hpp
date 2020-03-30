#ifndef RSHELL_EXECUTABLE_HPP
#define RSHELL_EXECUTABLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../header/Command.hpp"
#include "../header/Argument.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

class Executable {
protected:
    char** execute;
public:
    Executable (){};
    void makechar(Token* cmd){
        string cmd_str = cmd->getToken();
        Command* x = (Command*)cmd;
        string arg_str = x->getArg()->getToken();
        execute = new char*[3];
        execute[2] = NULL;
        execute[0] = (char*)cmd_str.c_str();
        //cout << "\"" << arg_str << "\"" << endl;
        if(arg_str == "") {
            execute[1] = NULL;
        } else
            execute[1] = (char *) arg_str.c_str();
    }
    bool exe(){
        bool worked = false;
        if(strncmp(execute[0], "exit" ,4) == 0)
            exit(42);
        if(strncmp(execute[0], "test" ,4) == 0) {
            struct stat sb;
            if (strncmp(execute[1], "-e" ,2) == 0) {
                string x = execute[1];
                string y = "";
                for(int i = 3; i < x.size(); i++){
                    y.push_back(x[i]);
                }
                char* temp = new char[y.length()+1];
                strcpy(temp, y.c_str());
                if (stat(temp, &sb) == 0) {
                    cout << "TRUE" << endl;
                    worked = true;
                } else {
                    cout << "FALSE" << endl;
                    worked = false;
                }
            } else if (strncmp(execute[1], "-f" ,2) == 0) {
                string x = execute[1];
                string y = "";
                for(int i = 3; i < x.size(); i++){
                    y.push_back(x[i]);
                }
                char* temp = new char[y.length()+1];
                strcpy(temp, y.c_str());
                if (stat(temp, &sb) != 0) {
                    cout << "FALSE" << endl;
                    worked = false;
                } else if (sb.st_mode & S_IFREG) {
                    cout << "TRUE" << endl;
                    worked = true;
                } else {
                    cout << "FALSE" << endl;
                    worked = false;
                }
            } else if (strncmp(execute[1], "-e" ,2) == 0) {
                string x = execute[1];
                string y = "";
                for(int i = 3; i < x.size(); i++){
                    y.push_back(x[i]);
                }
                char* temp = new char[y.length()+1];
                strcpy(temp, y.c_str());
                if (stat(temp, &sb) != 0) {
                    cout << "FALSE" << endl;
                    worked = false;
                } else if (sb.st_mode & S_IFDIR) {
                    cout << "TRUE" << endl;
                    worked = true;
                } else {
                    cout << "FALSE" << endl;
                    worked = false;
                }
            } else {
                if (stat(execute[1], &sb) == 0) {
                    cout << "TRUE" << endl;
                    worked = true;
                } else {
                    cout << "FALSE" << endl;
                    worked = false;
                }
            }
        }
        pid_t ID = fork();
        if (ID == 0){
            int exe = execvp(execute[0], execute);
            if(exe == -1) {
                perror("Execvp failed: ");
                return false;
            }
        }
        else if (ID > 0){
            if(wait(0) == -1){
                perror("Fork failed: ");
            }
            waitpid(ID, NULL, 0);
        }
        return worked;
    };
};

#endif //RSHELL_EXECUTABLE_HPP
