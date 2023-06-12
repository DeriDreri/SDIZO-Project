#include "graphGenerator.h"
MatrixN * generateMatrix(int size, int density, bool twoWays, bool negativeValues){
    if(density >= 100 || density < 0)
        throw "Wrong density!";
    MatrixN * toReturn = new MatrixN(size);

   
    //Creates minimal spanning tree
    for(int i = 0; i < size-1; i++){
        int weight = generateEdgeWeight(negativeValues);
        toReturn -> insert(i, i+1, weight);
        if(twoWays)
            toReturn -> insert(i+1, i, weight);
    }

    //Calculates density
    if(density == 99){
        int maxEdges = (size * (size - 1));
        if(twoWays) {
            maxEdges /= 2;
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == j)
                    continue;
                if(toReturn -> getEdgeWage(i, j) != 0)
                    continue;
                int weight = generateEdgeWeight(negativeValues);
                toReturn -> insert(i, j, weight);
                if(twoWays)
                    toReturn -> insert(j, i, weight);
            }
        }
        int edgesToRemove = maxEdges / 100 + 1;
        //printf("Max edges: %d\n", maxEdges);
        //printf("Edges to remove: %d\n", edgesToRemove);
        while(edgesToRemove > 0){
            int startNode = rand()%size;
            int endNode = rand()%size;
            if(startNode == endNode)
                continue;
            if(toReturn -> getEdgeWage(startNode, endNode) == 0)
                continue;
            //printf("Removing %d -> %d\n", startNode, endNode);
            toReturn -> insert(startNode, endNode, 0);
            if(twoWays)
                toReturn -> insert(endNode, startNode, 0);
            edgesToRemove--;
        }
    }
    else{
        int maxEdges = (size * (size - 1));
        if(twoWays) {
            maxEdges /= 2;
        }
        //printf("Max edges: %d\n", maxEdges);
        int lackingEdges = ((maxEdges * density) / 100) - size + 1;
    
        //printf("Lacking edges: %d\n", lackingEdges);
        while(lackingEdges > 0){
            int startNode = rand()%size;
            int endNode = rand()%size;
            if(startNode == endNode)
                continue;
            if(toReturn -> getEdgeWage(startNode, endNode) != 0){
                continue;
            }
            int weight = generateEdgeWeight(negativeValues);
            //printf("Picked %d -> %d with value: %d\n", startNode, endNode, weight);
            toReturn -> insert(startNode, endNode, weight);
            if(twoWays){
                toReturn -> insert(endNode, startNode, weight);
            }
            lackingEdges--;
        }
    }
    return toReturn;

};

ListN * generateList(int size, int density, bool twoWays, bool negativeValues){
     if(density >= 100 || density < 0)
        throw "Wrong density!";
    ListN * toReturn = new ListN(size);

     //Creates minimal spanning tree
    for(int i = 0; i < size-1; i++){
        int weight = generateEdgeWeight(negativeValues);
        toReturn -> addEdge(i, i+1, weight);
        if(twoWays)
            toReturn -> addEdge(i+1, i, weight);
    }

    //Calculates density
    if(density == 99){
        int maxEdges = (size * (size - 1));
        if(twoWays) {
            maxEdges /= 2;
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == j)
                    continue;
                if(toReturn -> getEdgeWage(i, j) != 0)
                    continue;
                int weight = generateEdgeWeight(negativeValues);
                toReturn -> addEdge(i, j, weight);
                if(twoWays)
                    toReturn -> addEdge(j, i, weight);
            }
        }
        int edgesToRemove = maxEdges / 100 + 1;
        //printf("Max edges: %d\n", maxEdges);
        //printf("Edges to remove: %d\n", edgesToRemove);
        while(edgesToRemove > 0){
            int startNode = rand()%size;
            int endNode = rand()%size;
            if(startNode == endNode)
                continue;
            if(toReturn -> getEdgeWage(startNode, endNode) == 0)
                continue;
            //printf("Removing %d -> %d\n", startNode, endNode);
            toReturn -> addEdge(startNode, endNode, 0);
            if(twoWays)
                toReturn -> addEdge(endNode, startNode, 0);
            edgesToRemove--;
        }
    }
    else{
        int maxEdges = (size * (size - 1));
        if(twoWays) {
            maxEdges /= 2;
        }
        //printf("Max edges: %d\n", maxEdges);
        int lackingEdges = ((maxEdges * density) / 100) - size + 1;
    
        //printf("Lacking edges: %d\n", lackingEdges);
        while(lackingEdges > 0){
            int startNode = rand()%size;
            int endNode = rand()%size;
            if(startNode == endNode)
                continue;
            if(toReturn -> getEdgeWage(startNode, endNode) != 0){
                continue;
            }
            int weight = generateEdgeWeight(negativeValues);
            //printf("Picked %d -> %d with value: %d\n", startNode, endNode, weight);
            toReturn -> addEdge(startNode, endNode, weight);
            if(twoWays){
                toReturn -> addEdge(endNode, startNode, weight);
            }
            lackingEdges--;
        }
    }
    return toReturn;

};

int generateEdgeWeight(bool negativeValues){
    int toReturn = 0;
    int randomRange = 9;
    int randomMod = 1;
    if(negativeValues)
        randomMod -= 5;
    toReturn = rand()%randomRange + randomMod;
    if(toReturn == 0) 
        return generateEdgeWeight(negativeValues);
    return toReturn;
}
