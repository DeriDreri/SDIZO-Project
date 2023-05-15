#include "matrixN.h"
#ifndef MATRIX_C
#define MATRIX_C 

MatrixN::MatrixN(){
    MatrixN(1);
}

MatrixN::MatrixN(int startingDimension){
    dimension = startingDimension;
    array = (int* )malloc(startingDimension * startingDimension * sizeof(int));
}

MatrixN::~MatrixN(){
    if(array != NULL)
        free(array);
}

int MatrixN::get(int x, int y){
    if(x >= dimension || y >= dimension) 
        throw std::out_of_range("Pozycja spoza macierzy");
    int position = x + dimension * y;
    return array[position];
}

void MatrixN::insert(int x, int y, int value){
    if (x >= dimension || y >= dimension)
        throw std::out_of_range("Pozycja spoza macierzy");
    int position = x + dimension * y;
    array[position] = value;
}

void MatrixN::print(){
    for(int i = 0; i < dimension * dimension; i++){
        if (i % dimension == 0) printf("\n");
        printf("%d ", array[i]);
    }
    printf("\n");
}
#endif