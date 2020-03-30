#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
	private:
		Base* x;
		Base* y;
		Iterator* its;
    public:
        Mult(Base* value, Base* value2){
			x = value;
			y = value2;
			};
        virtual double evaluate() { return ((x->evaluate())*(y->evaluate())); }
        virtual std::string stringify() { return x->stringify() + "*" + y->stringify(); }

        Iterator* create_iterator() {
            its = new BinaryIterator(this);
            return its;
        }
        Base* getLeft() {return x;}
        Base* getRight() {return y;}
        void accept(CountVisitor* v){v->visit_mult();}
};

#endif //__MULT_HPP__
