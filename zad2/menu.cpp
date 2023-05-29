#include "menu.h"

ListN * listN[20];
MatrixN * matrix[20];
int startingNode;

int main(){
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
            case 2:
                shortestPathOperations();
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
            loadFile(true);
            break;

            case 3:
            if(matrix != nullptr && matrix[0] != nullptr)
                matrix[0] -> print();
            else
                std::cout << "Brak macierzy sąsiadów\n";

            if(listN != nullptr && listN[0] != nullptr)
                listN[0] -> print();
            else
                std::cout << "Brak listy sąsiadów\n";
            break;

            case 4:
            primeAlgorithm();
            break;

            case 5:
            kruskalAlgoritm();
            break;
        }
    }

}

void shortestPathOperations(){
 short choice = -1;
    while(choice != 0){
        printSubMenu("Najkrótsza droga");
        std::cout << "4. Algorytm Djikstry\n"
        << "5. Alogrytm Bellmana-Forda\n"
        << "0. Wyjście\n"
        << "Wybór: ";
        std::cin >> choice;
        switch(choice){
            case 1:
            loadFile(false);
            break;

            case 3:
            if(matrix != nullptr && matrix[0] != nullptr)
                matrix[0] -> print();
            else
                std::cout << "Brak macierzy sąsiadów\n";

            if(listN != nullptr && listN[0] != nullptr)
                listN[0] -> print();
            else
                std::cout << "Brak listy sąsiadów\n";
            break;

            case 4:
            djikstraAlgorithm();
            break;

            case 5:
            bellmanFordAlgoritm();
            break;
        }
    }


}

void loadFile(bool isMst){


    std::cout << "Podaj ściezkę pliku: ";
    std::string pathName;
    std::cin >> pathName;

    std::ifstream inputFile;
    inputFile.open(pathName); 
    string sValue;

    std::getline(inputFile, sValue);
    string nodes= sValue.substr(sValue.find_first_of(' ') +1);
    if(!isMst){
        nodes = nodes.substr(0, nodes.find_last_of(' '));
    }


    if (matrix != nullptr && matrix[0] != nullptr){
        delete matrix[0];
        matrix[0] == nullptr;
    }
    if(listN != nullptr && listN[0] != nullptr){
        delete listN[0];
        listN[0] == nullptr;
    }

    matrix[0] = new MatrixN(std::stoi(nodes));
    listN[0] = new ListN(std::stoi(nodes));

    if(!isMst){
        string startingNodeS = sValue.substr(sValue.find_last_of(' ') + 1);
        if (startingNodeS.find('\r') != std::string::npos)
            startingNode = std::stoi(startingNodeS.substr(0, startingNodeS.length()-1));
    }

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
        if(isMst)
            matrix[0] -> insert(endValue, startValue, valueValue);

        listN[0] -> addEdge(startValue, endValue, valueValue);
        if (isMst)
           listN[0] -> addEdge(endValue, startValue, valueValue);
    }
    inputFile.close();
    matrix[0] -> print();
    listN[0] -> print();
}


void primeAlgorithm(){
    primeMatrix(matrix[0]);
    primeList(listN[0]);
}


void kruskalAlgoritm(){
    kruskalMatrix(matrix[0]);
    kruskalList(listN[0]);
}

void djikstraAlgorithm(){
    djikstraMatrix(matrix[0], startingNode);
    djikstraList(listN[0], startingNode);
}


void bellmanFordAlgoritm(){
    bellFordMatrix(matrix[0], startingNode);
};