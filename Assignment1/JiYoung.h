#pragma once
#include <string>
using namespace std;

//JiYoung's Utility Class :P

#ifndef _JIYOUNG_
#define _JIYOUNG_
#undef max
class JiYoung {
	public:
		int isValidInt();
		double isValidDouble();
		void clrscr();
		void getch();
		void clrBuffer();
		void setw(string,int);
		void doNothing();
		string doubleToStrPrecis(double, int);

};

#endif // !_JIYOUNG_
