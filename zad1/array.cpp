#include "array.h"

class Array {
    private:
        short dataSize; 
        int dataQuantity;
        int * arrayStart;
        int arraySize;


    public:
        Array(int size){
            dataSize = 4;
            arraySize = size;
            arrayStart = (int*)calloc(size, dataSize);
            dataQuantity = size;
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
            ///std::cout << currentIndexPointer << std::endl;
            //std::cout << arrayStart << std::endl;
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
            //std::cout << currentIndexPointer << std::endl;
            //std::cout << arrayStart << std::endl;
            currentIndexPointer = nullptr;
            return true;
        }

        bool removeElementAt(int index){
            if (index >= arraySize) return false;
            int * currentIndexPointer = arrayStart+arraySize-1;
            //std::cout << currentIndexPointer << std::endl; 
            //std::cout << arrayStart << std::endl;
            int dataBuffor1 = 0;
            int dataBuffor2 = 0;
            dataBuffor1 = *currentIndexPointer;
            for (int i = 0; i < arraySize - index-1; i++){
                currentIndexPointer--;
                dataBuffor2 = *currentIndexPointer;
                *currentIndexPointer = dataBuffor1;
                dataBuffor1 = dataBuffor2;
            }
            //std::cout << currentIndexPointer << std::endl;
            //std::cout << arrayStart << std::endl;
            currentIndexPointer = nullptr;
            arraySize--;
            arrayStart = (int*)realloc(arrayStart, arraySize * dataSize); //ERROR!
            return true;
        }

};

int main(){
    Array newArray = Array(5);
    newArray.setValueAt(0,2);
    newArray.setValueAt(2,5);

    std::cout << newArray.valueAt(0) << std::endl;
    std::cout << newArray.valueAt(1) << std::endl;
    std::cout << newArray.valueAt(2) << std::endl;
    std::cout << newArray.valueAt(3) << std::endl;
    std::cout << newArray.valueAt(4) << std::endl << std::endl;

    newArray.addElementAt(5,3);
    std::cout << newArray.valueAt(0) << std::endl;
    std::cout << newArray.valueAt(1) << std::endl;
    std::cout << newArray.valueAt(2) << std::endl;
    std::cout << newArray.valueAt(3) << std::endl;
    std::cout << newArray.valueAt(4) << std::endl;
    std::cout << newArray.valueAt(5) << std::endl << std::endl;

    newArray.removeElementAt(5);

    std::cout << newArray.valueAt(0) << std::endl;
    std::cout << newArray.valueAt(1) << std::endl;
    std::cout << newArray.valueAt(2) << std::endl;
    std::cout << newArray.valueAt(3) << std::endl;
    std::cout << newArray.valueAt(4) << std::endl;
    std::cout << newArray.valueAt(5) << std::endl << std::endl;



    return 0;
}

