#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include "decorator.hpp"

class Paren : public Decorator
{
    private:
    Base* dec;    
    protected:
    public:
    
    Paren(){};
    
    Paren(Base* base)
    {
        dec=base;
    };
    
    double evaluate()
    {
        return dec->evaluate();
    }

    std::string stringify()
    {
        return "(" + dec->stringify() + ")";
    }
    

};

#endif
