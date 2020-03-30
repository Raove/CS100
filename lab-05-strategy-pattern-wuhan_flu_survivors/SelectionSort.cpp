#include "SelectionSort.h"
#include "container.hpp"

void SelectionSort::sort(Container* container){
    int first;
    int numLength = container->size();
    for(int i = 0; i < numLength-1; i++) {
      int minIndex = i;
      int currMin = container->at(i)->evaluate();
      for(int j = i; j < numLength; j++) {
	if(container->at(j)->evaluate() < currMin) {
	  minIndex = j;
	  currMin = container->at(j)->evaluate();
	}
      }
      container->swap(i,minIndex);
    }
    return;
}
