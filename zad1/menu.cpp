#include "menu.h"


Array array[100];
List list[100];
Heap heap[100];
Tree tree[100];

int main()
{
    int choice;
    do{
        printMainMenu();
        cin >> choice;
        std::cout << endl;

        switch(choice)
        {
            case 1:
                arrayOperations();
                break;

            case 2:
                listOperations();
                break;

            case 3:
                heapOperations();
                break;
            case 4:
                treeOperations();
                break;
            

        };
    }
    while(choice);

    return 0;
}


void printMainMenu()
{
    std::cout << "1. Tablica\n"
    << "2. Lista\n"
    << "3. Kopiec\n"
    << "4. Drzewo AVL\n"
    << "0. Wyjście\n" 
    << "Wybór: ";
}

void printSubMenu(string nameOfStructure){
    std::cout << "----------" << nameOfStructure << "----------\n"
    << "1. Wczytaj strukturę\n"
    << "2. Wyświetl strukturę\n"
    << "3. Dodaj element\n"
    << "4. Usuń element\n"
    << "5. Znajdź element\n"
    << "6. Wygeneruj losowo\n"
    << "7. Pomiar - dodawanie\n"
    << "8. Pomiar - usuwanie\n"
    << "9. Pomiar - wyszukiwanie\n";   
}

void arrayOperations(){
    short choice = -1;
    while(choice != 0){
        printSubMenu("Tablica");
        std::cout << "0. Wyjście\n";
        std::cout << "Wybór: ";
        cin >> choice;

        switch(choice){
            case 1:
                arrayLoad();
                break;
            case 2: 
                array[0].display();
                break;
            case 3:
                arrayAddTest();
                break;
            case 4:
                arrayRemoveTest();
                break;
            case 5:
                arraySearchTest();
                break;
            case 6:
                arrayGenerate(0, 20);
                array[0].display();
                break;
            case 7:
                {
                    char subChoice;
                    std::cout << "Czy chcesz użyć domyślnych wartości pomiarowych? [y/n]: ";
                    std::cin >> subChoice;
                    std::cout << std::endl;
                    if(subChoice == 'y')      
                        arrayAdd(5000, 1000000, 10, 15);
                    else{
                        unsigned int minimalValue;
                        unsigned int maximumValue;
                        unsigned int steps;
                        unsigned int number;
                        std::cout << "Wybierz początkową ilość elementów w strukturze: ";
                        std::cin >> minimalValue;
                        std::cout << "Wybierz końcową ilość elementów w strukturze: ";
                        std::cin >> maximumValue;
                        std::cout << "Wybierz ilość pomiarów (max 100): ";
                        std::cin >> steps;
                        if (steps > 100)
                            steps = 100;
                        std::cout << "Wybierz ilość operacji równloległych: (max 100): ";
                        std::cin >> number;
                        if (steps > 100)
                            steps = 100;
                        arrayAdd(minimalValue,maximumValue,steps,number);
                    }
                    
                }break;
            case 8:
               {
                    char subChoice;
                    std::cout << "Czy chcesz użyć domyślnych wartości pomiarowych? [y/n]: ";
                    std::cin >> subChoice;
                    std::cout << std::endl;
                    if(subChoice == 'y')      
                        arrayRemove(5000, 1000000, 10, 15);
                    else{
                        unsigned int minimalValue;
                        unsigned int maximumValue;
                        unsigned int steps;
                        unsigned int number;
                        std::cout << "Wybierz początkową ilość elementów w strukturze: ";
                        std::cin >> minimalValue;
                        std::cout << "Wybierz końcową ilość elementów w strukturze: ";
                        std::cin >> maximumValue;
                        std::cout << "Wybierz ilość pomiarów (max 100): ";
                        std::cin >> steps;
                        if (steps > 100)
                            steps = 100;
                        std::cout << "Wybierz ilość operacji równloległych: (max 100): ";
                        std::cin >> number;
                        if (steps > 100)
                            steps = 100;
                        arrayRemove(minimalValue,maximumValue,steps,number);
                    }
                    
                }break;
            case 9:
                {
                    char subChoice;
                    std::cout << "Czy chcesz użyć domyślnych wartości pomiarowych? [y/n]: ";
                    std::cin >> subChoice;
                    std::cout << std::endl;
                    if(subChoice == 'y')      
                        arraySearch(5000, 1000000, 10, 15);
                    else{
                        unsigned int minimalValue;
                        unsigned int maximumValue;
                        unsigned int steps;
                        unsigned int number;
                        std::cout << "Wybierz początkową ilość elementów w strukturze: ";
                        std::cin >> minimalValue;
                        std::cout << "Wybierz końcową ilość elementów w strukturze: ";
                        std::cin >> maximumValue;
                        std::cout << "Wybierz ilość pomiarów (max 100): ";
                        std::cin >> steps;
                        if (steps > 100)
                            steps = 100;
                        std::cout << "Wybierz ilość operacji równloległych: (max 100): ";
                        std::cin >> number;
                        if (steps > 100)
                            steps = 100;
                        arraySearch(minimalValue,maximumValue,steps,number);
                    }
                    
                }break;
            default:
                break;           
        }
        std::cout << endl << endl;
    }

}

