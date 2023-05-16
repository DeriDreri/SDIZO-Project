#include <stdlib.h>
#include<iostream>

class ListElement{
    public:
        ListElement* next;                                                     //Wskaźnik na następny element listy
        ListElement* prev;                                                     //Wskaźnik na poprzedni element listy
        int value;                                                              //Wartość elementu listy
        ListElement(ListElement * previous, int value, ListElement * next);     //Konstruktor przypisujący dwa powiązane elementy listy oraz wartość
};

class List{
    ListElement* head;              //Wskaźnik na głowę listy
    ListElement* tail;              //Wskaźnik na oogn listy
    public:
        /// @brief Pusty konstruktor tworzący listę o rozmiarze 1
        List();

        /// @brief Konstruktor tworzacy listę o podanym rozmiarze
        /// @param size Rozmiar tworzonej listy
        List(int size);

        /// @brief Wyświetla listę na domyślnym wyjściu używając dwustronnej strzałki jako separatora elementów
        void displayList();

        /// @brief Dodaje element na początek listy - dostępny publicznie, ale przede wszystkim używany przez klasę do egzekucji specjalnego przypadku dodawania
        /// @param value Wartość elementu dodawanego na początku listy
        /// @return potwierdzenie poprawnego dodania elementu do listy
        bool addAtStart(int value);

        /// @brief Dodaje element na koniec listy - dostępny publicznie, ale przede wszystkim używany przez klasę do egzekucji specjalnego przypadku dodawania
        /// @param value Wartość elementu dodawanego na końcu listy
        /// @return Potwierdzenie poprawnego dodania elementu do listy
        bool addAtEnd(int value);

        /// @brief Dodaje element o podanej wartości na podaną pozycję na liście. Obsługuje zasięg [0, rozmiar Listy]
        /// @param index Pozycja dodawanego elementu
        /// @param value Wartość dodawanego elementu
        /// @return Potwierdzenie bądź zaprzeczenie poprawnego dodania elementu
        bool addAt(int index, int value);

        /// @brief Zmienia wartość elementu na podanej pozycji na wprowadzoną wartość
        /// @param index Pozycja modufikowanego elementu
        /// @param value Nowa wartość elementu 
        /// @return Potwierdzenie bądź zaprzeczenie poprawnej modyfikacji elementu
        bool setValueAt(int index, int value);

        bool isEmpty();

        void removeStart();

        void removeEnd();

        int getSize();

        int valueAt(int position);

        bool removeAt(int index);
        /// @brief Usuwa pierwszy element o podanej wartości jeśli występuje w liście
        /// @param valueToRemove Wartość elementu to usunięcia
        /// @return Potwierdzenie bądź zaprzeczenie poprawnego usunięcia elementu
        bool removeElementOfValue(int valueToRemove);

        /// @brief Odnajduje w liście elemenet o zadanej wartości
        /// @param valueToFind Wartość elementu do odnalezienia w liście
        /// @return Wskaźnik na odnaleziony element. W przypadku braku elementu w liście zwaraca nullptr
        ListElement * findElementOfValue(int valueToFind);

};