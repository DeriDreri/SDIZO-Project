#include "heap.h"


Heap::Heap(){
     heapSize = 0;
    heapArray = Array(100);
    heapLimit = 100;
}

Heap::Heap(int size){
    heapSize = 0;
    heapArray = Array(size);
    heapLimit = size;
}

void Heap::fixHeapUp(int index){
    if(index == 0) return;
    int parentIndex = index/2;
    int value = heapArray.valueAt(index);
    int parentValue = heapArray.valueAt(parentIndex);
    if(parentValue < value){
        heapArray.setValueAt(parentIndex, value);
        heapArray.setValueAt(index, parentValue);
        fixHeapUp(parentIndex);
    }
}


void Heap::add(int value){
    heapArray.setValueAt(heapSize, value);
    fixHeapUp(heapSize);
    heapSize++;    
}

void Heap::display(){
    for(int i = 0; i < heapSize; i++){
        std::cout << heapArray.valueAt(i) << std::endl;   
    }
}

int main(){
    Heap testHeap = Heap();
    testHeap.add(4);
    testHeap.add(5);
    testHeap.add(2);
    testHeap.add(10);
    testHeap.add(9);
    testHeap.display();
    return 0;
}