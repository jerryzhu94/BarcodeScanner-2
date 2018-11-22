#ifndef ARRAYSCANNER_H
#define ARRAYSCANNER_H
#include <iostream>
#include <string>
#include <fstream>
#define MAX_SIZE 10000
using namespace std;

//The BarcodeArrayScanner class parses csv text files and stores each item's upc and name into an array of Item.
//The Item struct is essentially a key-value pair. upc is the key and name is the value.
//BarcodeArrayScanner has one functionality that allows users to search for a specific item given the upc. 
//The item's name will be print if found.

struct Item
{
	Item() { }
	Item(double upc, string name)
	{
		this->upc = upc;
		this->name = name;
	}
	double upc;
	string name;
};

class BarcodeArrayScanner
{
public:
	BarcodeArrayScanner(string file);
	~BarcodeArrayScanner();
	void searchItem(double upc);

private:
	Item m_itemArray[MAX_SIZE];
	int m_count;

	//helper function
	bool isNumeric(string str);
};

#endif
