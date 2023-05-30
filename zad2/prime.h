#include "matrixN.cpp"
#include "listN.cpp"
#include "list.cpp"
#include <iostream>
#include <limits.h>
#include "heapN.cpp"
using namespace std;
int ** primeMatrix(MatrixN * matrix, int nodesNumber);
int ** primeList(ListN * list, int nodesNumber);
int extractMin(List * list, int * key);