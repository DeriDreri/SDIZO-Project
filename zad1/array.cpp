#include "array.h"
#include <iostream>

class Array {
    private:
        short dataSize; 
        int * arrayStart;
        int arraySize;


    public:
        Array(int size){
            dataSize = 4;
            arraySize = size;
            arrayStart = (int*)calloc(size, dataSize);
        }

        int valueAt(int index){
            if (index >= arraySize) return -999;
            int * currentIndexPointer = arrayStart;
            while(index > 0){
                currentIndexPointer++;
                index--;
            }
            return *currentIndexPointer;
        }

        bool setValueAt(int index, int value){
            if (index >= arraySize) return false;
            int * currentIndexPointer = arrayStart;
            while(index > 0){
                currentIndexPointer++;
                index--;
            }
            *currentIndexPointer = value;
            return true;
        }

        bool addElementAt(int index, int value){
            if(index > arraySize) return false;
            arraySize++;
            arrayStart = (int*)realloc(arrayStart, arraySize);
            int * currentIndexPointer = arrayStart+index;;
            int dataBuffor1 = 0;
            int dataBuffor2 = 0;
            dataBuffor1 = *currentIndexPointer;
            *currentIndexPointer = value;
            while(index < arraySize-1){ 
                index++;
                currentIndexPointer++;
                dataBuffor2 = *currentIndexPointer;
                *currentIndexPointer = dataBuffor1;
                dataBuffor1 = dataBuffor2;
            }
            currentIndexPointer = nullptr;
            return true;
        }

        bool removeElementAt(int index){
            if (index >= arraySize) return false;
            int * currentIndexPointer = arrayStart+arraySize-1;
            int dataBuffor1 = 0;
            int dataBuffor2 = 0;
            dataBuffor1 = *currentIndexPointer;
            for (int i = 0; i < arraySize - index-1; i++){
                currentIndexPointer--;
                dataBuffor2 = *currentIndexPointer;
                *currentIndexPointer = dataBuffor1;
                dataBuffor1 = dataBuffor2;
            }
            currentIndexPointer = nullptr;
            arraySize--;
            arrayStart = (int*)realloc(arrayStart, arraySize * dataSize); //ERROR!
            return true;
        }

        void displayArray(){
            int * dataPointer = arrayStart;
            std::cout << "-------TABLICA--------" << std::endl;
            for(int i = 0; i < arraySize; i++){
                std::cout << "[" << *dataPointer << "] ";
                dataPointer++;
            }
            std::cout << std::endl;
        }

        bool findElement(int value){
            int * dataPointer = arrayStart;
            for(int i = 0; i < arraySize; i++){
                if(*dataPointer == value) return true;
                dataPointer++;
            }
            return false;
        }

};

int main(){
    Array newArray = Array(1);
    newArray.addElementAt(1,2);
    newArray.addElementAt(1,2);
    newArray.addElementAt(1,2);
    newArray.addElementAt(1,2);
    newArray.addElementAt(1,2);
    newArray.displayArray();
    return 0;
}

