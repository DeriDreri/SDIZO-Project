#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "matrixN.cpp"
#include "listN.cpp"
#include "prime.cpp"
#include "kruskal.cpp"

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