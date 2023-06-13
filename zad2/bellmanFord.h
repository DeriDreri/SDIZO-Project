#include "matrixN.cpp"
#include "listN.cpp"
#include "edge.h"
#include <limits.h>
#include <stdlib.h>


int ** bellFordMatrix(MatrixN * matrix, int startNode);
int ** bellFordList(ListN * list, int startNode);