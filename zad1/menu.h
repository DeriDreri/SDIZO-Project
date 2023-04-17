#include <iostream>
#include <cstdlib>
#include <string>
#include "list.cpp"
#include "tree.cpp"
#include "heap.cpp"
#include "array.cpp"
#include <chrono>
#include <fstream> 

using namespace std;

void printMainMenu(void);
void printSubMenu(string);
void arrayOperations();
void listOperations();
void heapOperations();
void treeOperations();
void arrayLoad();
void arrayAddTest();
void arrayRemoveTest();
void arraySearchTest();
void arrayGenerate(int arrayIndex, int arraySize);
void arrayAdd(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void arrayRemove(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void arraySearch(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void listLoad();
void listAddTest();
void listRemoveTest();
void listSearchTest();
void listGenerate(int arrayIndex, int listSize);
void listAdd(int minimalElements, int maximumElements, int measurments, int listNumber);
void listRemove(int minimalElements, int maximumElements, int measurments, int listNumber);
void listSearch(int minimalElements, int maximumElements, int measurments, int listNumber);
void heapLoad();
void heapAddTest();
void heapRemoveTest();
void heapSearchTest();
void heapGenerate(int arrayIndex, int heapSize, int heapMax);
void heapAdd(int minimalElements, int maximumElements, int measurments, int heapNumber);
void heapRemove(int minimalElements, int maximumElements, int measurments, int heapNumber);
void heapSearch(int minimalElements, int maximumElements, int measurments, int heapNumber);
void treeLoad();
void treeAddTest();
void treeRemoveTest();
void treeSearchTest();
void treeGenerate(int arrayIndex, int treeSize);
void treeAdd(int minimalElements, int maximumElements, int measurments, int treeNumber);
void treeRemove(int minimalElements, int maximumElements, int measurments, int treeNumber);
void treeSearch(int minimalElements, int maximumElements, int measurments, int treeNumber);

