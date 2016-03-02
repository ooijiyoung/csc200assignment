#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"

/*
Ver 2.0(final)
2 March 2016
Author: Ooi Ji Young, Low Chun Shiong
*/

using namespace std;

//Item method implentation
string Item::getItemName() { 
	return name; 
}
string Item::getDescript() { 
	return descript; 
}
int Item::getQuantity() { 
	return quantity; 
}
int Item::getWeight() { 
	return weight; 
}
double Item::getPrice() { 
	return price; 
}

//item setter 
void Item::setItemName(string n) {
	name = n;
}
void Item::setDescript(string d) {
	descript = d;
}
void Item::setPrice(double p) {
	price = p;
}
void Item::setQuantity(int q) {
	quantity = q;
}
void Item::setWeight(int w) {
	weight = w;
}

//print full details
void Item::printData() {
	cout << setprecision(2) << fixed << showpoint;
	cout << name << " has " << quantity << " units of " << descript << ", weight " << weight << "g, RM" << price;
}

//calculate the total value held in that item type.
double Item::calcTotalVal() {
	double totalPrice = price * static_cast<double>(quantity); 
	return totalPrice;
}
//constructor
Item::Item() {
	name = "NULL";
	descript = "NULL";
	quantity = NULL;
	weight = NULL;
	price = NULL;
}