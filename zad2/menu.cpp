#include "menu.h"

ListN list[20];
MatrixN matrix[20];

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
    MatrixN matrix = MatrixN(std::stoi(sValue));
    ListN list = ListN(std::stoi(sValue));

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

        matrix.insert(startValue, endValue, valueValue);
        matrix.insert(endValue, startValue, valueValue);

        list.addEdge(startValue, endValue, valueValue);
        list.addEdge(endValue, startValue, valueValue);
    }
    inputFile.close();
    matrix.print();
    list.print();
}