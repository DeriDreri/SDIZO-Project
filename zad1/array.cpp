#include "array.h"
#ifndef ARRAY_C 
#define ARRAY_C 

Array::Array(){
    Array(0);
}

Array::Array(int size){
    arraySize = size;
    arrayStart = (int*)calloc(size, 4);
}

int Array::valueAt(int index){
    if (index >= arraySize || index < 0)                    
        throw std::out_of_range("Index out of array's range"); 
    return *(arrayStart + index);                       
}

bool Array::setValueAt(int index, int value){
    if (index >= arraySize || index < 0) return false;      
    *(arrayStart + index) = value;
    return true;
}

bool Array::addElementAt(int index, int value){
    if(index > arraySize || index < 0) return false;

    arraySize++;
    arrayStart = (int*)realloc(arrayStart, arraySize * 4);      // Zwiększa rozmiar tablicy o 1 i przenosi dane w nowe miesjce pamięci, rezerwując dodatkowe 4 bajty
    
    int* currentIndexPointer = arrayStart+index;;          // Przenosi wskaźnik na pozycję indeksu

    int dataBuffor1 = 0;
    int dataBuffor2 = 0;

    dataBuffor1 = *currentIndexPointer;                     
    *currentIndexPointer = value;                           // Zastępuje wartość na indeksie

    while(index < arraySize-1){                             // Pętla przepychająca wartości w górę tablicy, od indeksu w którym dodano element
        index++;
        currentIndexPointer++;
        dataBuffor2 = *currentIndexPointer;
        *currentIndexPointer = dataBuffor1;
        dataBuffor1 = dataBuffor2;
    }

    return true;
}

bool Array::removeElementAt(int index){
    if (index >= arraySize || index < 0) return false;      

    int* currentIndexPointer = arrayStart+arraySize-1;    //Ustawia wskaźnik na ostatni element tablicy
    int dataBuffor1 = 0;
    int dataBuffor2 = 0;
    dataBuffor1 = *currentIndexPointer;

    for (int i = 0; i < arraySize - index-1; i++){         //Przepycha wartości w dół aż do osiągnięcia pozycji usuwanego elementu
        currentIndexPointer--;
        dataBuffor2 = *currentIndexPointer;
        *currentIndexPointer = dataBuffor1;
        dataBuffor1 = dataBuffor2;
    }

    arraySize--;                                            //Zmniejsza rozmiar tablicy o 1 i realokuje pamięć w bloku o nowym rozmiarze, 
    arrayStart = (int*)realloc(arrayStart, arraySize * 4);  //zwalaniając nadmiarową pamięć

    return true;
}

void Array::display(){
    int* dataPointer = arrayStart;
    for(int i = 0; i < arraySize; i++){
        std::cout << "[" << *dataPointer << "] ";
        dataPointer++;
    }
    std::cout << std::endl;
}

bool Array::findElement(int value){
    int* dataPointer = arrayStart;
    for(int i = 0; i < arraySize; i++){
        if(*dataPointer == value) return true;
        dataPointer++;
    }
    return false;
}

int Array::getSize(){
    return arraySize;
}

#endif