#include "menu.h"

ListN ** list;
MatrixN ** matrix;

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
        switch(choice){
            case 1:
            loadMST();
            break;

            case 3:
            if(matrix != nullptr && matrix[0] != nullptr)
                matrix[0] -> print();
            else
                std::cout << "Brak macierzy sąsiadów\n";

            if(list != nullptr && list[0] != nullptr)
                list[0] -> print();
            else
                std::cout << "Brak listy sąsiadów\n";
            break;

            case 4:
            primeAlgorithm();
            break;
        }
    }

}

void loadMST(){


    std::cout << "Podaj ściezkę pliku: ";
    std::string pathName;
    std::cin >> pathName;

    std::ifstream inputFile;
    inputFile.open(pathName); 
    string sValue;

    std::getline(inputFile, sValue);
    sValue = sValue.substr(sValue.find_first_of(' ') +1);
    if (matrix == nullptr)
        matrix = (MatrixN **)malloc(sizeof(MatrixN *));
    if (matrix != nullptr && matrix[0] != nullptr)
        delete matrix[0];

    if (list == nullptr)
        list = (ListN **)malloc(sizeof(ListN *));
    if(list != nullptr && list[0] != nullptr) 
        delete list[0];

    matrix[0] = new MatrixN(std::stoi(sValue));
    list[0] = new ListN(std::stoi(sValue));

    string start, end, value;
    int startValue, endValue, valueValue;

    while(inputFile){
        std::getline(inputFile, sValue);

        start = sValue.substr(0, sValue.find_first_of(' '));
        end = sValue.substr(sValue.find_first_of(' ') + 1);
        end = end.substr(0, end.find_first_of(' '));
        value = sValue.substr(sValue.find_last_of(' ') + 1);
        if (value.find('\r') != std::string::npos)
            value = value.substr(0, value.length()-1);
        try{
            startValue = std::stoi(start);
            endValue = std::stoi(end);
            valueValue = std::stoi(value);
        }   
        catch(std::invalid_argument){
            break;
        }

        matrix[0] -> insert(startValue, endValue, valueValue);
        matrix[0] -> insert(endValue, startValue, valueValue);

        list[0] -> addEdge(startValue, endValue, valueValue);
        list[0] -> addEdge(endValue, startValue, valueValue);
    }
    inputFile.close();
    matrix[0] -> print();
    list[0] -> print();
}

void primeAlgorithm(){
    primeMatrix(matrix[0]);
    primeList(list[0]);
}


void kruskalAlgoritm(){
    return;
}