#include <string>
#include "Item.h"

using namespace std;

#ifndef _SUPERMARKET_
#define _SUPERMARKET_

class Supermarket {
private:
	string name; //store name
	double cash; //store cash
	int stock; //store stock
	Item item[100];
public:
	
	string getStoreName();
	double getStoreCash();
	int getStoreStock();
	
	//some method  DO NOT REMOVE
	void readFile(); //remove this soon, constructoor would read file 
	void buyItem();
	void finaceReport();

	Supermarket(); //constructor
	
};



#endif // _SUPERMARKET_

