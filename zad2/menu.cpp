#include "menu.h"
#define MEASURMENT_START 50
#define MEASURMENT_STEP 10

ListN * listN[50];
MatrixN * matrix[50];
int startingNode;
int nodesAmount;
int edgesAmount;


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
    << "3. Wyświetl strukturę\n"
    << "4. Pomiary\n";
}

void mstOperations(){
    short choice = -1;
    while(choice != 0){
        printSubMenu("Minimalne drzewo rozpinające");
        std::cout << "5. Algorytm Prima\n"
        << "6. Alogrytm Kruskala\n"
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
            mstData();
            break;
            
            case 5:
            primeAlgorithm();
            break;

            case 6:
            kruskalAlgoritm();
            break;

            default:
            break;
        }
    }

}

void shortestPathOperations(){
 short choice = -1;
    while(choice != 0){
        printSubMenu("Najkrótsza droga");
        std::cout << "5. Algorytm Djikstry\n"
        << "6. Alogrytm Bellmana-Forda\n"
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
            shortPathData();
            break; 

            case 5:
            djikstraAlgorithm();
            break;

            case 6:
            bellmanFordAlgoritm();
            break;

            default:
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
    string edges = sValue.substr(0, sValue.find_first_of(' '));
    edgesAmount = std::stoi(edges);

    string nodes= sValue.substr(sValue.find_first_of(' ') +1);
    if(!isMst){
        nodes = nodes.substr(0, nodes.find_last_of(' '));
    }
    nodesAmount = std::stoi(nodes);

    if (matrix != nullptr && matrix[0] != nullptr){
        delete matrix[0];
        matrix[0] == nullptr;
    }
    if(listN != nullptr && listN[0] != nullptr){
        delete listN[0];
        listN[0] == nullptr;
    }

    matrix[0] = new MatrixN(nodesAmount);
    listN[0] = new ListN(nodesAmount);

    if(!isMst){
        string startingNodeS = sValue.substr(sValue.find_last_of(' ') + 1);
        if (startingNodeS.find('\r') != std::string::npos)
            startingNodeS = startingNodeS.substr(0, startingNodeS.length()-1);
        startingNode = std::stoi(startingNodeS);
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
    int ** results = primeMatrix(matrix[0], nodesAmount);
   
    int counter = 0;
    printf("----- Macierzowo ------\n");
    for(int i = 0; i < nodesAmount; i++){
        if(results[1][i] == 0)
            continue;
        printf("(%d, %d) : %d\n", i, results[0][i], results[1][i]);
        counter+=results[1][i];
    }
    printf("Koszt całkowity: %d\n", counter);
    
    free(results[0]);
    results[0] = nullptr;
    free(results[1]);
    results[1] = nullptr;
    free(results);
    

    results = primeList(listN[0], nodesAmount);
    counter = 0;
     printf("----- Listowo ------\n");
    for(int i = 0; i < nodesAmount; i++){
        if(results[1][i] == 0)
            continue;
        printf("(%d, %d) : %d\n", i, results[0][i], results[1][i]);
        counter+=results[1][i];
    }
    printf("Koszt całkowity: %d\n", counter);
    

    free(results[0]);
    results[0] = nullptr;
    free(results[1]);
    results[1] = nullptr;
    free(results);
    results = nullptr;
}


void kruskalAlgoritm(){
    edge * finalEdgesList;
    finalEdgesList = kruskalMatrix(matrix[0], nodesAmount);
    int cost = 0;
    std::cout << "------ Macierzowo -----" << std::endl;
    for(int i = 0; i < nodesAmount-1; i++){
        printf("(%d, %d) : %d\n", finalEdgesList[i].start, finalEdgesList[i].end, finalEdgesList[i].value);
        cost += finalEdgesList[i].value;
    }
    std::cout << "Koszt całkowity: " << cost << std::endl;

    free(finalEdgesList);

    cost = 0;
    finalEdgesList = kruskalList(listN[0], nodesAmount);
    std::cout << "------ Listowo -----" << std::endl;
    for(int i = 0; i < nodesAmount-1; i++){
        printf("(%d, %d) : %d\n", finalEdgesList[i].start, finalEdgesList[i].end, finalEdgesList[i].value);
        cost += finalEdgesList[i].value;
    }
    std::cout << "Koszt całkowity: " << cost << std::endl;
    free(finalEdgesList);
    finalEdgesList = nullptr;
}

void djikstraAlgorithm(){
    // Algorytm tablicowy
    int ** results = djikstraMatrix(matrix[0], startingNode);
    // Wydruk
    printf(" --- Tablicowo ---\n");
    for (int i = 0; i < matrix[0] -> getDimension(); i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, results[1][currentNode]);
        printf("%d", currentNode);
        while(currentNode != startingNode){
            printf(" <- %d", results[0][currentNode]);
            currentNode = results[0][currentNode];
        }
        printf("\n");
    }

    // Czyści pamięć
    free(results[0]);
    results[0] = nullptr;
    free(results[1]);
    results[1] = nullptr;
    free(results);

    // Algorytm listowy
    results = djikstraList(listN[0], startingNode);
    // Wydruk
    printf("----- Listowo ------\n");
    for (int i = 0; i < listN[0] -> getSize(); i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, results[1][currentNode]);
        printf("%d", currentNode);
        while(currentNode != startingNode){
            printf(" <- %d", results[0][currentNode]);
            currentNode = results[0][currentNode];
        }
        printf("\n");
    }

    // Czyści pamieć
    free(results[0]);
    results[0] = nullptr;
    free(results[1]);
    results[1] = nullptr;
    free(results);
    results = nullptr;
}


