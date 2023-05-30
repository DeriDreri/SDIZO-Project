#include <iostream>
#include "matrixN.cpp"
#include "listN.cpp"
#include "edge.h"



edge *  kruskalMatrix(MatrixN * matrix);
edge *  kruskalList(ListN * list);
void treesUnion(int first, int second, int * trees, int size);
void bubbleEdgesSort(edge * edgesList, int size);