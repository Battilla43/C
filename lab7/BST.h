#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};
		treeNode* root;

		void copy(treeNode*&, treeNode*);
		void insert(treeNode*&, treeNode*);
		void displayInOrder(treeNode*) const;
		void destroySubTree(treeNode*);

	public:
		BST()
		{
			root = NULL;
		}			//default constructor
		BST(const BST &tree)
		{
			root = NULL;
		}	//copy constructor
		~BST()
		{
			destroySubTree(root);
		}

		void insertNode(int);
		void display();
};

void BST::copy(treeNode*&treeOrig, treeNode*parent)
{
	if(treeOrig == NULL)
	{
		return;
	}
	treeNode* newNode = new treeNode;
	newNode->value= treeOrig->value;
	newNode->parent = parent;

	newNode->left = copy(treeOrig->left, newNode);
	newNode->right = copy(treeOrig->right, newNode);
}
	
void BST::insert(treeNode*& nodePtr, treeNode* newNode)
{
	if (nodePtr = NULL)
	{
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value)
	{
		insert(nodePtr->left, newNode);
	}
	else
	{
		insert(nodePtr->right, newNode);
	}
}

void BST::displayInOrder(treeNode*nodePtr) const
{
	if (nodePtr)
	{
		cout << "Left is ";

		displayInOrder(nodePtr->left);

		cout <<"\nNode ";

		cout << nodePtr->value;

		cout <<"\nRight is ";

		displayInOrder(nodePtr->right);
	}
}

void BST::destroySubTree(treeNode*nodePtr)
{
	if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

void BST::insertNode(int digit)
{
	treeNode* newNode = NULL;	

	newNode = new treeNode;

   newNode->value = digit;
   
   newNode->left = newNode->right = NULL;
   
   insert(root, newNode);
}

void BST::display()
{
	void displayInOrder(treeNode*nodePtr);	
}

#endif