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
void listGenerate(int arrayIndex, int arraySize);
void listAdd(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void listRemove(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void listSearch(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void heapLoad();
void heapAddTest();
void heapRemoveTest();
void heapSearchTest();
void heapGenerate(int arrayIndex, int arraySize);
void heapAdd(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void heapRemove(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void heapSearch(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void treeLoad();
void treeAddTest();
void treeRemoveTest();
void treeSearchTest();
void treeGenerate(int arrayIndex, int arraySize);
void treeAdd(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void treeRemove(int minimalElements, int maximumElements, int measurments, int arrayNumber);
void treeSearch(int minimalElements, int maximumElements, int measurments, int arrayNumber);

