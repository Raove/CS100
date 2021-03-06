#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "decorator.hpp"

class Trunc : public Decorator
{
    private:
    Base* dec;
    protected:
    public:
        
    Trunc(){};

    Trunc(Base* base)
    {
    dec=base;
    };

    double evaluate()
    {
        return dec->evaluate();
    }
    
    std::string stringify()
    {
        return std::to_string(dec->evaluate());
    }

    Iterator* create_iterator() {return new UnaryIterator(this);}
    Base* getLeft() {return dec;}
    Base* getRight() {return nullptr;}
    void accept(CountVisitor* v){v->visit_trunc();}
    
};

#endif
