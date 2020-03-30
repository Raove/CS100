#ifndef __VECTORCONTAINER_H__
#define __VECTORCONTAINER_H__

#include "container.hpp"
#include "base.hpp"
#include "sort.hpp"
#include "op.hpp"
#include <vector>
#include <iostream>

using namespace std;

class VectorContainer : public Container {
protected:
    vector<Base*> trees;
public:

    VectorContainer()  {this->sort_function = 0;}

    VectorContainer(Sort* function) { this->sort_function = function;}

    void add_element(Base* element);

    void print();

    void sort();

    void swap(int i, int j);

    Base* at(int i);

    int size();
};

#endif //__VECTORCONTAINER_H__
