#include "shoppingList.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

shoppingList::shoppingList()
{
	file_name = "FileName";
	most_expensive_item = "Most_Expensive_Item";
	max_price = 0;
	name = "Name";
	price = 0;
}

bool shoppingList::fileExists(istream& in)
{
	string fName;
	in >> fName;
	file_name = fName;

	myFile.open(file_name);
	if (myFile.fail()) {
		cerr << "File cannot be opened.";
		exit(1);
	}
	else {
		cerr << "Successfully opens the target file!" << endl;
		return true;
	}
}

void shoppingList::printAll() 
{	
	int index = 1;
	while (!myFile.eof()) {
		myFile >> name >> price;
		cout << index << ". " << name << "\t\t\t$" << price << endl;
		index++;
	}
	myFile.seekg(0, ios::beg);
}

bool shoppingList::itemExist(istream& in) 
{
	string iName;
	in >> iName;
	while (!myFile.eof()) {
		myFile >> name >> price;
		if (iName.compare(name) == 0) {
			cout << "The item exists and it costs $" << price << endl;
			return true;
		}
	}
	cout << "This item does not exist" << endl;
	myFile.seekg(0, ios::beg);
}

void shoppingList::printMostExpensiveItem() 
{	
	myFile.seekg(0, ios::beg);
	max_price = 1;
	while (!myFile.eof()) {
		myFile >> name >> price;
		if (price > max_price) {
			most_expensive_item = name;
			max_price = price;
		}
	}
	
	cout << "The most expensive item is " << most_expensive_item << " and it costs $" << max_price << endl;
	myFile.seekg(0, ios::beg);
}

void shoppingList::addItem(istream& in) 
{
	myFile.close();
	myFile.open(file_name, ios::app);

	string item;
	double cost;
	in >> item >> cost;
	myFile << endl << item << " " << cost;
	myFile.close();
	myFile.open(file_name);
}