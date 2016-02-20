#include "JiYoung.h"
#include <iostream>
using namespace std;

//This method is to check is it a valid Int Value , and prvent buffer garbage
int JiYoung::isValidInt() {
	string input;
	int validInt;
	bool isValid = false;
	while (isValid == false) {
		cin >> input;
		cin.clear(); //clear buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer
		try {
			validInt = stoi(input);
			isValid = true;
		}
		catch (std::exception) {
			cout << "Invalid Entry, Please Retry: ";
		}
	}
	return validInt;
}
//Check Double Value
double JiYoung::isValidDouble() {
	string input;
	double validDou;
	bool isValid = false;
	while (isValid == false) {
		cin >> input;
		cin.clear(); //clear buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer
		try {
			validDou = stoi(input);
			isValid = true;
		}
		catch (std::exception) {
			cout << "Invalid Entry, Please Retry: ";
		}
	}
	return validDou;
}

void JiYoung::clrscr() {
	system("cls");
}

void JiYoung::getch() {
	system("pause>nul");
}