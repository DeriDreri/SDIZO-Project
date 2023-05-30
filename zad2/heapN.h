#include <stdlib.h>
#include <limits.h>
#ifndef HEAPN_H 
#define HEAPN_H 
class HeapN{
    int ** heapArray;
    int heapSize;
    int heapLimit;

public:
    HeapN(int limit);
    ~HeapN();
    bool isEmpty();
    int indexOfParent(int index);
    int indexOfLeft(int index);
    int indexOfRight(int index);
    void addElement(int value, int key);
    int findElementOfValue(int value, int index = 0);
    int findElementOfNode(int node, int index = 0);
    void modifyValueOf(int node, int newKey);
    int * removeRoot();
    void fixHeapDown(int index);
    void fixHeapUp(int index);
    void fixHeap(int index);
    void floydHeap();
};
#endif