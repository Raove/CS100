#include "BubbleSort.h"
#include "container.hpp"

void BubbleSort::sort(Container* container){
    int i;
    int j;
    bool flag;
    int numLength = container->size();
    for(i = 0; (i < numLength - 1); i++){
        flag = false;
        for(j = 0; j < (numLength - i - 1) ; j++){
            if(container->at(j)->evaluate() > container->at(j+1)->evaluate()){
                container->swap(j, j+1);
                flag = true;
            }
        }
        if(flag == false)
            break;
    }
    return;
}

