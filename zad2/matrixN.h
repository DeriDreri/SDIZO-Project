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

        MatrixN();
        //Definiuje macierz kwadratową o niezmienionym rozmiarze
        MatrixN(int dimension);
        ~MatrixN();
        //Pozyksuje wartość z macierzy
        //W przypadku podaniu wartości spoza zasięgu zwraca wyjątek!
        int get(int x, int y);
        //Zmienia wartość na podanej pozycji na podaną wartość
        //W przypadku pozycji spoza macierzy zwraca wyjątek!
        void insert(int x, int y, int value);
        void print();
};
#endif