#include "menu.h"

int main()
{
    int choice;
    do{
        printMainMenu();
        std::cin >> choice;
        std::cout << std::endl;

        switch(choice)
        {
            case 1:
                mstOperations();
                break;
        };
    }
    while(choice);

    return 0;
}

void printMainMenu(){
    std::cout << "1. Wyznaczanie minimalnego drzewa rozpinającego\n"
    << "2. Wyznaczanie najkrótszej ścieżki w grafie\n"
    << "0. Wyjście\n" 
    << "Wybór: ";
}

void printSubMenu(string nameOfStructure){
    std::cout << "----------" << nameOfStructure << "----------\n"
    << "1. Wczytaj strukturę\n"
    << "2. Wygeneruj losowo\n"
    << "3. Wyświetl strukturę\n";
}

void mstOperations(){
    short choice = -1;
    while(choice != 0){
        printSubMenu("Minimalne drzewo rozpinające");
        std::cout << "4. Algorytm Prima\n"
        << "5. Alogrytm Kruskala\n"
        << "0. Wyjście\n"
        << "Wybór: ";
        std::cin >> choice;
    }

}