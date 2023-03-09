#include "menu.h"

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
                //TO BE ADDED FUNCTION FOR TABLE OPERATION
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
    cout << "1. Tablica" << endl
    << "2. Lista" << endl
    << "0. Wyjdź" << endl
    << "Wybierz opcję:" << endl;
}

void printSubMenu(string structureTypeName)
{
    //TO BE ADDED THE BASIC MENU FOR ANY STRUCTURE TYPE   
}