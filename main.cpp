#include "shoppingList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
	//create shoppingList object sL1
	shoppingList sL1;

	//check if right file name is inputted
	cout << "Please enter the file name: ";
	sL1.fileExists(cin);

	cout << "(a) - add an item and its price" << endl;
	cout << "(i) - check to see if this item exists" << endl;
	cout << "(e) - print the most expensive item in the list" << endl;
	cout << "(p) - print all the items and its price" << endl;
	cout << "(q) - quit the program" << endl;

	char ch;
	cout << "Please select an option: ";
	cin >> ch;

	switch (tolower(ch)) {
	case 'a': 
		{
			//add Item to shopping list
			cout << "Enter item name and its price: ";
			sL1.addItem(cin);
		}
		break;
	case 'i':
		{
			cout << "Enter the item name: ";
			sL1.itemExist(cin);
		}
		break;
	case 'e':
		{
		//find the most expensive item
		sL1.printMostExpensiveItem();
		}
		break;
	case 'p':
		{
			//Print everything in the file formatted
			sL1.printAll();
		}
		break;
	case 'q':
		exit(1);
	default:
		cout << "Invalid input" << endl;
	}
	

	/*
	

	
	

	

	
	*/
}