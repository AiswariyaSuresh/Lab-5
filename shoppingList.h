#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class shoppingList {
private:
	string file_name;
	fstream myFile;
	string most_expensive_item;
	double max_price;
	string name;
	double price;

public:
	shoppingList();
	bool fileExists(istream& in);
	void addItem(istream& in);
	bool itemExist(istream& in);
	void printMostExpensiveItem();
	void printAll();
};
