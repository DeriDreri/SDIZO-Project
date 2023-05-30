#include "dijkstra.h"

int ** djikstraMatrix(MatrixN * matrix, int startingNode){
    int size = matrix -> getDimension();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    List * quene = new List(0);
    for (int i = 0; i < size; i++){
        quene -> addAtEnd(i);
        distance[i] = INT_MAX-1;
        previous[i] = -1;
    } 
    distance[startingNode] = 0;

    while(!quene -> isEmpty()){
        int selectedNode = extractMin2(quene, distance);
        int * attached = matrix -> getAdjusted(selectedNode);
        for(int i = 1; i <= attached[0]; i++){
            int checkedNode = attached[i];
            if (distance[checkedNode] > distance[selectedNode] + matrix -> getEdgeWage(selectedNode, checkedNode)){
                distance[checkedNode] = distance[selectedNode] + matrix -> getEdgeWage(selectedNode, checkedNode);
                previous[checkedNode] = selectedNode;
            }
        }
        free(attached);
        attached = nullptr;
    }

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;

    free(quene);
    quene = nullptr;
    return toReturn;
}



int ** djikstraList(ListN * list, int startingNode){
    int size = list -> getSize();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    List * quene = new List(0);
    for (int i = 0; i < size; i++){
        quene -> addAtEnd(i);
        distance[i] = INT_MAX-1;
        previous[i] = -1;
    } 
    distance[startingNode] = 0;

    while(!quene -> isEmpty()){
        int selectedNode = extractMin2(quene, distance);
        int * attached = list -> getAdjusted(selectedNode);
        for(int i = 1; i <= attached[0]; i++){
            int checkedNode = attached[i];
            if (distance[checkedNode] > distance[selectedNode] + list -> getEdgeWage(selectedNode, checkedNode)){
                distance[checkedNode] = distance[selectedNode] + list -> getEdgeWage(selectedNode, checkedNode);
                previous[checkedNode] = selectedNode;
            }
        }
        free(attached);
        attached = nullptr;
    }

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;

    free(quene);
    quene = nullptr;
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
    //list -> displayList();
    return minimalNode;
}