#include <iostream>
#include "array.cpp"
using namespace std;

void addToArray(Array *);

void printSubMenu(string structureTypeName)
{

    cout << "--------" << structureTypeName << "--------\n" 
    << "1. Zbuduj z pliku\n"
    << "2. Usuń\n"
    << "3. Dodaj\n"
    << "4. Znajdź\n"
    << "5. Utwórz losowo\n"
    << "6. Wyświetl\n" 
    << "0. Wróć\n"
    << "Wybierz opcję:\n";
}

void tableOperations(){
    int choice;
    do{
        Array mainArray = Array(1);
        printSubMenu("TABLICA");
        cin >> choice;

        switch(choice){
            case 1:
                
                break;

            case 3:
                addToArray(&mainArray);
                break;

            case 4:
                break;
            
            case 6:
                mainArray.displayArray();
                break;
        }

    }while(choice);


}

void addToArray(Array * mainArray){
    int index, valueToAdd;
    cout << "Podaj indeks:\n";
    cin >> index;
    cout << "Podaj wartość:\n";
    cin >> valueToAdd;
    if(mainArray -> addElementAt(index, valueToAdd))
    cout << "DONE!";
}

