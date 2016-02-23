#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "JiYoung.h"
#define NOMINMAX
using namespace std;

extern JiYoung ojy;

// Supermarket implentation

string Supermarket::getStoreName() { return name; }
double Supermarket::getStoreCash() { return cash; }
int Supermarket::getStoreStock() { return stock; }

/*
//TODO: Least Priority
Better "SHOP" function.
allow to buy multiple item before return to menu
allow to enter quanitity to buy
*/

//Q: will buy item add cash to store cash?
//If yes, need to redesign a bit

void Supermarket::buyItem() { //Basic stuff might be completed. Need more testing
	//_PRINT MENU CALL FROM STOCK REPORT__
	ojy.clrscr();
	cout << name << " Shop" << endl << "Items in store" << endl;
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Price"; ojy.setw("Price", 10);
	cout << "Quantity"; cout << endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 14);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		if (item[x].getQuantity() == 0) {
			cout << "     Out Of Stock!";
		}
		cout << endl;
	}
	/// PENDING REMOVAL
	cout << "Press 0 (zero) to exit.\nEnter Selection To Purchase Item: ";
	int selBuy = NULL;
	int amount = NULL;
	bool isValidItem = false;
	while (isValidItem == false) {
		selBuy = ojy.isValidInt();
		if (selBuy > 0 && selBuy <= itemInStore) { //buy item
			if (item[selBuy - 1].getQuantity() == 0) {
				cout << "Item out of stock! No transection is made. Please retry later" << endl;
				break;
			}
			isValidItem = true;
			cout << "Enter the amount of items wanted :";
			amount = ojy.isValidInt();
			//after enter the amount, it needs to deduct the total quantity from the stock.txt
			cout << amount << " "<< item[selBuy - 1].getItemName() << " sold RM" << item[selBuy - 1].getPrice()*amount << endl;
			item[selBuy - 1].setQuantity(item[selBuy - 1].getQuantity() - amount);
			cash = cash + item[selBuy - 1].getPrice()*amount; 
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selBuy == 0) { //exit
			isValidItem = true; //exit and return to menu
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else{ //404
			cout << "Error 404 Item Not Found, Please Retry: ";
		}
	}//end while
}

void Supermarket::finaceReport() {
	//for array length itemprice * item quanitty
	//TODO: list store cash
	cout << cash << endl;
}

void Supermarket::stockReport() {
	ojy.clrscr();
	cout << name << " Shop" << endl << "Items in store" << endl;
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Quantity"; ojy.setw("Quantity", 12);
	cout << "Price"; ojy.setw("Price", 10); cout << "Weight"; ojy.setw("Weight", 10);
	cout << "Description" << endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		cout << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 14);
		cout << item[x].getWeight() <<"g";
		ojy.setw(to_string(item[x].getWeight()), 10);
		cout << item[x].getDescript();
		ojy.setw(item[x].getDescript(), 10);
		if (item[x].getQuantity() == 0) {
			cout << "-This item is out of stock!";
		}
		cout << endl;
	}
}

void Supermarket::stockMaintance() {
	ojy.clrscr();
	 
	cout << name << " Shop" << endl << "Items in store" << endl;
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Quantity"; ojy.setw("Quantity", 12); 
	cout << "Price"; ojy.setw("Price", 10); cout << "Weight"; ojy.setw("Weight", 10);
	cout << "Description"<< endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		cout << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 14);
		cout << item[x].getWeight();
		ojy.setw(to_string(item[x].getWeight()), 10);
		cout << item[x].getDescript();
		ojy.setw(item[x].getDescript(), 10);
		if (item[x].getQuantity() == 0) {
			cout << "     Out Of Stock!";
		}
		cout << endl;
	}
	cout << "Press 0 (zero) to exit.\nEnter Selection To Select Item: ";
	int selMain = NULL;
	int selEditItem = NULL;
	bool isValidItem = false;
	//After selecting the item it can choose which section to edit 
	//and from there enter the edited amount or info to replace the old data
	
	//TODO: print a menu to do - edit item or add new item or add stock - ojy
	cout << "1. Add New Item" << endl << "2. Edit Current Stock" << endl;

	while (isValidItem == false) {
		selMain = ojy.isValidInt();
		if (selMain == 1) { //Edit information of the items
			isValidItem = true;
			cout << "Enter the New Item's Name ";
			//Midway
			
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selMain == 2) {
			isValidItem = true;

			//Choose which specific information to edit
			ojy.getch();
		}
		else if (selMain == 0) { //exit
			isValidItem = true; //exit and return to menu
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else { //Invalid Input Message
			cout << "Error 404 Item Not Found, Please Retry: ";
		}
	}//end while
}

Supermarket::Supermarket() {
	name = "NULL";
	cash = NULL;
	stock = NULL;
	cout << "Please Wait.... Loading Data" << endl;
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
				getline(fileIn, line, '\n'); //eat newline
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
				cout << item[x].getPrice() << item[x].getQuantity() << item[x].getWeight() << item[x].getDescript() <<endl;
				x++;
			}
			itemInStore = x;
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