#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#ifndef LISTN_H
#define LISTN_H

class ListElement{
    public:
        ListElement * next;                                                     //Wskaźnik na następny element listy
        ListElement * prev;                                                     //Wskaźnik na poprzedni element listy
        int value;                                                              //Wartość elementu listy
        ListElement(ListElement * previous, int value, ListElement * next);     //Konstruktor przypisujący dwa powiązane elementy listy oraz wartość
};

class ListN{
    int size;
    ListElement ** neighbours;
    ListElement ** weights;
    public:
        ListN();
        ListN(int amountOfNodes);
        ~ListN();
        void addEdge(int start, int end, int value);
        bool hasEdge(int start, int end);
        bool valueOfEdge(int start, int end);
        void print();
};


#endif