void bellmanFordAlgoritm(){
    // Algorytm tablicowy
    int ** results = djikstraMatrix(matrix[0], startingNode);
    results = bellFordMatrix(matrix[0], startingNode);
    printf(" --- Tablicowo ---\n");
    for (int i = 0; i < matrix[0] -> getDimension(); i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, results[1][currentNode]);
        printf("%d", currentNode);
        while(currentNode != startingNode){
            printf(" <- %d", results[0][currentNode]);
            currentNode = results[0][currentNode];
        }
        printf("\n");
    }

    free(results[0]);
    results[0] = nullptr;
    free(results[1]);
    results[1] = nullptr;
    free(results);

    // Algorytm lista
    results = bellFordList(listN[0], startingNode, edgesAmount);
    printf("----- Listowo ------\n");
    for (int i = 0; i < listN[0] -> getSize(); i++){
        int currentNode = i;
        printf("%d : Koszt: %d\n", currentNode, results[1][currentNode]);
        printf("%d", currentNode);
        while(currentNode != startingNode){
            printf(" <- %d", results[0][currentNode]);
            currentNode = results[0][currentNode];
        }
        printf("\n");
    }

    free(results[0]);
    results[0] = nullptr;
    free(results[1]);
    results[1] = nullptr;
    free(results);
    results = nullptr;
};

void primeMatrixData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillArray(i, density, true, false);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            primeMatrix(matrix[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        fillArray(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            primeMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        fillArray(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            primeMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void primeListData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillList(i, density, true, false);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            primeList(listN[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        fillList(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            primeList(listN[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        fillList(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            primeList(listN[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void kruskalMatrixData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillArray(i, density, true, false);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalMatrix(matrix[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        fillArray(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        fillArray(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void kruskalListData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillList(i, density, true, false);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalList(listN[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        fillList(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalList(listN[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        fillList(i, density, true, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalList(listN[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void djikstraMatrixData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillArray(i, density, false, false);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalMatrix(matrix[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        fillArray(i, density, false, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        fillArray(i, density, false, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            kruskalMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void djikstraListData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillList(i, density, false, false);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            djikstraList(listN[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        fillList(i, density, false, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            djikstraList(listN[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        fillList(i, density, false, false);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            djikstraList(listN[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void bellFordMatrixData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        fillArray(i, density, false, true);
        auto start = std::chrono::high_resolution_clock::now();
        int edgeNumber = (i * (i - 1) * density) / 100; 
        for(int j = 0; j < 50; j++){
            bellFordMatrix(matrix[j], i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        edgeNumber = (i * (i - 1) * density) / 100; 
        fillArray(i, density, false, true);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            bellFordMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        edgeNumber = (i * (i - 1) * density) / 100; 
        fillArray(i, density, false, true);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            bellFordMatrix(matrix[j], i);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}

void bellFordListData(){
    for(int i = MEASURMENT_START; i < MEASURMENT_START + 7 * MEASURMENT_STEP; i += MEASURMENT_STEP){
        
        int density = 20;
        int edgeNumber = (i * (i - 1) * density) / 100; 
        edgeNumber++;
        fillList(i, density, true, true);
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            bellFordList(listN[j], i, edgeNumber);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time20 = (end - start) / 50;
        
        density = 60;
        edgeNumber = (i * (i - 1) * density) / 100;
        edgeNumber++; 
        fillList(i, density, true, true);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            bellFordList(listN[j], i, edgeNumber);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time60 = (end - start) / 50;
    
        density = 99;
        edgeNumber = (i * (i - 1) * density) / 100; 
        edgeNumber++;
        fillList(i, density, false, true);
        start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 50; j++){
            bellFordList(listN[j], i, edgeNumber);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time99 = (end - start) / 50;   

        printf("Dla %d wierzchołków: %d - %d - %d\n", i, time20, time60, time99);
        //std::chrono::high_resolution_clock::now();
    }
}


void mstData(){

    printf("-- Algorytm Kruskala - Macierzowo --\n");
    kruskalMatrixData();  
    printf("-- Algorytm Kruskala - Listowo --\n");
    kruskalListData();

    printf("-- Algorytm Prima - Listowo --\n");
    primeListData();
    printf("-- Algorytm Prima - Macierzowo --\n");
    primeMatrixData();
    
};
void shortPathData(){
    printf("-- Algorytm Bellmana-Forda - Listowo --\n");    
    bellFordListData();
    printf("-- Algorytm Bellmana-Forda - Macierzowo --\n");
    bellFordMatrixData();
    

    printf("-- Algorytm Djikstry - Macierzowo --\n");
    djikstraMatrixData();
    printf("-- Algorytm Djikstry - Listowo --\n");
    djikstraListData();

    
}

void clearArrays(){
    for (int i = 0; i < 50; i++){
        if (matrix[i] != nullptr){
            free(matrix[i]);
            matrix[i] = nullptr;
        }
        if(listN[i] != nullptr){
            free(listN[i]);
            listN[i] = nullptr;
        }
    }
}

void fillArray(int nodesNumber, int density, bool twoWays, bool negativeValues){
    for (int i = 0; i < 50; i++){
        if (matrix[i] != nullptr){
            free(matrix[i]);
            matrix[i] = nullptr;
        }
    }
    for (int i = 0; i < 50; i++)
        matrix[i] = generateMatrix(nodesNumber, density, twoWays, negativeValues);
}

void fillList(int nodesNumber, int density, bool twoWays, bool negativeValues){
    for (int i = 0; i < 50; i++){   
        if(listN[i] != nullptr){
            free(listN[i]);
            listN[i] = nullptr;
        }
    }
    for (int i = 0; i < 50; i++){
        listN[i] = generateList(nodesNumber, twoWays, negativeValues);
    }
}