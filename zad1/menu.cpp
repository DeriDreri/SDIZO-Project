#include "menu.h"
#include "arrayMenu.cpp"

int main()
{
    int choice;
    do{
        printMainMenu();
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                tableOperations();
                cout << "Tablica" << endl; 
                break;

            case 2:
                //TO BE ADDED FUNCTION FOR LSIT OPERATION
                cout << "Lista" << endl;
                break;

        };
    }
    while(choice);

    return 0;
}


void printMainMenu()
{
    cout << "1. Tablica\n"
    << "2. Lista\n"
    << "0. Wyjdź\n" 
    << "Wybierz opcję:\n";
}



