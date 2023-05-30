#include <iostream>
#include "matrixN.cpp"
#include "listN.cpp"
#include "edge.h"



edge *  kruskalMatrix(MatrixN * matrix, int size);
edge *  kruskalList(ListN * list, int size);
void treesUnion(int first, int second, int * trees, int size);
void bubbleEdgesSort(edge * edgesList, int size);