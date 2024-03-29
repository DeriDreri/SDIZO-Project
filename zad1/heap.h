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
    void printNode(int depth, int parentIndex);


    public:
        Heap();
        Heap(int size);
        Heap(Array array);
        void displayTree();                            //Prowizorycznie, do implemenetacji późniejszej
        void displayArray();
        bool removeAt(int index);
        void add(int value);
        bool findElementOfValue(int value, int index);
};