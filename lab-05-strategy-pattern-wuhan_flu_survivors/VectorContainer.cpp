#include "container.hpp"
#include "VectorContainer.h"

using namespace std;

void VectorContainer::add_element(Base* element){
    trees.push_back(element);
}

void VectorContainer::print(){
    string treeStr;
    for(unsigned i = 0; i < trees.size(); i++){
        treeStr = trees.at(i)->stringify();
        cout << treeStr << endl;
    }
}

void VectorContainer::sort(){
    if(this->sort_function != nullptr){
        sort_function->sort(this);
    }
    else
    {

    }
}

void VectorContainer::swap(int i, int j){
    Base* temp;
    temp = trees.at(i);
    trees.at(i) = trees.at(j);
    trees.at(j) = temp;
}

Base* VectorContainer::at(int i){
    return trees[i];
}

int VectorContainer::size(){
    return trees.size();
}
