#include <cstdlib>
#include <iostream>

class Array{
    int* arrayStart;       // Wskaźnik na początek tablicy, niezbędny do nawigacji po tablicy 
    int arraySize;          // Rejestr obecnego rozmiaru tablicy, uniemożliwiający przekroczenie zakresu i dokonanie niepożądanej operacji na pamięci

    public:
        /// @brief Konstruktor nieprzyjujmujący wartości generuje tablicę o rozmairze 0
        Array();

        /// @brief Konstruktor z parametrem generuje tablice wypełnioną wartościami 0 o podanym rozmiarze
        /// @param size Rozmiar tworzonej tablicy
        Array(int size);

        /// @brief Pobiera wartość elementu w tablicy. W przypadku przekroczenia zasięgu tablicy wyrzuca błąd out_of_range 
        /// @param index Pozycja elementu w tablicy w zasięgu [0, arraySize-1]
        /// @return Wartość elementu tablicy
        int valueAt(int index);

        /// @brief Ustawia podaną wartość na indeksie
        /// @param index Pozycja modyfikowanego elementu
        /// @param value Nowa wartość elementu
        /// @return Potwierdzenie lub przeczenie udanej zmiany wartości
        bool setValueAt(int index, int value);

        /// @brief Dodaje element, zwiększa rozmiar tablicy i realokuje dane w pamięci. Dla wartości 0 dodaje na początku tablicy, dla wartości równej rozmiarowi tablicy - na końcu.
        /// @param index Pozycja, na którą element ma być dodany, dozwolny zasięg [0, arraySize]
        /// @param value Wartość dodwawanego elementu
        /// @return Potwierdzenie lub przeczenie udanego dodania elementu
        bool addElementAt(int index, int value);

        /// @brief Usuwa element na podanym indeksie, zmniejsza rozmiar tablicy i realokuje zmniejszony blok danych, zwalaniając niepotrzebną pamięc
        /// @param index Pozycja elementu w tablicy w zasięgu [0, arraySize-1]
        /// @return Potwierdzenie lub przeczenie udanego usuniecia elementu
        bool removeElementAt(int index);

        /// @brief Wyświetla zawartość tablicy na standardowym wyjściu. Elementy tablicy wydzielone są przez nawiasy kwadratowe - []
        void display();

        /// @brief Sprawdza, czy element o podanej wartości występuje w tablicy
        /// @param value Wartość szukanego elementu
        /// @return Potwierdzenie bądź przeczenie znalezienia elementu
        bool findElement(int value);

        int getSize();
};