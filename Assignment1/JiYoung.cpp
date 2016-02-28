#include "JiYoung.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

//This method is to check is it a valid Int Value , and prvent buffer garbage
int JiYoung::isValidInt() {
	string input;
	int validInt;
	bool isValid = false;
	while (isValid == false) {
		cin >> input;
		clrBuffer();
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
			validDou = stod(input);
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

 
//This method is designed to do nothing at all
void JiYoung::doNothing() {
}

string JiYoung::doubleToStrPrecis(double a, int n)
{
	ostringstream out;
	out << fixed << showpoint << setprecision(2) << a;
	return out.str();
}
