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
	cout << store.getStoreName() << " Sales System " << endl << endl;
	cout << "1. Shop" << endl << "2. Display financal report" << endl << "3. Display stock report" <<endl;
	cout << "4. Stock Maintanace" <<endl << "5. Quit" << endl << "Enter Selection: "; 
	int selection;//The Selection of the menu 
	cin >> selection; //Input Validation
	
	ojy.charPrevention();
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
		store.stockMaintance();
		break;
	case 5:
		cout << "Thank you for choosing " + store.getStoreName() << endl;
		cout << "Press any key to exit" << endl;
		ojy.getch();
		exit(0);
		break;
	default:
		//print out popup Error Message 
		MessageBox(NULL, L"Invalid Entry\nPlease Try Again!", L"Error", MB_OK | MB_ICONERROR);
		return 0;
		break;
	}
	return selection;//return to the selection
}