// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
using namespace std;


//przyk�adowa implementacja tablicy ale tylko jest TYLKO szkielet 

//normalnie ka�da klasa powinna zawiera� definicj� w pliku .h a implementacje metod w pliku .cpp


//staramy si� unika� u�ywania funkcji we/wy w klasie (op�cz metody  display)
//ta definicja klast Table powinna normalnie znajdowac si� w pliku .h np. table.h
class Table
{
	int *tab;
	int cnt; //ilo�� element�w w tablicy
public:
	
	Table(); //konstruktor - wywo�ywany automatycznie przy tworzeniu obieku
	~Table(); //destrukor - wyw�ywany automatycznie przy usuwaniu obiektu

	int loadFromFile(string FileName);
	
	bool IsValueInTable(int val);
	
	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);

};

//ta implementacja poni�ej powinna znajdowa� si� w pliku cpp np. table.cpp
Table::Table()
{
}

Table::~Table()
{
}

int Table::loadFromFile(string FileName)
{
	return 0;
}

bool Table::IsValueInTable(int val)
{
	return false;
}

void Table::addValue(int index, int value)
{
}

void Table::deleteFromTable(int index)
{
}

void Table::display()
{
}

void Table::generateTable(int size)
{
}






//w�a�ciwy program

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}



Table myTab; //myTab mo�e by� dynamiczna, mo�e byc takze zadeklarowana w manu_table albo tutaj jako zmienna globalna 

void menu_table()
{
	char opt;
	string fileName;
	int index, value;

	

	do{
		displayMenu("--- TABLICA ---");
		opt = getche();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazw� zbioru:";
			cin >> fileName;
			myTab.loadFromFile(fileName);
			myTab.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj index:";
			cin >> index;
			myTab.deleteFromTable(index);
			myTab.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waerto��:";
			cin >> value;

			myTab.addValue(index,value);
			myTab.display();			
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myTab.IsValueInTable(value))
				cout << "poadana wartosc jest w tablicy";
			else
				cout << "poadanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc element�w tablicy:";
			cin >> value;
			myTab.generateTable(value);
			myTab.display();
			break;

		case '6':  //tutaj wy�wietlanie tablicy
			myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
			      // mo�na sobie tu doda� w�asne dodatkowe case'y
			break;
		}

	} while (opt != '0');
}

void menu_list()
{
	 //analogicznie jak menu_table()
}

void menu_heap()
{
	//analogicznie jak menu_table()
}

int main(int argc, char* argv[])
{

	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";		
		option = getche();
		cout << endl;

		switch (option){
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;		
		}

	} while (option != '0');
	

	return 0;
}

