#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "decorator.hpp"

class Abs : public Decorator
{
    private:
    Base* dec;
    Iterator* its;
    protected:
    public:
        
    Abs(){};

    Abs(Base* base)
    {
        dec=base;
    };    
    Iterator* create_iterator()
    {
    its = new UnaryIterator(this);
    return its;
    }

    Base* getLeft()
    {
        return dec;
    }

    Base* getRight()
    {
        return nullptr;
    }

    double evaluate()
    {
        return std::abs(dec->evaluate());
    }

    std::string stringify()
    {
        return dec->stringify();
    }

    void accept(CountVisitor* v){v->visit_abs();}

};

#endif
