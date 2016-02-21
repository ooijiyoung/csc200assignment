#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Supermarket.h"
#include <Windows.h>
#include "JiYoung.h"

const string VERSION = "2.0";

using namespace std;
JiYoung ojy;
Supermarket store; //global var in this file
int printMenu();

int main() {
	cout << fixed << showpoint << setprecision(2);
	for (;;) {
		printMenu();
	}
	ojy.getch();
	return 0;
}

int printMenu() {
	ojy.clrscr();
	cout << store.getStoreName() << " Sales System " << endl;
	cout << "1. Shop" << endl << "2. Display financal report" << endl << "3. Display stock report" <<endl;
	cout << "4. Stock Maintanace" <<endl << "5. Quit" << endl << "Enter Selection: "; 
	int selection; 
	cin >> selection; //Input Validation

	ojy.clrBuffer();

	switch (selection)
	{
	case 1:
		store.buyItem();
		break;
	case 2:
		store.finaceReport();
		break;
	case 3:
		store.stockReport();
		break;
	case 4:
		store.stockMaintance();//stock maintanace
		break;
	case 5:
		cout << "Press any key to exit";
		ojy.getch();
		exit(0);
		break;
	default:
		//cout << "Invalid Entry" << endl; -replace with popup Error Message 
		MessageBox(NULL, L"Invalid Entry\nPlease Try Again!", L"Error", MB_OK | MB_ICONERROR);
		return 0;
		break;
	}
	
	return selection;
}