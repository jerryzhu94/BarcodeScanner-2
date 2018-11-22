#include <iostream>
#include <time.h>
#include "BarcodeBSTScanner.h"
#include "BarcodeArrayScanner.h"
using namespace std;

//entry point of the program
int main(int argc, char* argv[])
{
	double upc;
	clock_t t1, t2; 

	//input csv to scanners
	BarcodeBstScanner bst(argv[1]);
	BarcodeArrayScanner arr(argv[1]);

	//prompt use to input upc
	cout << "UPC Code:";
	cin >> upc;

	//search and print using binary search tree
	t1 = clock();
	bst.searchItem(upc);
	t1 = clock() - t1;

	//search and print using array
	t2 = clock();
	arr.searchItem(upc);
	t2 = clock() - t2;

	//print execution time
	cout << "BST time: " << t1 << " miliseconds" << endl;
	cout << "Array time: " << t2 << " miliseconds" << endl;

	return 0;
}
