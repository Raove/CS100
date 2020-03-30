#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"


class Op : public Base {
    private:
    double x;

    public:
        Op(double value) : Base() {x=value; };
        Op(std::string value)
        {
         x=std::stoi(value);   
        };
        virtual double evaluate() { return x; }
        virtual std::string stringify() { return std::to_string(x); }
};

#endif //__OP_HPP__
