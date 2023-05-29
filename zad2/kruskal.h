#include <iostream>
#include "matrixN.cpp"
#include "listN.cpp"
#include "edge.h"


typedef struct 
{
    int node;
    int tree;
}tree;

void kruskalMatrix(MatrixN * matrix);
void kruskalList(ListN * list);
void treesUnion(int first, int second, tree * trees, int size);
void bubbleEdgesSort(edge * edgesList, int size);
int findSet(int node, tree * subTrees);