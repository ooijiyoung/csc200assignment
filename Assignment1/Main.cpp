//#include JiYoung.h
//Ver 1.0
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Supermarket.h"
#include <Windows.h>

using namespace std;

Supermarket store; //global
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
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		cout << "Press any key to exit";
		system("pause>nul");
		exit(0);
		break;
	default:
		//cout << "Invalid Entry" << endl;
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