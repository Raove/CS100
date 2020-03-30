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
#include "iterator.hpp"
#include "countvisitor.hpp"
#include "dummydec.hpp"

using namespace std;


int main(int argc,char** argv)

{
    vector<string> temp;
    string str = "";
    for(int i = 1; i < argc; i++)
    {
        str += argv[i];
        temp.push_back(str);
        str = "";
    }

    Factory fact(temp);
    Calculator calc(fact.creator());
    //calc.calculate();

    Base* op1 = new Op(1);
    Base* op2 = new Op(2);
    Base* add = new Add(op1, op2);
    Base* dec = new DummyDec(add);
    Iterator* pre = new PreorderIterator(dec);
    CountVisitor* visit = new CountVisitor();
    pre->first();

    while(pre->current() != nullptr)
    {
        pre->current()->accept(visit);
        pre->next();
    }

    cout << "Op count: " << visit->op_count() << endl;
    cout << "Add count: " << visit->add_count() << endl;
    cout << "Sub count: " << visit->sub_count() << endl;
    cout << "Mult count: " << visit->mult_count() << endl;
    cout << "Div count: " << visit->div_count() << endl;
    cout << "Pow count: " << visit->pow_count() << endl;
    cout << "Ceil count: " << visit->ceil_count() << endl;
    cout << "Abs count: " << visit->abs_count() << endl;
    cout << "Trunc count: " << visit->trunc_count() << endl;
    cout << "Paren count: " << visit->paren_count() << endl;

    return 0;
}

