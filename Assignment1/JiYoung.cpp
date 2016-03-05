#include "JiYoung.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

//Check if it's a valid integer value and prevent buffer garbage
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

//Check if it's a valid double value and prevent buffer garbage
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

//Clear whole screen 
void JiYoung::clrscr() {
	system("cls");
}

//getch function
void JiYoung::getch() {
	system("pause>nul");
}

//This method is to clear buffer to prevent garbage in next 
void JiYoung::clrBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//This method is to set the width of any line
void JiYoung::setw(string s, int i) {
	int len = i - s.length();
	for (int x = 1; x <= len; x++)
		cout << " ";
}
 
//This method is designed to do nothing at all
void JiYoung::doNothing() {
}

//Use to fix setprecision to string
string JiYoung::doubleToStrPrecis(double a, int n)
{
	ostringstream out;
	out << fixed << showpoint << setprecision(2) << a;
	return out.str();
}

//This method checks whether the input integer is bigger than zero(0)
int JiYoung::largerThanZeroInt() {
	int validInt;
	bool isValid = false;
	while (isValid == false) {
		validInt = isValidInt();
		if (validInt > 0) {
			isValid = true;
		}
		else {
			cout << "Invalid Entry, Please Retry: ";
		}
	}
	return validInt;
}

//This method checks whether the input double is bigger than zero(0)
double JiYoung::largerThanZeroDouble() {
	double validDouble;
	bool isValid = false;
	while (isValid == false) {
		validDouble = isValidDouble();
		if (validDouble > 0) {
			isValid = true;
		}
		else {
			cout << "Invalid Entry, Please Retry: ";
		}
	}
	return validDouble;
}