#include "listcontainer.h"
#include "container.hpp"

void ListContainer::add_element(Base* element)
{
    tree.push_back(element);
    return;
}

void ListContainer::print()
{
    for (std::list<Base*>::iterator it = tree.begin(); it != tree.end(); it++)
    {
        (*it)->stringify();
    }
    std::cout << " ";
    return;
}

void ListContainer::sort()
{
    if (this->sort_function == nullptr)
    {

    }
    else
    {
        sort_function->sort(this);
    }
    return;
}

void ListContainer::swap(int i, int j)
{
    std::list<Base*>::iterator it_1 = tree.begin();
    std::list<Base*>::iterator it_2 = tree.begin();
    for(int k=0;k<i;k++)
    {
        it_1++;
    }
    for(int k=0;k<j;k++)
    {
        it_2++;
    }
    std::swap(*it_1,*it_2);

    return;
}

Base* ListContainer::at(int i)
{
    std::list<Base*>::iterator it = tree.begin();
    for(int j=0;j<i;j++)
    {
        it++;
    }
    return it.operator*();
}

int ListContainer::size()
{
    return tree.size();
}
