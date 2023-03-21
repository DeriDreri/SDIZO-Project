#include "array.h"
#include <iostream>

class Array {
    private:
        int * arrayStart;                                           // Wskaźnik na początek tablicy, niezbędny do nawigacji po tablicy 
        int arraySize;                                              // Rejestr obecnego rozmiaru tablicy, uniemożliwiający przekroczenie zakresu i dokonanie niepożądanej operacji na pamięci


    public:

        //Konstruktor nieprzyjujmujący wartości generuje tablicę o rozmairze 0
        Array(){
            Array(0);
        }

        //Konstruktor z parametrem generuje tablice wypełnioną wartościami 0 o podanym rozmiarze
        //Parametry:
        //  size - rozmiar tworzonej tablicy
        Array(int size){
            arraySize = size;
            arrayStart = (int*)calloc(size, 4);
        }


        //Funckja pozwalająca uzyskać wartość w tablicy. 
        //Parametry:
        //      index - pozycja elementu w tablicy w zasięgu [0, arraySize-1]
        //Zwraca:
        //      int - wartość elementu tablicy
        //      out_of_range - żadana pozycja poza zasięgiem
        int valueAt(int index){
            if (index >= arraySize || index < 0)                    
                throw std::out_of_range("Index out of array's range"); 
            return *(arrayStart + index);                       
        }

        //Ustawia podaną wartość na indeksie
        //Parametry:
        //      index - pozycja modyfikowanego elementu
        //      value - nowa wartość elementu
        //Zwraca:
        //      true - udana zmiana wartości
        //      false - żadana pozycja poza zasięgiem tablicy
        bool setValueAt(int index, int value){
            if (index >= arraySize || index < 0) return false;      
            *(arrayStart + index) = value;
            return true;
        }


        //Dodaje element, zwiększa rozmiar tablicy i realokuje dane w pamięci
        //Dodaje na pocżątku tablicy dla index = 0
        //Dodaje na końcu tablicy dla index = arraySize
        //Parametry:
        //  index - pozycja, na którą element ma być dodany, dozwolny zasięg [0, arraySize]
        //  value - wartość dodwawanego elementu
        //Zwraca:
        //  true - pomyślnie dodano element
        //  false - próba dodania elementu poza zasięg 
        bool addElementAt(int index, int value){
            if(index > arraySize || index < 0) return false;

            arraySize++;
            arrayStart = (int*)realloc(arrayStart, arraySize);      // Zwiększa rozmiar tablicy o 1 i przenosi dane w nowe miesjce pamięci, rezerwując dodatkowe 4 bajty
            
            int * currentIndexPointer = arrayStart+index;;          // Przenosi wskaźnik na pozycję indeksu

            int dataBuffor1 = 0;
            int dataBuffor2 = 0;

            dataBuffor1 = *currentIndexPointer;                     
            *currentIndexPointer = value;                           // Zastępuje wartość na indeksie

            while(index < arraySize-1){                             // Pętla przepychająca wartości w górę tablicy, od indeksu w którym dodano element
                index++;
                currentIndexPointer++;
                dataBuffor2 = *currentIndexPointer;
                *currentIndexPointer = dataBuffor1;
                dataBuffor1 = dataBuffor2;
            }

            return true;
        }


        //Usuwa element na podanym indeksie, zmniejsza rozmiar tablicy i realokuje zmniejszony
        //blok danych, zwalaniając niepotrzebną pamięc
        //Parametry:
        //  index - pozycja elementu w tablicy w zasięgu [0, arraySize-1]
        //Zwraca:
        //  true - pomyślnie usunięto żądany element
        //  false - podana pozycja poza zasięgiem
        bool removeElementAt(int index){
            if (index >= arraySize || index < 0) return false;      

            int * currentIndexPointer = arrayStart+arraySize-1;    //Ustawia wskaźnik na ostatni element tablicy
            int dataBuffor1 = 0;
            int dataBuffor2 = 0;
            dataBuffor1 = *currentIndexPointer;

            for (int i = 0; i < arraySize - index-1; i++){         //Przepycha wartości w dół aż do osiągnięcia pozycji usuwanego elementu
                currentIndexPointer--;
                dataBuffor2 = *currentIndexPointer;
                *currentIndexPointer = dataBuffor1;
                dataBuffor1 = dataBuffor2;
            }

            arraySize--;                                            //Zmniejsza rozmiar tablicy o 1 i realokuje pamięć w bloku o nowym rozmiarze, 
            arrayStart = (int*)realloc(arrayStart, arraySize * 4);  //zwalaniając nadmiarową pamięć

            return true;
        }

        //Funckja wyświetlająca zawartość tablicy na standardowym wyjściu
        //Elementy tablicy wydzielone są przez nawiasy kwadratowe - []
        void displayArray(){
            int * dataPointer = arrayStart;
            for(int i = 0; i < arraySize; i++){
                std::cout << "[" << *dataPointer << "] ";
                dataPointer++;
            }
            std::cout << std::endl;
        }

        //Sprawdza, czy element o podanej wartości występuje w tablicy
        //Parametry:
        //  value - wartość szukanego elementu
        //Zwraca:
        //  true - element znalezony
        //  false - brak elementu w tablicy
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

    Array testArray = Array(0);
    testArray.addElementAt(0,5);
    testArray.addElementAt(0,4);
    testArray.addElementAt(0,3);
    testArray.addElementAt(0,2);
    testArray.addElementAt(0,1);
    testArray.removeElementAt(2);
    testArray.removeElementAt(10);
    testArray.setValueAt(4,10);
    testArray.displayArray();

    return 0;
}