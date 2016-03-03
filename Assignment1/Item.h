#pragma once
#include <string>
using namespace std;

/*
Ver 2.0(final)
2 March 2016
Author: Ooi Ji Young, Low Chun Shiong
*/

#ifndef _ITEM_
#define _ITEM_

//item class
class Item
{
private:
	string name,descript;//name and description
	int quantity,weight; //quantity and weight
	double price;//price
public:
	//getter
	string getItemName();
	string getDescript(); 
	int getQuantity();
	int getWeight();
	double getPrice();

	//setter
	void setItemName(string);
	void setDescript(string);
	void setQuantity(int);
	void setWeight(int);
	void setPrice(double);

	void printData();
	double calcTotalVal();
	
	//constructor
	Item();
	
};

#endif // !_ITEM_
