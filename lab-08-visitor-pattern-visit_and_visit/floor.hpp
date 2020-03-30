#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include "decorator.hpp"

class Floor : public Decorator
{
    private:
    Base* dec;
    protected:
    public:
        
        Floor() {};
        
        Floor(Base* base)
        {
        dec=base;
        };
    
        double evaluate()
        {
            return std::floor(dec->evaluate());
        }
        
        std::string stringify()
        {
            return dec->stringify();
        }

        Iterator* create_iterator() {return new UnaryIterator(this);}
        Base* getLeft() {return dec;}
        Base* getRight() {return nullptr;}
        void accept(CountVisitor* v){v->visit_floor();}
};

#endif
