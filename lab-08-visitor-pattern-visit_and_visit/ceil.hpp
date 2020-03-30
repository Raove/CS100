#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include "decorator.hpp"

class Ceil : public Decorator
{
    private:
    Base* dec;
    protected:
    public:
        
        Ceil()
        {
        };
        Ceil(Base* base)
        {
        dec=base;
        };

        double evaluate()
        {
            return std::ceil(dec->evaluate());
        }

        std::string stringify()
        {
            return dec->stringify();
        }

        Iterator* create_iterator() {return new UnaryIterator(this);}
        Base* getLeft() {return dec;}
        Base* getRight() {return nullptr;}
        void accept(CountVisitor* v){v->visit_ceil();}

};

#endif
