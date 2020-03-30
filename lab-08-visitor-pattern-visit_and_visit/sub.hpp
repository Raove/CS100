   #ifndef __sub_hpp__
   #define __sub_hpp__
  
   #include "base.hpp"
  
   class Sub: public Base {
       private:
       Base* x;
       Base* y;
        Iterator* its; 
      public:
         Sub(Base* value,Base* value2){
         x = value;
         y = value2;
  };
 

          Sub(Base* value, double value2){
          x = value;
          y = new Op(value2);

  };

          Sub(double value, Base* value2) {
          x = new Op(value);
          y = value2;
 
  };

         Sub(double value, double value2){
          x = new Op(value);
          y = new Op(value2);
  };
        Iterator* create_iterator()
        {
        its = new BinaryIterator(this);
        return its;
        }

        Base* getLeft()
        {
        return x;
        }
        Base* getRight()
        {
        return y;
        }
        void accept(CountVisitor* v){v->visit_sub();}
 
          virtual double evaluate() { return x->evaluate() - y->evaluate() ; }
          virtual std::string stringify() { return x->stringify() +  "-" +  y->stringify() ; }
  };
 
 
  #endif
