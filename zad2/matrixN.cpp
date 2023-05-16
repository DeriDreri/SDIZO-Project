#include "matrixN.h"
#ifndef MATRIX_C
#define MATRIX_C 



MatrixN::MatrixN(int startingDimension){
    dimension = startingDimension;
    array = (int* )malloc(startingDimension * startingDimension * sizeof(int));
    for(int i = 0; i < dimension * dimension; i++){
        array[i] = 0;
    }
}

MatrixN::~MatrixN(){
    free(array);
}

int MatrixN::getDimension(){
    return this -> dimension;
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

int * MatrixN::getAdjusted(int node){
    int * adjusted = (int *)malloc(sizeof(int));
    adjusted[0] = 0;
    for(int i = 0; i < dimension; i++){
        if(array[node * dimension + i] != 0){
            adjusted[0] = adjusted[0] + 1;
            adjusted = (int *)realloc(adjusted, adjusted[0] * sizeof(int));
            adjusted[adjusted[0]] = i;
        }
    }
    return adjusted;
}
int MatrixN::getEdgeWage(int start, int end){
    return array[start * dimension + end];
}

void MatrixN::print(){
    for(int i = 0; i < dimension * dimension; i++){
        if (i % dimension == 0) printf("\n");
        printf("%d ", array[i]);
    }
    printf("\n");
}
#endif