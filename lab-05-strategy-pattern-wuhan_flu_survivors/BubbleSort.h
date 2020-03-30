#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#include "sort.hpp"
#include "container.hpp"

class BubbleSort : public Sort {
public:
    virtual void sort(Container* container);
};

#endif //__BUBBLESORT_HPP__

