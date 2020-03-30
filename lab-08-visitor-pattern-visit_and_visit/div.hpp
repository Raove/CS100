#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
	private:
		Base* x;
		Base* y;
		Iterator* its;
    public:
        Div(Base* value, Base* value2){
			x = value;
			y = value2;
			};
        virtual double evaluate() { return ((x->evaluate())/(y->evaluate())); }
        virtual std::string stringify() { return x->stringify() + "/" + y->stringify(); }

        Iterator* create_iterator() {
            its = new BinaryIterator(this);
            return its;
            }
        Base* getLeft() {return x;}
        Base* getRight() {return y;}
        void accept(CountVisitor* v){v->visit_div();}
};

#endif //__DIV_HPP__
