#include <stdio.h>
#include "array.cpp"
#include <iostream>
#include <cmath>

class Heap{

    Array heapArray;
    int heapSize;
    int heapLimit;

    void fixHeapUp(int index);
    void fixHeapDown(int index);
    void heapCreateDown();                         //Algorytm Floyda


    public:
        Heap();
        Heap(int size);
        Heap(Array array);
        void display();                            //Prowizorycznie, do implemenetacji późniejszej
        bool removeAt(int index);
        void add(int value);
        bool findElementOfValue(int value, int index);
};