#include "dijkstra.h"

int ** djikstraMatrix(MatrixN * matrix, int startingNode){
    int size = matrix -> getDimension();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    HeapN quene = HeapN(size);
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX-1;
        previous[i] = -1;
        quene.addElement(i, distance[i]);
    } 
    distance[startingNode] = 0;
    quene.modifyValueOf(startingNode, 0);

    while(!quene.isEmpty()){
        int * selected = quene.removeRoot();
        int selectedNode = selected[1];
        for(int checkedNode = 0; checkedNode < size; checkedNode++){
            int checkedNodeWeight = matrix -> getEdgeWage(selectedNode, checkedNode);
            if(checkedNodeWeight == 0)
                continue;
            int value = distance[selectedNode] + checkedNodeWeight;
            if (distance[checkedNode] > value){
                distance[checkedNode] = value;
                previous[checkedNode] = selectedNode;
                quene.modifyValueOf(checkedNode, value);
            }
        }
        free(selected);
        selected = nullptr;
    }

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;

    return toReturn;
}



int ** djikstraList(ListN * list, int startingNode){
    int size = list -> getSize();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    HeapN quene = HeapN(size);
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX-1;
        previous[i] = -1;
        quene.addElement(i, distance[i]);
    } 
    distance[startingNode] = 0;
    quene.modifyValueOf(startingNode, 0);

    while(!quene.isEmpty()){
        int * selected = quene.removeRoot();
        int selectedNode = selected[1];
        ListElementN * attached = list -> getList(selectedNode); 
        if(attached == nullptr)
            break;
        while(attached != nullptr){
            int checkedNode = attached -> value;
            int value = distance[selectedNode] + list -> getEdgeWage(selectedNode, checkedNode);
            if (distance[checkedNode] > value){
                distance[checkedNode] = value;
                previous[checkedNode] = selectedNode;
                quene.modifyValueOf(checkedNode, value);
            }
            if(attached -> next == nullptr)
                break;
            attached = attached -> next;
        }
        
    }

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;

    return toReturn;
}

//Funckja oparta o listę
int extractMin2(List * list, int * key){
    int minimal = INT_MAX;
    int minimalNode = -1;
    for(int i = 0; i < list -> getSize(); i++){
        int current = list -> valueAt(i);
        if(key[current] < minimal){
            minimalNode = current;
            minimal = key[current];
        }
    }
    list -> removeElementOfValue(minimalNode);
    return minimalNode;
}