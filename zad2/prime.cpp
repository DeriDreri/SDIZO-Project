#include "prime.h"
void primeMatrix(MatrixN * matrix){
    //Incijalizuje podstawowe parametry
    int nodesNumber = matrix -> getDimension();
    int * key = (int *)malloc(nodesNumber * sizeof(int));
    int * previous = (int *)malloc(nodesNumber * sizeof(int));
    List * query = new List(0);
    for (int i = 0; i < nodesNumber; i++){
        key[i] = INT_MAX-1;
        previous[i] = -1;
        query -> addAtEnd(i);
    }
    int startNode = 0;
    key[startNode] = 0;
    previous[startNode] = startNode;

    //Przechodzi po kolei przez wszsytkie wierzchołki kolejki
    while(!(query -> isEmpty())){
        int selectedNode = extractMin(query, key);
        int * adjusted = matrix -> getAdjusted(selectedNode);
        for (int i = 0; i <= adjusted[0]; i++){
            int adjustedNode = adjusted[i +1];
            if(query->findElementOfValue(adjustedNode) && matrix->getEdgeWage(selectedNode, adjustedNode) < key[adjustedNode]){
                key[adjustedNode] = matrix -> getEdgeWage(selectedNode, adjustedNode);
                previous[adjustedNode] = selectedNode;
            }
        }
    }

    int counter = 0;
    printf("----- Macierzowo ------\n");
    for(int i = 0; i < nodesNumber; i++){
        if(key[i] == 0)
            continue;
        printf("(%d, %d) : %d\n", i, previous[i], key[i]);
        counter+= key[i];
    }
    printf("Koszt całkowity: %d\n", counter);
    //Tworzy drzewo spinające na podstawie uzyskanych wartości previous i key
    /*MatrixN newMatrix = MatrixN(matrix -> getDimension());
    for(int i = 0; i < matrix -> getDimension(); i++){
        newMatrix.insert(i, previous[i], key[i]);
        newMatrix.insert(previous[i], i, key[i]);
    }
    newMatrix.print();*/

    free(key);
    key = nullptr;
    free(query);
    query = nullptr;
    free(previous);
    previous = nullptr;
}

void primeList(ListN * list){
    /*for(int i = 0; i < list ->getSize(); i++){
        int * adjusted = list -> getAdjusted(i);
        printf("Sąsiedzi %d: ", i);
        for (int j = 0; j < adjusted[0]; j++){
            printf("%d, ", adjusted[1+j]);
        }
    }*/
    int nodesNumber = list -> getSize();
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

    //Tworzy drzewo spinające na podstawie uzyskanych wartości previous i key
    int counter = 0;
    printf("----- Listowo ------\n");
    for(int i = 0; i < nodesNumber; i++){
        if(key[i] == 0)
            continue;
        printf("(%d, %d) : %d\n", i, previous[i], key[i]);
        counter+=key[i];
    }
    printf("Koszt całkowity: %d\n", counter);
    /*ListN newList = ListN(list -> getSize());
    for(int i = 0; i < list -> getSize(); i++){
        if(key[i] == 0) continue;
        newList.addEdge(i, previous[i], key[i]);
        newList.addEdge(previous[i], i, key[i]);
    }

    newList.print();*/
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