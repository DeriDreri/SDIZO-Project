#include "dijkstra.h"

void djikstraMatrix(MatrixN * matrix, int startingNode){
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

    printf(" --- Tablicowo ---\n");
    for (int i = 0; i < size; i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, distance[currentNode]);
        printf("%d", currentNode);
        while(currentNode != startingNode){
            printf(" -> %d", previous[currentNode]);
            currentNode = previous[currentNode];
        }
        printf("\n");
    }


    free(quene);
    quene = nullptr;
    free(distance);
    distance = nullptr;
    free(previous);
    previous = nullptr;
}



void djikstraList(ListN * list, int startingNode){
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

    printf("----- Listowo ------\n");
    for (int i = 0; i < size; i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, distance[currentNode]);
        printf("%d", currentNode);
        while(currentNode != startingNode){
            printf(" -> %d", previous[currentNode]);
            currentNode = previous[currentNode];
        }
        printf("\n");
    }


    free(quene);
    quene = nullptr;
    free(distance);
    distance = nullptr;
    free(previous);
    previous = nullptr;
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