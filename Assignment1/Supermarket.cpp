#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
	ifstream fileIn;
	fileIn.open("Stock.txt");
	if (fileIn.is_open()) {
		cout << "File Open";
		//read first line (storeName and store details)
		string line;
		getline(fileIn, line); //THIS IS CONFUUSING
		cout << line;
		string itemname;
		fileIn >> itemname;
		item[0].setItemName(itemname);
		cout << item[0].getItemName();
		//read into item array
	}
	else 
	{
		cout << "Unable to open file \"Stock.txt\"! This program will be terminated";
	}
	fileIn.close();
}