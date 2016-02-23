#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"

/*
Ver 1.0
7 Feb 2016
Author: Ooi Ji Young
DO NOT MODIFY
*/

using namespace std;
//Item method implentation
string Item::getItemName() { return name; }
string Item::getDescript() { return descript; }
int Item::getQuantity() { return quantity; }
int Item::getWeight() { return weight; }
double Item::getPrice() { return price; }



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

void Item::printData() {
	cout << setprecision(2) << fixed << showpoint;
	cout << name << " has " << quantity << " units of " << descript << ", weight " << weight << "g, RM" << price;
}

double Item::calcTotalVal() {
	//A function to determine the total value held in that item type.
	double totalPrice = price * static_cast<double>(quantity); 
	return totalPrice;
}
//CONSTRUCTOR
Item::Item() {
	name = "NULL";
	descript = "NULL";
	quantity = NULL;
	weight = NULL;
	price = NULL;
}