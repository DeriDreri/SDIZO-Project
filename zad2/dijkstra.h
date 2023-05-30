#include "matrixN.cpp"
#include "listN.cpp"
#include "list.cpp"
#include <limits.h>
using namespace std;


int ** djikstraMatrix(MatrixN * matrix, int startingNode);
int ** djikstraList(ListN * list, int startingNode);
int extractMin2(List * list, int * key);