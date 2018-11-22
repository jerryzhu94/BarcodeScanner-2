#include "BarcodeBST.h"

//BarcodeBst class implementation

//default constructor
BarcodeBst::BarcodeBst()
{
	m_root = nullptr;
}

//destructor
BarcodeBst::~BarcodeBst()
{
	//call recursive delete function
	deleteTree(m_root);
}


//insert new TreeNode into BST
void BarcodeBst::insert(double upc, string name)
{
	//call recursive insert function
	insert(m_root, upc, name);
}

//recursive insert helper function
void BarcodeBst::insert(TreeNode*& node, double upc, string name)
{
	//base case: Empty tree or sub-tree
	if(node == nullptr)
	{
		//create new TreeNode and assign to node
		node = new TreeNode(upc, name);
		return;
	}

	//compare upc with node's upc
	//insert into left sub-tree
	if(upc < node->upc)
		insert(node->left, upc, name);
	//insert into right sub-tree
	else 
		insert(node->right, upc, name);
}

//search TreeNode with upc key and print out item's name
void BarcodeBst::search(double upc) 
{
	//call recursive search function to find TreeNode with upc
	TreeNode* targetNode = search(m_root, upc);
	if(targetNode == nullptr)
		cout << "Item not found" << endl;
	else
		cout << targetNode->name << endl;
}

//recursive search helper function
TreeNode* BarcodeBst::search(TreeNode* node, double upc)
{
	//base case: node not found.
	if(node == nullptr)
		return nullptr;
	//base case: node found
	if(upc == node->upc)
		return node;

	//compare upc with node's upc
	//search left sub-tree
	if(upc < node->upc)
		return search(node->left, upc);
	//search right sub-tree
	else 
		return search(node->right, upc);
}

//recursive delete
void BarcodeBst::deleteTree(TreeNode* node)
{
	//base case: Empty tree or sub-tree
	if(node == nullptr)
		return;
	//transverse left sub-tree
	deleteTree(node->left);
	node->left = nullptr;
	//transverse right sub-tree
	deleteTree(node->right);
	node->right = nullptr;
	//deallocate memory
	delete node;
}