#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
	private:
		Base* x;
		Base* y;
    public:
        Div(Base* value, Base* value2){
			x = value;
			y = value2;
			};
        virtual double evaluate() { return (x->evaluate())/(y->evaluate()); }
        virtual std::string stringify() { return x->stringify() + "/" + y->stringify(); }
};

#endif //__DIV_HPP__
