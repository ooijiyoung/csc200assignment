#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//TODO: EVERYTHING .......

// Supermarket implentation

string Supermarket::getStoreName() { return name; }
double Supermarket::getStoreCash() { return cash; }
int Supermarket::getStoreStock() { return stock; }

//readfile

/*
ifstream fileIn;
void Supermarket::readFile() {
	fileIn.open("Stock.txt");
	//POPULATE DATA HERE
	//TODO: Read Item to Store Name, and Item array
	fileIn.close();
}  GOING To BE REMOVED SOON
*/

void Supermarket::buyItem() {
	//TODO: item quantity --
}

void Supermarket::finaceReport() {
	//for array length itemprice * item quanitty
	//TODO: list store cash
}

Supermarket::Supermarket() {
	name = "NULL";
	cash = NULL;
	stock = NULL;
	ifstream fileIn;
	fileIn.open("Stock.txt");
	if (fileIn.is_open()) {

		cout << "File Open"; //DEBUG
		//TODO : Need to seperate the string and put into correct var =.= 
		string line;
		//First Line
		getline(fileIn, line, ':');//read name
		name = line;
		getline(fileIn, line, ':');//number of different items stocked 
		stock = stoi(line);
		getline(fileIn, line, ':');//cash on hand
		cash = stod(line);
		
		cout << "name= " << name << " stock= " << stock << " cash= " << cash << endl; //DEBUG TO BE REMOVED
		//end of first line

		int x = 0; //array need x 
		while (getline(fileIn, line)) { //Stock array - read until EOF
			item[x].setItemName(line);
			cout << item[x].getItemName();


		}
		
		//read into item array
	}
	else 
	{
		cout << "Something bad happened!"; //THROW NEW EXCEPTION
	}
	fileIn.close();
}

Supermarket::~Supermarket(){} //destructor