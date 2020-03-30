#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <stdlib.h>

class Rand : public Base {
	private:
		double value;
    public:
        Rand(){
            value  = rand() %100;
        };
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value);}
};

#endif //__RAND_HPP__
