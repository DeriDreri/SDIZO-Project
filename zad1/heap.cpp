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
    int parentIndex = (index-1)/2;
    int value = heapArray.valueAt(index);
    int parentValue = heapArray.valueAt(parentIndex);
    if(parentValue < value){
        heapArray.setValueAt(parentIndex, value); 
        heapArray.setValueAt(index, parentValue); 
        fixHeapUp(parentIndex);
    }
}

void Heap::fixHeapDown(int parentIndex){
    if(parentIndex >= heapSize) return;         //Rekurencja zatrzymuje się po osiągnieciu indeksu spoza kopca
    
    //Pobranie obu potomków i ich porównanie!!
    int leftIndex = 2 * parentIndex + 1;
    if  (leftIndex >= heapSize) return;
    int rightIndex = 2 * parentIndex + 2;
    int leftValue;
    if (rightIndex >= heapSize) leftValue = 9999999;
    else int leftValue = heapArray.valueAt(leftIndex);
    int rightValue = heapArray.valueAt(rightIndex);


    int index;
    int value;
    if(rightValue > leftValue){
        index = rightIndex;
        value = rightValue;
    }
    else{
        index = leftIndex;
        value = leftValue;
    }

    int parentValue = heapArray.valueAt(parentIndex);
    if(parentValue < value){
        heapArray.setValueAt(parentIndex, value);
        heapArray.setValueAt(index, parentValue);
        fixHeapDown(index);
    }

}

void Heap::add(int value){
    heapArray.setValueAt(heapSize, value);
    fixHeapUp(heapSize);
    heapSize++;    
}

void Heap::removeRoot(){
    int rootValue = heapArray.valueAt(0);
    int value = heapArray.valueAt(heapSize-1);
    heapArray.setValueAt(0, value);
    heapArray.setValueAt(heapSize-1, rootValue);
    heapSize--;
    fixHeapDown(0);
}

void Heap::display(){
    heapArray.display();
    /*
    int spacesAmount = log2(heapSize) * 2;
    int i = 0;
    int spacesAtLevel = 1;
    while(i < heapSize){
        std::cout << std::string(spacesAmount, ' ');
        for(int j = 0; j < spacesAtLevel; j++){
            std::cout << heapArray.valueAt(i) << "    ";
            i++;
            if(i >= heapSize) break;
        }
        if(i >= heapSize) break;
        spacesAmount-=2;
        std::cout << std::endl << std::string(spacesAmount, ' ');

        spacesAtLevel *= 2;
        if (spacesAtLevel >= heapSize) spacesAtLevel = heapSize - 1;
        std::cout << std::endl;
        */

}

int main(){
    Heap testHeap = Heap();
    testHeap.add(4);
    testHeap.add(5);
    testHeap.add(2);
    testHeap.add(10);
    testHeap.add(9);
    testHeap.removeRoot();
    testHeap.display();
    return 0;
}