void listOperations(){
    short choice = -1;
    while(choice != 0){
        printSubMenu("Lista");
        std::cout << "0. Wyjście\n";
        std::cout << "Wybór: ";
        cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Wczytywanie";
                break;
            case 2: 
                std::cout << "Wyświetlanie";
                break;
            case 3:
                std::cout << "Dodawanie";
                break;
            case 4:
                std::cout << "Usuwanie";
                break;
            case 5:
                std::cout << "Szukanie";
                break;
            
            default:
                break;           
        }
        std::cout << endl << endl;
    }

}

void heapOperations(){
    short choice = -1;
    while(choice != 0){
        printSubMenu("Kopiec");
        std::cout << "0. Wyjście\n";
        std::cout << "Wybór: ";
        cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Wczytywanie";
                break;
            case 2: 
                std::cout << "Wyświetlanie";
                break;
            case 3:
                std::cout << "Dodawanie";
                break;
            case 4:
                std::cout << "Usuwanie";
                break;
            case 5:
                std::cout << "Szukanie";
                break;
            default:
                break;           
        }
        std::cout << endl << endl;
    }
    
}

void treeOperations(){
    short choice = -1;
    while(choice != 0){
        printSubMenu("Drzewo AVL");
        std::cout << "0. Wyjście\n";
        std::cout << "Wybór: ";
        cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Wczytywanie";
                break;
            case 2: 
                std::cout << "Wyświetlanie";
                break;
            case 3:
                std::cout << "Dodawanie";
                break;
            case 4:
                std::cout << "Usuwanie";
                break;
            case 5:
                std::cout << "Szukanie";
                break;
            default:
                break;           
        }
        std::cout << endl << endl;
    }
}

void arrayLoad(){
    array[0] = Array(0);
    std::ifstream arrayFile;
    arrayFile.open("data/tab1.txt");
    int i = 0;
    string sValue;
    int value;
    while(arrayFile){
        std::getline(arrayFile, sValue);
        try{
            value = std::stoi(sValue);
        }
        catch(std::invalid_argument){
            break;
        }
        array[0].addElementAt(i,value);
        i++;
    }
    arrayFile.close();
    array[0].display();
}

void arrayAddTest(){
    int index;
    int value;
    std::cout << "Podaj indeks: ";
    std::cin >> index;
    std::cout << std::endl << "Podaj wartość: ";
    std::cin >> value;
    if(array[0].addElementAt(index, value)){
        std::cout << std::endl << "Poprawnie dodano!" << std::endl;
        array[0].display();
    }
    else
        std::cout << std::endl << "Niepoprawne wartości!" << std::endl;
}

void arrayRemoveTest(){
    int index;
    int value;
    std::cout << "Podaj indeks: ";
    std::cin >> index;
    if(array[0].removeElementAt(index)){
        std::cout << std::endl << "Poprawnie usunięto!" << std::endl;
        array[0].display();
    }
    else
        std::cout << std::endl << "Niepoprawny indeks!" << std::endl;
}

void arraySearchTest(){
    int value;
    std::cout << "Podaj szukaną wartość: ";
    std::cin >> value;
    if(array[0].findElement(value))
        std::cout << "Element obecny w tablicy";
    else
        std::cout << "Brak elementu w tablicy";
};

void arrayGenerate(int arrayIndex, int arraySize){
    array[arrayIndex] = Array(0);
    int value;
    for (int i = 0; i < arraySize; i++){
        value = rand() % 10000;
        array[arrayIndex].addElementAt(i, value);
    }
}

void arrayAdd(int minimalElements, int maximumElements, int measurments, int arrayNumber){
    int step = (maximumElements - minimalElements) / (measurments);
    int currentElements = minimalElements;

    std::cout << "----Dodawanie na początku tablicy----\n";
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToAdd = rand()%100000;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(0, elementToAdd);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber<< "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements);
        }
        currentElements += step;
    }

    std::cout << "----Dodawanie w losowym miejscu tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToAdd = rand()%100000;
        int indexToAdd = rand()%currentElements;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(indexToAdd, elementToAdd);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements);
        }
        currentElements += step;
    }

    std::cout << "----Dodawanie na końcu tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToAdd = rand()%100000;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-1, elementToAdd);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements);
        }
        currentElements += step;
    }
}

