#ifndef GENERATE
#define GENERATE
#include "matrixN.cpp"
#include "listN.cpp"

MatrixN * generateMatrix(int size, int density, bool twoWays=true, bool negativeValues=false);
ListN * generateList(int size, int density, bool twoWays=true, bool negativeValues=false);
int generateEdgeWeight(bool negativeValues=false);
#endif