#include "BarcodeArrayScanner.h"

//BarcodeArrayScanner class implementation

//constructor that takes in csv text file
BarcodeArrayScanner::BarcodeArrayScanner(string file)
{
	m_count = 0;
	string upc, name;
	ifstream inFile;
	inFile.open (file);

	//parse csv file and store upc and name into m_itemArray
	while(getline(inFile, upc, ',') && getline(inFile, name, '\n'))
	{
		if(isNumeric(upc))
		{
			m_itemArray[m_count].upc = stod(upc);
			m_itemArray[m_count].name = name;
			m_count++;
		}
	}
	inFile.close();
}
//destructor
BarcodeArrayScanner::~BarcodeArrayScanner()
{

}

//search function
void BarcodeArrayScanner::searchItem(double upc)
{
	//iterates through array
	for(int i = 0; i < m_count; i++)
	{
		if(m_itemArray[i].upc == upc)
		{
			cout << m_itemArray[i].name << endl;
			return;
		}
	}

	//print if item not found
	cout << "Item not found" << endl;

}


//isNumeric returns true if the entire string consists of only numbers (0-9).
bool BarcodeArrayScanner::isNumeric(string str)
{
	string::iterator it = str.begin();
	for(it = str.begin(); it != str.end(); it++)
	{
		if((*it) < '0' || (*it) > '9')
			return false;
	}
	return true;
}
