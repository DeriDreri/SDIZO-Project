#include "heapN.h"
#ifndef HEAPN_C
#define HEAPN_C
HeapN::HeapN(int limit){
    heapLimit = limit;
    heapArray = (int **)malloc(limit * sizeof(int *));
    for(int i = 0; i < limit; i++){
        heapArray[i] = (int *)malloc(2 * sizeof(int));
    }
    heapSize = 0;
}

HeapN::~HeapN(){
    for(int i = 0; i < heapLimit; i++){
        free(heapArray[i]);
        heapArray[i] = nullptr;
    }
    free(heapArray);
    heapArray = nullptr;
}

bool HeapN::isEmpty(){
    return (heapSize == 0);
}

int HeapN::indexOfParent(int index){
    return (index - 1) / 2;
}

int HeapN::indexOfLeft(int index){
    return 2 * index + 1;
}

int HeapN::indexOfRight(int index){
    return 2 * index + 2;
}

void HeapN::addElement(int node, int value){
    if(heapSize == heapLimit)
        throw "Heap full";
    heapArray[heapSize][0] = value;
    heapArray[heapSize][1] = node;
    heapSize++;
}

int HeapN::findElementOfValue(int value, int index){
    if(index >= heapSize)
        return -1;
    if(heapArray[index][0] == value )
        return index;
    if(heapArray[index][0] > value)
        return -1;
    int toReturn = findElementOfValue(value, indexOfLeft(index));
    if(toReturn != -1)
        return toReturn;
    toReturn = findElementOfValue(value, indexOfRight(index));
    return toReturn;
}

int HeapN::findElementOfNode(int node, int index){
    int toReturn = -1;
    if(index >= heapSize)
        return toReturn;
    int curNode = heapArray[index][1];
    if(curNode == node)
        return index;
    toReturn = findElementOfNode(node, indexOfLeft(index));
    if(toReturn != -1)
        return toReturn;
    toReturn = findElementOfNode(node, indexOfRight(index));
    return toReturn;
}

void HeapN::modifyValueOf(int node, int newKey){
  int index = findElementOfNode(node, 0);
  if(index == -1) return;
  heapArray[index][0] = newKey;
  fixHeap(index);  
}

int * HeapN::removeRoot(){
    int * toReturn = (int *)malloc(2 * sizeof(int));
    heapSize--;
    toReturn[0] = heapArray[0][0];
    toReturn[1] = heapArray[0][1];

    heapArray[0][0] = heapArray[heapSize][0];
    heapArray[0][1] = heapArray[heapSize][1];

    heapArray[heapSize][0] = toReturn[0];
    heapArray[heapSize][1] = toReturn[1];

    fixHeapDown(0);
    return toReturn;
}

void HeapN::fixHeapUp(int index){
    if(index == 0 || index >= heapSize) return;         //Blokada niepoprawnych warotści indeksu
    int parentIndex = indexOfParent(index);                      //Wyliczenie indeksu rodzica
    int value = heapArray[index][0];               
    int parentValue = heapArray[parentIndex][0];
    if(parentValue > value){                            //Sprawdza, czy należy zamienić potomka z rodzicem
        int parentNode = heapArray[parentIndex][1];
        int node = heapArray[index][1]; 
         
        heapArray[index][0] = parentValue;
        heapArray[index][1] = parentNode;

        heapArray[parentIndex][0] = value;
        heapArray[parentIndex][1] = node;

        fixHeapUp(parentIndex);                         //Naprawa jest kontynuowana w górę w przypadku naprawy
    }
}

void HeapN::fixHeapDown(int parentIndex){
    if(parentIndex >= heapSize) return;         //Rekurencja zatrzymuje się po osiągnieciu indeksu spoza kopca
    
    //Pobranie obu potomków i ich porównanie!!
    int leftIndex = indexOfLeft(parentIndex);
    if  (leftIndex >= heapSize)                 //Jeśli lewy potomek nie istnieje, to nie istnieje i prawy, funkcja się kończy
        return;             
    int leftValue = heapArray[leftIndex][0];

    int rightIndex = indexOfRight(parentIndex);
    int rightValue;
    if (rightIndex >= heapSize) 
        rightValue = INT_MAX;                  //Jeśli prawy potomek nie istnieje, to ustawiamy wysoką wartość zamiast pobierania z tablicy
    else 
        rightValue = heapArray[rightIndex][0];

    int index;                                 
    int value;
    int node;
    if(rightValue < leftValue){
        index = rightIndex;
        value = rightValue;
        node = heapArray[rightIndex][1];
    }
    else{
        index = leftIndex;
        value = leftValue;
        node = heapArray[leftIndex][1];
    }

    //Sprawdzanie czy rodzic jest mniejszy i potrzebna jest zamiana
    int parentValue = heapArray[parentIndex][0];
    int parentNode = heapArray[parentIndex][1];
    if(parentValue > value){
        heapArray[index][0] = parentValue;
        heapArray[index][1] = parentNode;

        heapArray[parentIndex][0] = value;
        heapArray[parentIndex][1] = node;

        fixHeapDown(index);                                 //Naprawa kontynuowana jest w dół, jeśli nastąpiła zamiana
    }
}

void HeapN::fixHeap(int index){
    if(index == 0){
        fixHeapDown(index);
        return;
    }
    if(heapArray[indexOfParent(index)][0] > heapArray[index][0]){
        fixHeapUp(index);
        return;
    }
    fixHeapDown(index);
}

void HeapN::floydHeap(){
    for (int i = (heapSize - 2)/2; i >= 0; i--){
        fixHeapDown(i);
    }
}

void HeapN::printNode(int depth, int parentIndex){
    
    for(int i = 0; i < depth; i++){
        if(i == depth -1 ) 
            if(parentIndex % 2 == 1)                //Dla lewego potomka
                std::cout << "├── ";
            else 
                std::cout << "└── ";                //Dla prawego potomka
        else
            std::cout << "│   ";
    }
    std::cout << heapArray[parentIndex][1] << ":" << heapArray[parentIndex][0] <<std::endl;
    int leftIndex = 2 * parentIndex + 1;
    if(leftIndex >= heapSize) 
        return;
    printNode(depth+1, leftIndex);
    int rightIndex = 2 * parentIndex + 2;
    if(rightIndex >= heapSize) 
        return;
    printNode(depth+1, rightIndex);
    
}

void HeapN::displayTree(){
    if(heapSize > 0)
        printNode(0, 0);
    std::cout << std::endl;
}
#endif