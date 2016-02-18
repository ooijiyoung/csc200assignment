//#include JiYoung.h
//Ver 1.0
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Supermarket.h"
#include <Windows.h>
#define NOMINMAX
using namespace std;

Supermarket store; //global var in this file
int printMenu();

int main() {

	int sel;
	do {
		sel = printMenu();
	} while (sel == 0);

	cout << sel << endl;
	system("pause");
	return 0;
}

int printMenu() {
	cout << store.getStoreName() << " Sales System " << endl;
	cout << "1. Shop" << endl << "2. Display financal report" << endl << "3. Display stock report" <<endl;
	cout << "4. Stock Maintanace" <<endl << "5. Quit" << endl << "Enter Selection: "; 
	int selection; 
	cin >> selection; //Input Validation

	cin.clear(); //clear buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer

	switch (selection)
	{
	case 1:
		store.buyItem();
		break;
	case 2:
		store.finaceReport();
		break;
	case 3:
		//stock report
		break;
	case 4:
		//stock maintanace /
		break;
	case 5:
		cout << "Press any key to exit";
		system("pause>nul");
		exit(0);
		break;
	default:
		//cout << "Invalid Entry" << endl; -replace with popup Error Message 
		MessageBox(NULL, L"Invalid Entry\nPlease Try Again!", L"Error", MB_OK | MB_ICONERROR);
		return 0;
		break;
	}
	
	/*
	try
	{
		int sel = stoi(selection); //stoi = Integer parseInt
	}
	catch (const std::exception&)
	{
		cout << "Unexpected Error Occured , std::invalid_argument" <<endl;
	}
	*/
	return selection;
}