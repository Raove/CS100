#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    private:
    double x;
    Iterator* its;
    public:
        Op(double value) : Base() {x=value; };
        Op(std::string value){
            x=std::stoi(value);
        };
        double evaluate() { return x; }
        std::string stringify() { return std::to_string(x); }
        Iterator* create_iterator()
        {
            its = new NullIterator(this);
            return its;
        }
        Base* getLeft()
        {
            return nullptr;
        }
        Base* getRight()
        {
            return nullptr;
        }
        void accept(CountVisitor* v){v->visit_op();}
};

#endif //__OP_HPP__
