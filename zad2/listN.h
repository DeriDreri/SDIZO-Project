#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#ifndef LISTN_H
#define LISTN_H

class ListElementN{
    public:
        ListElementN * next;                                                     //Wskaźnik na następny element listy
        ListElementN * prev;                                                     //Wskaźnik na poprzedni element listy
        int value;                                                              //Wartość elementu listy
        ListElementN(ListElementN * previous, int value, ListElementN * next);     //Konstruktor przypisujący dwa powiązane elementy listy oraz wartość
};

class ListN{
    int size;
    ListElementN ** neighbours;
    ListElementN ** weights;
    public:

        ListN(int amountOfNodes);
        ~ListN();
        int getSize();
        void addEdge(int start, int end, int value);
        bool hasEdge(int start, int end);
        bool valueOfEdge(int start, int end);
        void print();
        int * getAdjusted(int node);
        int getEdgeWage(int start, int end);
        int * getEdge(int edgeIndex);
};


#endif