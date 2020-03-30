#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include "base.hpp"
#include <math.h>
#include <stdlib.h>

class Decorator : public Base
{
    private:
    Base* dec;
    protected:
    public:
    
        Decorator()
        {
        };
        Decorator(Base* base)
        {
           dec=base; 
        };


};

#endif
