#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include "container.hpp"
#include "sort.hpp"
#include "op.hpp"
#include <list>
#include "base.hpp"
#include <algorithm>
#include <iostream>

class ListContainer : public Container {
protected:
    std::list<Base*> tree;
public:
    ListContainer() {this->sort_function = 0;}

    ListContainer(Sort* function) {this->sort_function = function;}

    void add_element(Base* element);

    void print();

    void sort();

    void swap(int i, int j);

    Base* at(int i);

    int size();
};

#endif //listc.hpp


