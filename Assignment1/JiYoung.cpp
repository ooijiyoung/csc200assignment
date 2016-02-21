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
		clrBuffer();
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
	//system("cls");
	cout << endl << "CLRSCR IS TEMPORARY DISABLED FOR DEBUGGING PURPOSE" << endl;
}

void JiYoung::getch() {
	system("pause>nul");
}

//This method is to clear buffer to prevent garbage in next 
void JiYoung::clrBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void JiYoung::setw(string s, int i) {
	int len = i - s.length();
	for (int x = 1; x <= len; x++)
		cout << " ";
}