void arrayRemove(int minimalElements, int maximumElements, int measurments, int arrayNumber){

    int step = (maximumElements - minimalElements) / (measurments);
    int currentElements = minimalElements;

    std::cout << "----Usuwanie z początku tablicy----\n";
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(0);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber<< "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-2, rand()%10000);
        }
        currentElements += step;
    }

    std::cout << "----Usuwanie losowego elementu tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int toRemove = rand()%currentElements;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(toRemove);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber<< "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-1, rand()%10000);
        }
        currentElements += step;
    }

    std::cout << "----Usuwanie z końca tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements-1);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-1, rand()%10000);
        }
        currentElements += step;
    }
}

void arraySearch(int minimalElements, int maximumElements, int measurments, int arrayNumber){
    int step = (maximumElements - minimalElements) / (measurments);
    int currentElements = minimalElements;

    std::cout << "----Szukanie losowego elementu w tabilicy---\n";
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToFind = rand()%100000;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].findElement(elementToFind);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        currentElements += step;
    }
};

void listLoad(){
    list[0] = List(0);
    std::ifstream listFile;
    listFile.open("data/tab1.txt");
    string sValue;
    int value;
    while(listFile){
        std::getline(listFile, sValue);
        try{
            value = std::stoi(sValue);
        }
        catch(std::invalid_argument){
            break;
        }
        list[0].addAtEnd(value);
    }
    listFile.close();
    list[0].displayList();
}

void listAddTest(){
    int index;
    int value;
    std::cout << "Podaj indeks: ";
    std::cin >> index;
    std::cout << std::endl << "Podaj wartość: ";
    std::cin >> value;
    if(list[0].addAt(index, value)){
        std::cout << std::endl << "Poprawnie dodano!" << std::endl;
        list[0].displayList();
    }
    else
        std::cout << std::endl << "Niepoprawne wartości!" << std::endl;
}

void listRemoveTest(){
    int value;
    std::cout << "Podaj wartość: ";
    std::cin >> value;
    if(list[0].removeElementOfValue(value)){
        std::cout << std::endl << "Poprawnie usunięto!" << std::endl;
        array[0].display();
    }
    else
        std::cout << std::endl << "Niepoprawny indeks!" << std::endl;
}

void listSearchTest(){
    int value;
    std::cout << "Podaj szukaną wartość: ";
    std::cin >> value;
    if(list[0].findElementOfValue(value))
        std::cout << "Element obecny w tablicy";
    else
        std::cout << "Brak elementu w tablicy";
};

void listGenerate(int listIndex, int listSize){
    list[listIndex] = List(0);
    int value;
    for (int i = 0; i < listSize; i++){
        value = rand() % 10000;
        list[listIndex].addAtEnd(value);
    }
}

void arrayAdd(int minimalElements, int maximumElements, int measurments, int arrayNumber){
    int step = (maximumElements - minimalElements) / (measurments);
    int currentElements = minimalElements;

    std::cout << "----Dodawanie na początku tablicy----\n";
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToAdd = rand()%100000;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(0, elementToAdd);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber<< "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements);
        }
        currentElements += step;
    }

    std::cout << "----Dodawanie w losowym miejscu tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToAdd = rand()%100000;
        int indexToAdd = rand()%currentElements;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(indexToAdd, elementToAdd);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements);
        }
        currentElements += step;
    }

    std::cout << "----Dodawanie na końcu tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToAdd = rand()%100000;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-1, elementToAdd);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements);
        }
        currentElements += step;
    }
}

void arrayRemove(int minimalElements, int maximumElements, int measurments, int arrayNumber){

    int step = (maximumElements - minimalElements) / (measurments);
    int currentElements = minimalElements;

    std::cout << "----Usuwanie z początku tablicy----\n";
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(0);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber<< "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-2, rand()%10000);
        }
        currentElements += step;
    }

    std::cout << "----Usuwanie losowego elementu tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int toRemove = rand()%currentElements;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(toRemove);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber<< "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-1, rand()%10000);
        }
        currentElements += step;
    }

    std::cout << "----Usuwanie z końca tablicy----\n";
    currentElements = minimalElements;
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].removeElementAt(currentElements-1);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        for(int i = 0; i < arrayNumber; i++){
            array[i].addElementAt(currentElements-1, rand()%10000);
        }
        currentElements += step;
    }
}

void arraySearch(int minimalElements, int maximumElements, int measurments, int arrayNumber){
    int step = (maximumElements - minimalElements) / (measurments);
    int currentElements = minimalElements;

    std::cout << "----Szukanie losowego elementu w tabilicy---\n";
    while(currentElements <= maximumElements){
        for(int i = 0; i < arrayNumber; i++)
            arrayGenerate(i,currentElements);
        int elementToFind = rand()%100000;
        auto begin = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < arrayNumber; i++){
            array[i].findElement(elementToFind);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << currentElements << " | "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() / arrayNumber << "ns" << std::endl;
        currentElements += step;
    }
};