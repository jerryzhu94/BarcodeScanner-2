#ifndef BarcodeBST_H
#define BarcodeBST_H
#include <iostream>
#include <string>
using namespace std;

//The BarcodeBst class is a binary search tree that stores information about trade item's upc and name. 
//The upc field in the TreeNode struct acts as the key and the name field in the TreeNode acts as the value. 
//BarcodeBst has two functionalities: insert and search. The insert function adds a new TreeNode based on the TreeNode's upc.
//The search function will find the TreeNode with the inputted upc(key) and print out the name(value).

struct TreeNode
{
	TreeNode(double upc, string name)
	{
		this->upc = upc;
		this->name = name;
		this->left = nullptr;
		this->right = nullptr;
	}
	TreeNode* left;
	TreeNode* right;
	double upc;
	string name;
};


class BarcodeBst
{
public:
	BarcodeBst();
	~BarcodeBst();

	void insert(double upc, string name);
	void search(double upc);

private:
	TreeNode* m_root;

	//helper function
	void insert(TreeNode*& node, double upc, string name);
	TreeNode* search(TreeNode* node, double upc);
	void deleteTree(TreeNode* node);

};

#endif