#ifndef BSTSCANNER_H
#define BSTSCANNER_H
#include "BarcodeBST.h"
#include <fstream>
using namespace std;

//The BarcodeBstScanner class parses csv text files and stores each item's upc and name into a binary search tree(m_itemTree).
//It has one functionality that allows users to search for a specific item given the upc. The item's name will be print if found.

class BarcodeBstScanner
{
public:
	BarcodeBstScanner(string file);
	~BarcodeBstScanner();
	void searchItem(double upc);

private:
	BarcodeBst m_itemTree;

	//helper function
	bool isNumeric(string str);
};

#endif