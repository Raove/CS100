#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include <vector>

class Factory
{
    private:
    std::vector<std::string> x;
    std::vector<Base*> result;
    Base* base;
    Base* left;
    Base* right;
    bool state=true;
    protected:
    public:
    
        Factory() {};

        Factory(std::vector<std::string> in)
        {
            x=in;
        }
        
        std::vector<Base*> creator()
        {
            for(int i =0; i<x.size(); i++) {
                if (state) {
                    if (x[i] == "+") {
                        // createAdd();
                        left = new Op(x[i - 1]);
                        right = new Op(x[i + 1]);
                        base = new Add(left, right);
                        result.push_back(base);
                        state = false;
                    } else if (x[i] == "-") {
                        // createSub();
                        left = new Op(x[i - 1]);
                        right = new Op(x[i + 1]);
                        base = new Sub(left, right);
                        result.push_back(base);
                        state = false;
                    } else if (x[i] == "x") {
                        //  createMult();
                        left = new Op(x[i - 1]);
                        right = new Op(x[i + 1]);
                        base = new Mult(left, right);
                        result.push_back(base);
                        state = false;
                    } else if (x[i] == "/") {
                        //  createDiv();
                        left = new Op(x[i - 1]);
                        right = new Op(x[i + 1]);
                        base = new Div(left, right);
                        result.push_back(base);
                        state = false;
                    } else if (x[i] == "xx") {
                        //  createPow();
                        left = new Op(x[i - 1]);
                        right = new Op(x[i + 1]);
                        base = new Pow(left, right);
                        result.push_back(base);
                        state = false;
                    }
                } else {
                    if (x[i] == "+") {
                        //  createADD();
                        left = result.back();
                        right = new Op(x[i + 1]);
                        base = new Add(left, right);
                        result.push_back(base);
                    } else if (x[i] == "-") {
                        //  createSub();
                        left = result.back();
                        right = new Op(x[i + 1]);
                        base = new Sub(left, right);
                        result.push_back(base);
                    } else if (x[i] == "x") {
                        //  createMult();
                        left = result.back();
                        right = new Op(x[i + 1]);
                        base = new Mult(left, right);
                        result.push_back(base);
                    } else if (x[i] == "/") {
                        //  createDiv();
                        left = result.back();
                        right = new Op(x[i + 1]);
                        base = new Div(left, right);
                        result.push_back(base);
                    } else if (x[i] == "xx") {
                        //  createPow();
                        left = result.back();
                        right = new Op(x[i + 1]);
                        base = new Pow(left, right);
                        result.push_back(base);
                    }
                }
            }
            return result;
        }
};

#endif 
