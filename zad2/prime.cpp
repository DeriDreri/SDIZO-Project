#include "prime.h"
int ** primeMatrix(MatrixN * matrix, int nodesNumber){
    //Incijalizuje podstawowe parametry
    int * key = (int *)malloc(nodesNumber * sizeof(int));
    int * previous = (int *)malloc(nodesNumber * sizeof(int));
    HeapN query = HeapN(nodesNumber);
    int startNode = 0;
    for (int i = 0; i < nodesNumber; i++){ 
        key[i] = INT_MAX-1;
        previous[i] = -1;
        query.addElement(i, key[i]);
    }
    key[startNode] = 0;
    previous[startNode] = startNode;
    query.modifyValueOf(startNode, 0);
    
    previous[startNode] = startNode;

    //Przechodzi po kolei przez wszsytkie wierzchołki kolejki
    while(!(query.isEmpty())){
        int * selected = query.removeRoot();
        int selectedNode = selected[1];
        int * adjusted = matrix -> getAdjusted(selectedNode);
        for (int i = 0; i <= adjusted[0]; i++){
            int adjustedNode = adjusted[i +1];
            int value = matrix->getEdgeWage(selectedNode, adjustedNode);
            if(query.findElementOfNode(adjustedNode) != -1 && value < key[adjustedNode]){
                key[adjustedNode] = value;
                previous[adjustedNode] = selectedNode;
                query.modifyValueOf(adjustedNode, value);
            }
        }
        free(adjusted);
        adjusted = nullptr;
        free(selected);
        selected = nullptr;
    }

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = key;

    return toReturn;
}

int ** primeList(ListN * list, int nodesNumber){

    int * key = (int *)malloc(nodesNumber * sizeof(int));
    int * previous = (int *)malloc(nodesNumber * sizeof(int));
    List * query = new List(0);             // POPRWIĆ NA KOPIEC
    for (int i = 0; i < nodesNumber; i++){
        key[i] = INT_MAX-1;
        previous[i] = -1;
        query -> addAtEnd(i);
    }
    int startNode = 0;
    key[startNode] = 0;
    previous[startNode] = startNode;

    while(!(query -> isEmpty())){
        int selectedNode = extractMin(query, key);
        int * adjusted = list -> getAdjusted(selectedNode);
        for (int i = 0; i <= adjusted[0]; i++){
            int adjustedNode = adjusted[i +1];
            if(query->findElementOfValue(adjustedNode) && list ->getEdgeWage(selectedNode, adjustedNode) < key[adjustedNode]){
                key[adjustedNode] = list -> getEdgeWage(selectedNode, adjustedNode);
                previous[adjustedNode] = selectedNode;
            }
        }
    }


    
    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = key;

    free(query);
    query = nullptr;
    return toReturn;

}

//Funckja oparta o listę
int extractMin(List * list, int * key){
    int minimal = INT_MAX;
    int minimalNode = -1;
    for(int i = 0; i < list -> getSize(); i++){
        if(key[list -> valueAt(i)] < minimal){
            minimalNode = list -> valueAt(i);
            minimal = key[list -> valueAt(i)];
        }
    }
    list -> removeElementOfValue(minimalNode);
    //list -> displayList();
    return minimalNode;
}