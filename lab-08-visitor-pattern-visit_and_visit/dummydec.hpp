#ifndef __DUMMYDEC_HPP__
#define __DUMMYDEC_HPP__

#include "base.hpp"
#include "decorator.hpp"

class DummyDec : public Decorator
{
    private:
    Base* dec;
    Iterator* its;
    public:
    
    DummyDec(){};
    DummyDec(Base* in)
    {
        dec=in;
    };
     double evaluate()
    {
        return dec->evaluate();
    }
         
    std::string stringify()
    {
        return dec->stringify();
    }
    Iterator* create_iterator()
    {
        its = new UnaryIterator(this);
        return its;
    }
    Base* getLeft() {return dec;}
    Base* getRight() {return nullptr;}
    void accept(CountVisitor* v){ v->visit_dummy(); }



};

#endif
