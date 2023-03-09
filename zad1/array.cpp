#include "array.h"

class Array {
    private:
        short dataSize; 
        int dataQuantity;
        int * arrayStart;

    public:
        Array(int size){
            dataSize = 4;
            arrayStart = (int*)calloc(size, dataSize);
            dataQuantity = size;
        }
        ~Array();
};

