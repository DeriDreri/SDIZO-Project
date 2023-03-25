#include <stdio.h>
#include "array.cpp"

class Heap{

    Array heapArray = Array(100);
    int heapSize;

    public:
        Heap();
        void display();
        bool removeAt(int index);
        void add(int value);
        void balanceTree();
        bool findElementOfValue(int value);

};