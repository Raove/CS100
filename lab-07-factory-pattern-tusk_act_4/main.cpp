#include <iostream>
#include <vector>
#include <string>


#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "base.hpp"
#include "calculator.hpp"
#include "factory.hpp"

using namespace std;


int main(int argc,char** argv)

{
    vector<string> temp;
    string str = "";
    for(int i = 1; i < argc; i++){
        str += argv[i];
        temp.push_back(str);
        str = "";
    }
    Factory fact(temp);
    vector<Base*> created;
    created = fact.creator();       
    Calculator calc(created);
    calc.calculate();

    return 0;
}

