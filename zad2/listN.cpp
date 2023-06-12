#include "listN.h"
#ifndef LISTN_C 
#define LISTN_C
ListElementN::ListElementN(ListElementN * previous, int value, ListElementN * next){
    this -> prev = previous;
    this -> value = value;
    this -> next = next;
}

ListN::ListN(int amountOfNodes){
    this -> size = amountOfNodes;
    this -> neighbours = (ListElementN **)malloc(amountOfNodes * sizeof(ListElementN*));
    for(int i = 0; i < amountOfNodes; i++)
        neighbours[i] = nullptr;
    this -> weights = (ListElementN **)malloc(amountOfNodes * sizeof(ListElementN*));
    for(int i = 0; i < amountOfNodes; i++)
        weights[i] = nullptr;
}

ListN::~ListN(){
   // if(neighbours != nullptr)
   //    free(neighbours);
   //    neighbours = nullptr;
   // if(weights != nullptr)
   //     free(weights);
   //     weights = nullptr;
}

int ListN::getSize(){
    return this -> size;
}

void ListN::print(){
    for (int i = 0; i < size; i++){
        printf("%d -> ", i);
        if(neighbours[i] == nullptr){
            printf("\n");
            continue; 
        }
        ListElementN * currentN = neighbours[i];
        ListElementN * currentW = weights[i];
        while(currentN != nullptr){
            printf("(%d, %d) ", currentN -> value, currentW -> value);
            currentN = currentN -> next;
            currentW = currentW -> next;
        }
        printf("\n");
    }
}       

ListElementN * ListN::getList(int node){
    if (node >= size || node < 0)
        throw "Out of the bonds!";
    return neighbours[node];
}


int * ListN::getAdjusted(int node){
    if(neighbours[node] == nullptr) 
        return 0;
    int * adjusted = (int *)malloc(sizeof(int));
    adjusted[0] = 0;
    ListElementN * current = neighbours[node];
    while(current != nullptr){
        adjusted[0] = adjusted[0] + 1;
        adjusted = (int *)realloc(adjusted, (adjusted[0]+1)*sizeof(int));
        adjusted[adjusted[0]] = current -> value;
        current = current -> next;
    }
    return adjusted;
}

int ListN::getEdgeWage(int start, int end){
    if(start >= size || end >= size)
        throw "Index out of bonds";
    ListElementN * currentPointer = neighbours[start];
    ListElementN * currentWeight = weights[start];
    while(currentPointer != nullptr){
        if(currentPointer -> value == end)
            return currentWeight -> value;
        currentPointer = currentPointer -> next;
        currentWeight = currentWeight -> next;
    }
    return 0;
}

void ListN::addEdge(int start, int end, int value){
    if(start >= size || end >= size)
        throw std::out_of_range("Nie ma takiego wierzchołka");
    if(neighbours[start] == nullptr){
        neighbours[start] = new ListElementN(nullptr, end, nullptr);
        weights[start] = new ListElementN(nullptr, value, nullptr);
    }
    else{
        ListElementN * currentN = neighbours[start];
        ListElementN * currentW = weights[start];
        while(currentN -> next != nullptr){
            currentN = currentN -> next;
            currentW = currentW -> next;
        }
        currentN -> next = new ListElementN(currentN, end, nullptr);
        currentW -> next = new ListElementN(currentW, value, nullptr);
    }
}

int * ListN::getEdge(int edgeIndex){
    ListElementN * currentN = neighbours[0];
    ListElementN * currentW = weights[0];
    int node = 0;
    while(edgeIndex > 0){
        if(currentN -> next == nullptr){
            node++;
            if(node == size)
                return nullptr;
            currentN = neighbours[node];
            currentW = weights[node];
        }
        else{
            currentN = currentN -> next;
            currentW = currentW -> next;
        }
        edgeIndex--;
    }
    int * toReturn = (int *)malloc(3 * sizeof(int));
    toReturn[0] = node;
    toReturn[1] = currentN -> value;
    toReturn[2] = currentW -> value;
    return toReturn;
}

#endif