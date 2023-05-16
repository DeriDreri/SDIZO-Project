#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
using namespace std::string_literals;
#ifndef MATRIX_H 
#define MATRIX_H 
class MatrixN{
    int dimension;
    int * array;
    public:

        //Definiuje macierz kwadratową o niezmienionym rozmiarze
        MatrixN(int dimension);
        ~MatrixN();
        int getDimension();
        //Pozyksuje wartość z macierzy
        //W przypadku podaniu wartości spoza zasięgu zwraca wyjątek!
        int get(int x, int y);
        //Zmienia wartość na podanej pozycji na podaną wartość
        //W przypadku pozycji spoza macierzy zwraca wyjątek!
        void insert(int x, int y, int value);
        int * getAdjusted(int node);
        int getEdgeWage(int start, int end);
        void print();
};
#endif