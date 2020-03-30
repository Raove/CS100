#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

#include "sort.hpp"
#include "container.hpp"

class SelectionSort : public Sort {
public:
    virtual void sort(Container* container);
};

#endif //__SELECTIONSORT_HPP__
