#include "listN.h"
#ifndef LISTN_C 
#define LISTN_C
ListElement::ListElement(ListElement * previous, int value, ListElement * next){
    this -> prev = previous;
    this -> value = value;
    this -> next = next;
}

ListN::ListN(){
    ListN(10);
}

ListN::ListN(int amountOfNodes){
    this -> size = amountOfNodes;
    this -> neighbours = (ListElement **)malloc(amountOfNodes * sizeof(ListElement*));
    for(int i = 0; i < amountOfNodes; i++)
        neighbours[i] = nullptr;
    this -> weights = (ListElement **)malloc(amountOfNodes * sizeof(ListElement*));
    for(int i = 0; i < amountOfNodes; i++)
        weights[i] = nullptr;
}

ListN::~ListN(){
    free(neighbours);
    free(weights);
}

void ListN::print(){
    for (int i = 0; i < size; i++){
        printf("%d -> ", i);
        if(neighbours[i] == nullptr){
            printf("\n");
            continue; 
        }
        ListElement * currentN = neighbours[i];
        ListElement * currentW = weights[i];
        while(currentN != nullptr){
            printf("(%d, %d) ", currentN -> value, currentW -> value);
            currentN = currentN -> next;
            currentW = currentW -> next;
        }
        printf("\n");
    }
}       

void ListN::addEdge(int start, int end, int value){
    if(start >= size || end >= size)
        throw std::out_of_range("Nie ma takiego wierzchołka");
    if(neighbours[start] == nullptr){
        neighbours[start] = new ListElement(nullptr, end, nullptr);
        weights[start] = new ListElement(nullptr, value, nullptr);
    }
    else{
        ListElement * currentN = neighbours[start];
        ListElement * currentW = weights[start];
        while(currentN -> next != nullptr){
            currentN = currentN -> next;
            currentW = currentW -> next;
        }
        currentN -> next = new ListElement(currentN, end, nullptr);
        currentW -> next = new ListElement(currentW, value, nullptr);
    }
}

#endif