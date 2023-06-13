#include "bellmanFord.h"

int ** bellFordMatrix(MatrixN * matrix, int startNode){
    int size = matrix -> getDimension();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX/2;
        previous[i] = -1;
    } 
    distance[startNode] = 0;
    
  
    
    for(int i = 1; i < size; i++){
        bool change = false;
        for (int start = 0; start < size; start++){
            for (int end = 0; end < size; end++){
                if (start == end)
                    continue;
                int weight = matrix -> getEdgeWage(start, end);
                if( weight == 0)
                    continue;
                if(distance[end] > distance[start] + weight){
                    change = true;
                    distance[end] = distance[start] + weight;
                    previous[end] = start;
                }
            }
        }
        if(!change) break;
    }

    bool change = false;
    for (int start = 0; start < size; start++){
        for (int end = 0; end < size; end++){
            if (start == end)
                continue;
            int weight = matrix -> getEdgeWage(start, end);
            if( weight == 0)
                continue;
            if(distance[end] > distance[start] + weight){
                change = true;
                distance[end] = distance[start] + weight;
                previous[end] = start;
            }
        }
    }
    if(change) return nullptr;

    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;
    return toReturn;
}

int ** bellFordList(ListN * list, int startNode){
    int size = list -> getSize();
    int * distance = (int *)malloc(size * sizeof(int));
    int * previous = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        distance[i] = INT_MAX/2;
        previous[i] = -1;
    } 
    distance[startNode] = 0;


    for(int i = 1; i < size; i++){
        bool change = false;
        int start = 0;
        ListElementN * edge = list -> getList(0);
        ListElementN * weights = list -> getListWeight(0);
        while(start < size){
            if(edge == nullptr){
                start++;
                if(start >= size)
                    break;
                edge = list -> getList(start);
                weights = list -> getListWeight(start);
                continue;
            }
            int end = edge -> value;
            int weight = weights -> value;
            if(distance[end] > distance[start] + weight){
                change = true;
                distance[end] = distance[start] + weight;
                previous[end] = start;
            }
            if(edge -> next == nullptr){
                start++;
                if(start >= size)
                    break;
                edge = list -> getList(start);
                weights = list -> getListWeight(start);
                continue;
            }
            edge = edge -> next;
            weights = weights -> next;
        }
    
        if(!change) 
            break;
    }

    bool change = false;
    int start = 0;
    ListElementN * edge = list -> getList(0);
    ListElementN * weights = list -> getListWeight(0);
    while(start < size){
        if(edge == nullptr){
            start++;
            if(start >= size)
                break;
            edge = list -> getList(start);
            weights = list -> getListWeight(start);
            continue;
        }
        int end = edge -> value;
        int weight = weights -> value;
        if(distance[end] > distance[start] + weight){
            change = true;
            distance[end] = distance[start] + weight;
            previous[end] = start;
        }
        if(edge -> next == nullptr){
            start++;
            if(start >= size)
                break;
            edge = list -> getList(start);
            weights = list -> getListWeight(start);
            continue;
        }
        edge = edge -> next;
        weights = weights -> next;
    }

    if(change) 
        return nullptr;

  
    int ** toReturn = (int **)malloc(2 * sizeof(int *));
    toReturn[0] = previous;
    toReturn[1] = distance;
    return toReturn;
}