#include "bellmanFord.h"

int ** bellFordMatrix(MatrixN * matrix, int startNode, int edgesNumber){
    int size = matrix -> getDimension();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX/2;
        previous[i] = -1;
    } 
    distance[startNode] = 0;
    

    edge * edgesList = (edge *)malloc(edgesNumber * sizeof(edge));
    int counter = 0;                                            // Bezpośrrednio krawędzie z macierzy
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int value = matrix -> get(i,j);
            if(value != 0){
                edgesList[counter] = {i, j, value};
                counter++;
            }
        }
    }
    //SPRAWDZANIE CYKLU UJEMNEGO
    
    for(int i = 1; i < size; i++){
        bool change = false;
        for (int j = 0; j < edgesNumber; j++){
            int start = edgesList[j].start;
            int end = edgesList[j].end;
            int weight = edgesList[j].value;
            if(distance[end] > distance[start] + weight){
                change = true;
                distance[end] = distance[start] + weight;
                previous[end] = start;
            }
        }
        if(!change) break;
    }

    free(edgesList);
    edgesList = nullptr;

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;
    return toReturn;
}

int ** bellFordList(ListN * list, int startNode, int edgesNumber){
    int size = list -> getSize();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX/2;
        previous[i] = -1;
    } 
    distance[startNode] = 0;

    edge * edgesList = (edge *)malloc(edgesNumber * sizeof(edge));
    for(int i = 0; i < edgesNumber; i++){
        int * edge = list -> getEdge(i);
        edgesList[i] = {edge[0], edge[1], edge[2]};
        free(edge);
    }

    for(int i = 1; i < size; i++){
        bool change = false;
        for (int j = 0; j < edgesNumber; j++){
            int start = edgesList[j].start;
            int end = edgesList[j].end;
            int weight = edgesList[j].value;
            if(distance[end] > distance[start] + weight){
                change = true;
                distance[end] = distance[start] + weight;
                previous[end] = start;
            }
        }
        if(!change) break;
    }

    free(edgesList);
    edgesList = nullptr;
  
    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;
    return toReturn;
}