#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

#include "../header/Parser.hpp"

int main(){
    string command = "";
    while(1) {
        //cout << char(36);
        cout << "$ ";
        getline(cin, command);
        if (command == "exit")
            exit(42);
        Parser parser(command);
        Tokenizer* tokenizing = new Tokenizer();
        tokenizing->Tokenize(parser.parsed());
        ShuntingYard* Shunt = new ShuntingYard();
        Shunt->ShuntingYardRun(tokenizing->tokenized());
        Tree tree(Shunt->Yarded());
        tree.startTree();
        //tree.MichaelScreamsAtMe();
    }
    return 0;
}
