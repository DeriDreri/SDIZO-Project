#include "matrixN.cpp"
#include "listN.cpp"
#include "edge.h"
#include <limits.h>
#include <stdlib.h>


int ** bellFordMatrix(MatrixN * matrix, int startNode, int edgesNumber);
int ** bellFordList(ListN * list, int startNode, int edgesNumber);