#include "matrixN.cpp"
#include "listN.cpp"
#include "list.cpp"
#include <limits.h>
using namespace std;


void djikstraMatrix(MatrixN * matrix, int startingNode);
void djikstraList(ListN * list, int startingNode);
int extractMin2(List * list, int * key);