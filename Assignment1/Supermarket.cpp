#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#define NOMINMAX
using namespace std;

//TODO: EVERYTHING .......

// Supermarket implentation

string Supermarket::getStoreName() { return name; }
double Supermarket::getStoreCash() { return cash; }
int Supermarket::getStoreStock() { return stock; }

//readfile

/* REMOVE THIS SHIT
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
		try
		{
			while (!fileIn.eof()) { //Stock array - read until EOF
				getline(fileIn, line, ':'); //itemname
				item[x].setItemName(line);
				getline(fileIn, line, ':'); //number
				item[x].setQuantity(stoi(line));
				getline(fileIn, line, ':'); //unit price
				item[x].setPrice(stod(line));
				getline(fileIn, line, ':');//unit weight
				item[x].setWeight(stoi(line));
				getline(fileIn, line, ':');//unit descp
				item[x].setDescript(line);
				cout << item[x].getItemName(); //TODO: remove after done
				cout << item[x].getPrice() << item[x].getQuantity() << item[x].getWeight() << item[x].getDescript();
				x++;
			}
		}
		catch (const std::exception&)
		{
			MessageBox(NULL, L"Something wrong with \"Stock.txt\" file!", L"Error", MB_OK | MB_ICONERROR); //make sure last EOF dont have the ':'
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