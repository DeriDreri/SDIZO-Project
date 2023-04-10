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
    void heapCreateUp();
    void heapCreateDown();

    public:
        Heap();
        Heap(int size);
        void display();                             //Prowizoruycznie, do implemenetacji późniejszej
        bool removeAt(int index);
        void removeRoot();
        void add(int value);
        bool findElementOfValue(int value);
};