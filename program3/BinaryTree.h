/* BinaryTree.h
    Riley Battilla
    11/10/21
    Pokedex
*/

#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    struct TreeNode
    {
        TreeNode* right;
        TreeNode* left;
        T value;
    };
    TreeNode* root;
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void destroySubTree(TreeNode *nodePtr);
    void displayInOrder(TreeNode *nodePtr) const;

public:
    BinaryTree()
    {
        root = NULL;
    }

    ~BinaryTree()
    {
        destroySubTree(root);
    }

    void insertNode(T item);
    bool searchNode(T item);

    void displayInOrder()
    {
        displayInOrder(root);
    }
    
};

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                 
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     
   else 
      insert(nodePtr->right, newNode);    
}

template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
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

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

template <class T>
bool BinaryTree<T>::searchNode(T item)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == item)
         return true;
      else if (item < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

template <typename T>
void BinaryTree<T>::insertNode(T item)
{
   TreeNode *newNode = nullptr;

   newNode = new TreeNode;
   newNode->value = item;
   newNode->left = newNode->right = nullptr;
   
   insert(root, newNode);
}



