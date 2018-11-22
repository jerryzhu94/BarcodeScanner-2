#include "BarcodeBSTScanner.h"

//BarcodeBstScanner class implementation

//constructor that takes in csv text file
BarcodeBstScanner::BarcodeBstScanner(string file)
{
	string upc, name;
	ifstream inFile;
	inFile.open (file);

	//parse csv file and inserts upc and name into m_itemTree
	while(getline(inFile, upc, ',') && getline(inFile, name, '\n'))
	{
		if(isNumeric(upc))
		{
			m_itemTree.insert(stod(upc), name);
		}
	}
	inFile.close();
}

//destructor
BarcodeBstScanner::~BarcodeBstScanner()
{

}

//search function
void BarcodeBstScanner::searchItem(double upc)
{
	//call BarcodeBst's search function
	m_itemTree.search(upc);
}

//isNumeric returns true if the entire string consists of only numbers (0-9).
bool BarcodeBstScanner::isNumeric(string str)
{
	string::iterator it = str.begin();
	for(it = str.begin(); it != str.end(); it++)
	{
		if((*it) < '0' || (*it) > '9')
			return false;
	}
	return true;
}