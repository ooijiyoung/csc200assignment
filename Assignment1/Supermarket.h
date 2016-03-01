#pragma once
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
	int itemInStore; //how many item in the stock.txt
	Item item[100];
public:
	
	string getStoreName();
	double getStoreCash();
	int getStoreStock();
	
	//some method  DO NOT REMOVE
	void buyItem();
	void finaceReport();
	void stockReport();
	void stockMaintance();
	void listAllStock();
	void errormsg();
	Supermarket(); //constructor
	~Supermarket(); //desturctor 
};

#endif // _SUPERMARKET_

