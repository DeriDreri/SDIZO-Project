#include "kruskal.h"



void kruskalMatrix(MatrixN * matrix){
    int size = matrix -> getDimension();
    tree * subTrees = (tree *)malloc(size * sizeof(tree));
    for(int i = 0; i < size; i++){
        subTrees[i].node = i;
        subTrees[i].tree = i;
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
        if(findSet(edgesList[i].start, subTrees) == findSet(edgesList[i].end, subTrees))
            continue;
        finalEdgesList[counter] = {edgesList[i].start, edgesList[i].end, edgesList[i].value};
        treesUnion(edgesList[i].start, edgesList[i].end, subTrees, edgesNumber);
        counter++;
    }

    /*for (int i =0; i < size; i++){
        printf("[%d, %d]\n", subTrees[i].node, subTrees[i].tree);
    }*/

    int cost = 0;
    std::cout << "------ Macierzowo -----" << std::endl;
    for(int i = 0; i < counter; i++){
        printf("(%d, %d) : %d\n", finalEdgesList[i].start, finalEdgesList[i].end, finalEdgesList[i].value);
        cost += finalEdgesList[i].value;
    }
    std::cout << "Koszt całkowity: " << cost << std::endl;

    /*MatrixN newMatrix = MatrixN(size);
    for(int i = 0; i < counter; i++){
        newMatrix.insert(finalEdgesList[i].start,finalEdgesList[i].end, finalEdgesList[i].value);
        newMatrix.insert(finalEdgesList[i].end, finalEdgesList[i].start, finalEdgesList[i].value);
    }


    newMatrix.print();*/

    free(finalEdgesList);
    finalEdgesList = nullptr;
    free(subTrees);
    subTrees = nullptr;
}


int findSet(int node, tree * subTrees){
    return subTrees[node].tree;
}

void kruskalList(ListN * list){
    int size = list -> getSize();
    tree * subTrees = (tree *)malloc(size * sizeof(tree));
    for(int i = 0; i < size; i++){
        subTrees[i].node = i;
        subTrees[i].tree = i;
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
        if(findSet(edgesList[i].start, subTrees) == findSet(edgesList[i].end, subTrees))
            continue;
        finalEdgesList[counter]= {edgesList[i].start, edgesList[i].end, edgesList[i].value};
        treesUnion(edgesList[i].start, edgesList[i].end, subTrees, edgesNumber);
        counter++;
    }
    
    int cost = 0;
    std::cout << "------ Listowo -----" << std::endl;
    for(int i = 0; i < counter; i++){
        printf("(%d, %d) : %d\n", finalEdgesList[i].start, finalEdgesList[i].end, finalEdgesList[i].value);
        cost += finalEdgesList[i].value;
    }
    std::cout << "Koszt całkowity: " << cost << std::endl;

    /*ListN newList = ListN(size);
    for(int i = 0; i < counter; i++){
        newList.addEdge(finalEdgesList[i].start,finalEdgesList[i].end, finalEdgesList[i].value);
        newList.addEdge(finalEdgesList[i].end, finalEdgesList[i].start, finalEdgesList[i].value);
    }

    newList.print();*/

    free(finalEdgesList);
    finalEdgesList = nullptr;
    free(subTrees);
    subTrees = nullptr;
}

void treesUnion(int first, int second, tree * trees, int size){
    int change = trees[second].tree; 
    for (int i = 0; i < size; i++){
        if(trees[i].tree == change)
            trees[i].tree = trees[first].tree;
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
