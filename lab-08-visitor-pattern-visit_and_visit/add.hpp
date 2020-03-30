#ifndef __add_hpp__
#define __add_hpp__

#include "base.hpp"

class Add: public Base {
    private:
    Base* x;
    Base* y;
    Iterator* its;
   
    public:
        Add (Base* value,Base* value2){
        x = value;
        y = new Op(value2->evaluate());
};

        Add(Base* value, double value2){
        x = value;
        y = new Op(value2);

};

        Add(double value, Base* value2){
        x = new Op(value);
        y = value2;
        
};

        Add(double value, double value2){
        x = new Op(value);
        y = new Op(value2);
};


        virtual double evaluate() { return x->evaluate() + y->evaluate() ; }
        virtual std::string stringify() { return x->stringify() +  "+" +  y->stringify() ; }

        Iterator* create_iterator() {
            its = new BinaryIterator(this);
            return its;
        }
        Base* getLeft() {return x;}
        Base* getRight() {return y;}
        void accept(CountVisitor* v){v->visit_add();}
};

#endif

