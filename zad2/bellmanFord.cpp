#include "bellmanFord.h"

void bellFordMatrix(MatrixN * matrix, int startNode){
    int size = matrix -> getDimension();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX/2;
        previous[i] = -1;
    } 
    distance[startNode] = 0;
    
    int edgesNumber = 0;
    for(int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            if(matrix -> get(i, j) != 0)
            edgesNumber++;
        }
    }

    edge * edgesList = (edge *)malloc(edgesNumber * sizeof(edge));
    int counter = 0;
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int value = matrix -> get(i,j);
            if(value != 0){
                edgesList[counter] = {i, j, value};
                counter++;
            }
        }
    }

    for(int i = 1; i < size; i++){
        for (int j = 0; j < edgesNumber; j++){
            int start = edgesList[j].start;
            int end = edgesList[j].end;
            int weight = edgesList[j].value;
            if(distance[end] > distance[start] + weight){
                distance[end] = distance[start] + weight;
                previous[end] = start;
            }
        }
        
    }

    printf(" --- Tablicowo ---\n");
    for (int i = 0; i < size; i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, distance[currentNode]);
        printf("%d", currentNode);
        while(currentNode != startNode){
            printf(" -> %d", previous[currentNode]);
            currentNode = previous[currentNode];
        }
        printf("\n");
    }

    free(edgesList);
    edgesList = nullptr;
    free(distance);
    distance = nullptr;
    free(previous);
    previous = nullptr;

}

void bellFordList(ListN * list, int startNode){

}