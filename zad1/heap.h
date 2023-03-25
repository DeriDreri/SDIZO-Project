#include <stdio.h>
#include "array.cpp"
#include <iostream>

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
        void display();
        bool removeAt(int index);
        void add(int value);
        bool findElementOfValue(int value);
};