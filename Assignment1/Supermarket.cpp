#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "JiYoung.h"
#define NOMINMAX
using namespace std;

extern JiYoung ojy;
//Assignment Progress 80% Complete  as 23 Feb 2016

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
void Supermarket::buyItem() { //Basic stuff might be completed. Need more testing
	
	ojy.clrscr();
	cout << name << " Shop" << endl  << endl << "Items in store" << endl << endl;
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Price"; ojy.setw("Price", 10);
	cout << "Quantity"; cout << endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu 
		//DO NOT CALL THE listAllStock FUNCTION, this menu is slightly differernt
		// I SAID DO NOT! 
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << "RM" << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 12);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		if (item[x].getQuantity() == 0) {
			cout << "     NOTE - Out Of Stock!";
		}
		cout << endl;
	}
	
	cout << "Press 0 (zero) to exit.\nEnter Selection To Purchase Item: ";
	int selBuy = NULL;
	int amount = NULL; //AMOUNT VALIDATION Done, need further testing
	bool isValidItem = false;
	bool amntCheckPass = false;
	while (isValidItem == false) {
		selBuy = ojy.isValidInt();
		if (selBuy > 0 && selBuy <= itemInStore) { //buy item
			if (item[selBuy - 1].getQuantity() == 0) {
				cout << "Item out of stock! No transection is made. Please retry later" << endl;
				break;
			}
			isValidItem = true;
			do {
				cout << "Enter the amount of items wanted :";
				amount = ojy.isValidInt();
				if (amount > item[selBuy - 1].getQuantity()) {
					cout << "Shop have only " << item[selBuy - 1].getQuantity() << " item left. Please enter value lower than available quanitity." << endl;
				}
				else if (amount < 0) {
					cout << "Amount cannot be negative." << endl;
				}
				else {
					amntCheckPass = true;
				}
			} while (amntCheckPass == false);
			//after enter the amount, it needs to deduct the total quantity from the stock.txt
			cout << amount << " "<< item[selBuy - 1].getItemName() << " sold RM" << item[selBuy - 1].getPrice()*amount << endl;
			item[selBuy - 1].setQuantity(item[selBuy - 1].getQuantity() - amount);
			cash = cash + item[selBuy - 1].getPrice()*amount; 
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selBuy == 0) { //Exit
			isValidItem = true; //Exit and return to menu
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else{ //Error message for invalid input
			cout << "Error 404 Item Not Found, Please Retry With a Different input: " << endl;
		}
	}//end while
}

void Supermarket::finaceReport() {//DONE
	ojy.clrscr();
	cout << name << " Financial Report" << endl << endl;
	double assetValue=0;
	for (int x = 0; x < itemInStore; x++) {
		assetValue = assetValue + (item[x].getQuantity() * item[x].getPrice());
	}
	//TODO: list store cash
	cout << "Total Stock Value: RM" << assetValue << endl;
	cout << "Available cash: RM" << cash << endl << endl;
	cout << "Total Combined Asset Value (Stock + Cash): RM" << cash + assetValue << endl;
	cout << "Press any key to return to menu";
	ojy.getch();
}

void Supermarket::stockReport() {
	ojy.clrscr();
	cout << name << " Stock Report" << endl;
	listAllStock();
	cout << "Press any key to return to menu";
	ojy.getch();
}

void Supermarket::stockMaintance() {
	ojy.clrscr();
	int selMain = NULL;
	int selEditItem = NULL;
	bool isValidItem = false;
	//After selecting the item it can choose which section to edit 
	//and from there enter the edited amount or info to replace the old data
	
	//TODO: print a menu to do - edit item or add new item or add stock - ojy
	cout << "Choose from these 2 selections" << endl;
	cout << "1. Add New Item" << endl << "2. Edit Current Stock" << endl;

	while (isValidItem == false) {
		selMain = ojy.isValidInt();
		if (selMain == 1) { //Edit information of the items
			isValidItem = true;
			string iName, iDesc;
			int iQuan;
			double iPrice, iWeight;
			//TODO : PRICE AND STOCK CANNOT BE LOWER THAN 0
			cout << "Enter the New Item's Name : ";
			getline(cin, iName);
			cout << "Enter the New Item's Quantity : ";
			iQuan = ojy.isValidInt();
			cout << "Enter the New Item's Price : ";
			iPrice = ojy.isValidDouble();
			cout << "Enter the New Item's Weight : ";
			iWeight = ojy.isValidDouble();
			cout << "Enter the New Item's Description : ";
			getline(cin, iDesc);
			string confirmItem;
			
			confirmItem = "Are you sure you want to add the following item?\nItem Name: " + iName + "\nItem Quantity: " + to_string(iQuan) + "\nItem Price: "
				+ ojy.doubleToStrPrecis(iPrice,2) + "\nItem Weight: " + ojy.doubleToStrPrecis(iWeight,2) + "\nItem Description: " + iDesc
				+ "\nNote: This Operation Could Not Be Undo";
			
			//convert String to LPCWSTR
						
			wstring To(confirmItem.begin(), confirmItem.end());
			LPCWSTR msgConfmMsg = To.c_str();

			
			int response= MessageBox(NULL, msgConfmMsg, L"WindowsTitle", MB_YESNO | MB_ICONQUESTION);
			//6 is yes , 7 is no
			if (response == 6) {
				// itemInStore is new Index Val
				item[itemInStore].setItemName(iName);
				item[itemInStore].setQuantity(iQuan);
				item[itemInStore].setWeight(iWeight);
				item[itemInStore].setPrice(iPrice);
				item[itemInStore].setDescript(iDesc);
				itemInStore++;
				MessageBox(NULL, L"The Operation Completed Sucessfully", L"Error", MB_OK | MB_ICONERROR);
			}
			else if(response==7){
				MessageBox(NULL, L"The Item is not added to the inventory", L"Information", MB_OK | MB_ICONINFORMATION);
			}
			else {
				cout << "This Wont Happen Just To Make Sure ";
			}
			
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selMain == 2) {
			isValidItem = true;
			listAllStock();
			//Choose which specific information to edit
			cout << "Enter the number for which you wish to edit the information of the item :" << endl;

			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selMain == 0) { //exit
			isValidItem = true; //exit and return to menu
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else { //Invalid Input Message
			cout << "Invalid Entry, Please Retry: ";
		}
	}//end while
}

void Supermarket::listAllStock() {
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Quantity"; ojy.setw("Quantity", 12);
	cout << "Price"; ojy.setw("Price", 10); cout << "Weight"; ojy.setw("Weight", 10);
	cout << "Description" << endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		cout << "RM" << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 12);
		cout << item[x].getWeight() << "g";
		ojy.setw(to_string(item[x].getWeight()), 9);
		cout << item[x].getDescript();
		ojy.setw(item[x].getDescript(), 10);
		if (item[x].getQuantity() == 0) {
			cout << " NOTE - This item is out of stock!";
		}
		cout << endl;
	}
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
				//cout << item[x].getItemName(); //TODO: remove after done
				//cout << item[x].getPrice() << item[x].getQuantity() << item[x].getWeight() << item[x].getDescript() <<endl;
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
//TODO: SAVE STOCK TO STOCK.TXT
Supermarket::~Supermarket(){} //destructor