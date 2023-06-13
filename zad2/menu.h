#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <chrono>
#include "matrixN.cpp"
#include "listN.cpp"
#include "prime.cpp"
#include "kruskal.cpp"
#include "djikstra.cpp"
#include "bellmanFord.cpp"
#include "graphGenerator.cpp"
using namespace std;

void printMainMenu(void);
void printSubMenu(string);
void mstOperations();
void shortestPathOperations();
void maxFlowOperatons();
void loadFile(bool);
void primeAlgorithm();
void kruskalAlgoritm();
void djikstraAlgorithm();
void bellmanFordAlgoritm();
void mstData();
void shortPathData();
void clearArrays();
void fillArray(int nodesNumber, int density, bool twoWays, bool negativeValues);
void fillList(int nodesNumber, int density, bool twoWays, bool negativeValues);