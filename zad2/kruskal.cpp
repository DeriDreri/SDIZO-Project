#include "kruskal.h"



edge * kruskalMatrix(MatrixN * matrix, int size){
    int * subTrees = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        subTrees[i] = i;
    }

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
        for (int j = i; j < size; j++){
            int value = matrix -> get(i,j);
            if(value != 0){
                edgesList[counter] = {i, j, value};
                counter++;
            }
        }
    }
    
    bubbleEdgesSort(edgesList, edgesNumber);

    edge * finalEdgesList = (edge *)malloc(edgesNumber * sizeof(edge));
    counter = 0;
    for(int i = 0; i < edgesNumber; i++){
        if(subTrees[edgesList[i].start] == subTrees[edgesList[i].end])
            continue;
        finalEdgesList[counter] = {edgesList[i].start, edgesList[i].end, edgesList[i].value};
        treesUnion(edgesList[i].start, edgesList[i].end, subTrees, edgesNumber);
        counter++;
    }

    free(subTrees);
    subTrees = nullptr;

    return finalEdgesList;
}


edge * kruskalList(ListN * list, int size){
    int * subTrees = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        subTrees[i] = i;
    }

    int edgesNumber = 0;
    for(int i = 0; i < size; i++){
        edgesNumber += list -> getAdjusted(i)[0];
    }
    edge * edgesList = (edge *)malloc(edgesNumber * sizeof(edge));
    int counter = 0;

    for(int i = 0; i < size; i++){
        int * adjusted = list -> getAdjusted(i);
        for (int j = 1; j <= adjusted[0]; j++){
            edgesList[counter] = {i, adjusted[j], list -> getEdgeWage(i, adjusted[j])};
            counter++;
        }
    }

    bubbleEdgesSort(edgesList, edgesNumber);

    edge * finalEdgesList = (edge *)malloc(edgesNumber * sizeof(edge));
    counter = 0;
    for(int i = 0; i < edgesNumber; i++){
        if(subTrees[edgesList[i].start] == subTrees[edgesList[i].end])
            continue;
        finalEdgesList[counter]= {edgesList[i].start, edgesList[i].end, edgesList[i].value};
        treesUnion(edgesList[i].start, edgesList[i].end, subTrees, edgesNumber);
        counter++;
    }

    free(subTrees);
    subTrees = nullptr;

    return finalEdgesList;
}

void treesUnion(int first, int second, int * trees, int size){
    int change = trees[second]; 
    for (int i = 0; i < size; i++){
        if(trees[i] == change)
            trees[i] = trees[first];
    }    
}

void bubbleEdgesSort(edge * edgesList, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(edgesList[j].value > edgesList[j+1].value){
                int start = edgesList[j].start;
                int end = edgesList[j].end;
                int value = edgesList[j].value;

                edgesList[j].start = edgesList[j+1].start;
                edgesList[j].end = edgesList[j+1].end;
                edgesList[j].value = edgesList[j+1].value;

                edgesList[j+1].start = start;
                edgesList[j+1].end = end;
                edgesList[j+1].value = value;
            }
        }
    }
}
