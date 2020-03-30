#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "decorator.hpp"

class Abs : public Decorator
{
    private:
    Base* dec;
    protected:
    public:
        
    Abs(){};

    Abs(Base* base)
    {
        dec=base;
    };    

    double evaluate()
    {
        return std::abs(dec->evaluate());
    }

    std::string stringify()
    {
        return dec->stringify();
    }

};

#endif
