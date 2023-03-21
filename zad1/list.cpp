#include "list.h"

ListElement::ListElement(ListElement * previous, int value, ListElement * nex){
    this -> prev = previous;
    this -> value = value;
    this -> next = nex;
}

List::List(){
    List(1);
}

List::List(int size){

    head = new ListElement(nullptr, 0, nullptr);                    //Tworzy głowę
    ListElement* current = head;

    for(int i = 1; i < size; i++){                                  //Pętla tworzy elementy powiązane z poprzednim elementem i wiąże poprzedni element z tworzonym
        current -> next = new ListElement(current, 0, nullptr);
        current = current -> next;
    }
    tail = current;                                                 //Ustawienei ostatniego elementu na ogon
}

void List::displayList(){
    ListElement* currentPointer = head;
    while(currentPointer -> next != nullptr){                           
        std::cout << currentPointer -> value << " <-> ";
        currentPointer = currentPointer -> next;
    }
    std::cout << currentPointer -> value << std::endl << std::endl;     //Ostatni element wyświetlany osobno z powodu niepożądania występowania "<->" po nim 
}

bool List::addAtStart(int value){
    head -> prev = new ListElement(nullptr, value, head);
    head = head -> prev;
    return true;
}

bool List::addAtEnd(int value){
    tail -> next = new ListElement(tail, value, nullptr);
    tail = tail -> next;
    return true;
}

bool List::addAt(int index, int value){
    if (index < 0) return false;                        //Wykrywa niedozwoloną pozycję
    ListElement* currentPointer = head;
    while(index > 0){                               

        if(currentPointer -> next == nullptr) {         //Wykrywa dotarcie do końca listy  
            if(index == 1)                              //Sprawdza, czy osiągnięto żądaną pozycję
                return addAtEnd(value);                 //Wywołuje dodanie na końcu

            return false;
        }
        
        currentPointer = currentPointer -> next;        //Przechodzi do kolejnego elementu listy i zmiejsza zmienną iteracji
        index--;
    }

    if(currentPointer == head) 
        return addAtStart(value);


    currentPointer -> prev -> next = new ListElement(currentPointer -> prev, value, currentPointer);    //Tworzy nowy element listy i przyłącza do porzedniego elementu
    currentPointer -> prev = currentPointer -> prev -> next;                                            //Przyłącza dodany element do elementu wkazywanego przez   
    return true;
}

bool List::setValueAt(int index, int value){
    if(index < 0) return false;                                      //Wykrywa niedozwoloną pozycję

    ListElement* currentPointer = findElementOfValue(value);
    if  (currentPointer == nullptr) return false;
    
    currentPointer -> value = value;
    return true;
}

bool List::removeElementOfValue(int valueToRemove){

    ListElement* currentPointer = findElementOfValue(valueToRemove);
    if(currentPointer == nullptr) return false;

    if(currentPointer == head){                                     //Inicjaluzuje usuwanie głowy i wychodzi z funkcji przy ukończeniu
        head -> next -> prev = nullptr;
        head = head -> next;
        free(currentPointer);
        return true;
    }

    if(currentPointer == tail){                                     //Inicjalizuje usuwanie ogona i wychodzi z funkcji przy ukończeniu
        tail -> prev -> next = nullptr;
        tail = tail -> prev;
        free(currentPointer);
        return true;

    }

    currentPointer -> next -> prev = currentPointer -> prev;       //Inicjalizuje zmianę w środku listy przy braku wykrycia skrajnych przypadków
    currentPointer -> prev -> next = currentPointer -> next;

    free(currentPointer);
    return true;
}

ListElement * List::findElementOfValue(int valueToFind){
    ListElement* currentPointer = head;
        while(true){
            if(currentPointer -> value == valueToFind) return currentPointer; 
            if(currentPointer == tail) return nullptr;                              //Przy osiągnieciu ogona funkcja zwraca pusty wskaźnik
            currentPointer = currentPointer -> next;
        }
}