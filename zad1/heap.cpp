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

Heap::Heap(Array array){
    heapSize = array.getSize();
    heapArray = Array(100);
    for(int i = 0; i < heapSize; i++)
        heapArray.addElementAt(i, array.valueAt(i));
    heapLimit = 100;
    heapCreateDown();
}

void Heap::heapCreateDown(){
    int lastParentIndex = (heapSize-2)/2;
    for (int i = lastParentIndex; i >= 0; i--){
        fixHeapDown(i);
    }
}

void Heap::fixHeapUp(int index){
    if(index == 0 || index >= heapSize) return;         //Blokada niepoprawnych warotści indeksu
    int parentIndex = (index-1)/2;                      //Wyliczenie indeksu rodzica
    int value = heapArray.valueAt(index);               
    int parentValue = heapArray.valueAt(parentIndex);
    if(parentValue < value){                            //Sprawdza, czy należy zamienić potomka z rodzicem
        heapArray.setValueAt(parentIndex, value); 
        heapArray.setValueAt(index, parentValue); 
        fixHeapUp(parentIndex);                         //Naprawa jest kontynuowana w górę w przypadku naprawy
    }
}

void Heap::fixHeapDown(int parentIndex){
    if(parentIndex >= heapSize) return;         //Rekurencja zatrzymuje się po osiągnieciu indeksu spoza kopca
    
    //Pobranie obu potomków i ich porównanie!!
    int leftIndex = 2 * parentIndex + 1;
    if  (leftIndex >= heapSize)                 //Jeśli lewy potomek nie istnieje, to nie istnieje i prawy, funkcja się kończy
        return;             
    int leftValue = heapArray.valueAt(leftIndex);

    int rightIndex = 2 * parentIndex + 2;
    int rightValue;
    if (rightIndex >= heapSize) 
        rightValue = -9999999;                  //Jeśli prawy potomek nie istnieje, to ustawiamy niską wartość zamiast pobierania z tablicy
    else 
        rightValue = heapArray.valueAt(rightIndex);

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

    //Sprawdzanie czy rodzic jest mniejszy i potrzebna jest zamiana
    int parentValue = heapArray.valueAt(parentIndex);
    if(parentValue < value){
        heapArray.setValueAt(parentIndex, value);           //Zamiana
        heapArray.setValueAt(index, parentValue);           //Zamiana
        fixHeapDown(index);                                 //Naprawa kontynuowana jest w dół, jeśli nastąpiła zamiana
    }

}

void Heap::add(int value){
    heapArray.setValueAt(heapSize, value);
    heapSize++;    
    fixHeapUp(heapSize-1);
  
}

bool Heap::removeAt(int index){
    if(index >= heapSize || index < 0)                                  //Blokada w przypadku usuwania spoza kopca
        return false;    
    int valueToSwap = heapArray.valueAt(heapSize - 1);                  //Zachowanie wartości z ostatniego liścia 
    heapArray.setValueAt(heapSize-1, heapArray.valueAt(index));         //Wstawienie wartośći do usunięcia na ostatni liść
    heapArray.setValueAt(index, valueToSwap);                           //Wstawienie wartości zachowanej z ostatniego liścia na miejsce usuwanego wierzchołka
    heapSize--;                                                         //Usunięcie ostatniego liścia
    int lastParentIndex = (heapSize-2)/2;
    if (index <= lastParentIndex){
        int parentIndex = (index - 1) / 2;
        if(parentIndex < 0 || heapArray.valueAt(parentIndex) < heapArray.valueAt(index))
            fixHeapUp(index);                                                           //Naprawa kopca
        else
            fixHeapDown(index);
    }
    return true;
}

void Heap::printNode(int depth, int parentIndex){
    
    for(int i = 0; i < depth; i++){
        if(i == depth -1 ) 
            if(parentIndex % 2 == 1)                //Dla lewego potomka
                std::cout << "├── ";
            else 
                std::cout << "└── ";                //Dla prawego potomka
        else
            std::cout << "│   ";
    }
    std::cout << heapArray.valueAt(parentIndex) << std::endl;
    int leftIndex = 2 * parentIndex + 1;
    if(leftIndex >= heapSize) 
        return;
    printNode(depth+1, leftIndex);
    int rightIndex = 2 * parentIndex + 2;
    if(rightIndex >= heapSize) 
        return;
    printNode(depth+1, rightIndex);
    
}

void Heap::displayTree(){
    if(heapSize > 0)
        printNode(0, 0);
    std::cout << std::endl;
    
}

void Heap::displayArray(){
    for (int i = 0; i < heapSize; i++)
        std::cout << "[" << heapArray.valueAt(i) << "]";
    std::cout << std::endl;
}

bool Heap::findElementOfValue(int value, int index){
    if(index >= heapSize || index < 0)                      //Jeśli przekroczył, kończ
        return false;
    if(heapArray.valueAt(index) == value)                   //Jeśli został znaleziony, kończ jako true
        return true;
    if(heapArray.valueAt(index) < value)                    //Jeśli wartość w wierzchołku jest mniejsza niż wartość, to nie szukaj głębiej, końćz
        return false;                                       //W tej gałęzi będą tylko mniejsze wartości
    bool toReturn = findElementOfValue(value, 2*index+1);   //Sprawdź lewą gałąź  
    if(toReturn)                                            //Przerywaj, jeśli został znaleziony i przekaż wyżej w rekurencji
        return toReturn;
    toReturn = findElementOfValue(value, 2*index+2);        //Sprawdź prawą gałąź
    return toReturn;
}
