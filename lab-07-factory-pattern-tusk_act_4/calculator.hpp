#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <vector>
#include <string>
#include "base.hpp"

using namespace std;

class Calculator {
private:
    vector<Base*> saved;
public:
    Calculator(){};
    Calculator(vector<Base*> pointers) {
        saved = pointers;
    };

    void calculate(){
        cout << saved.back()->stringify()<< "=" ;
        cout << saved.back()->evaluate() << endl;
        return;
    }
};

#endif //__CALCULATOR_HPP__
