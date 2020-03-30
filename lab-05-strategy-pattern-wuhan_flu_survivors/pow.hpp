 #ifndef __pow_hpp__
      #define __pow_hpp__
  
      #include "base.hpp"
    #include <math.h>
  
      class Pow: public Base {
          private:
          Base* x;
         Base* y;
 
        public:
            Pow(Base* value,Base* value2){
            x = value;
            y = value2;
    };
 
           Pow(Base* value, double value2){
            x = value;
           y = new Op(value2);
 
    };
 
            Pow(double value, Base* value2){
            x = new Op(value);
            y = value2;
 
    };
 
            Pow(double value, double value2){
            x = new Op(value);
            y = new Op(value2);
    };
 
 
            virtual double evaluate() { return std::pow(x->evaluate(), y->evaluate()) ; }
           virtual std::string stringify() { return x->stringify() + "**" +  y->stringify() ; }
    };
 
    #endif
