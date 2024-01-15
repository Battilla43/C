/* Riley Battilla
    program 2
    10/8/21
    Linked List
*/

#include <iostream>
using namespace std;

template <typename T> 
class LinkedList
{
    private: 
        struct ListNode
        {
            T value;
            ListNode *next;
        };
        ListNode *head;
        ListNode *tail;
        ListNode *numNodes;
    
    public: 
        LinkedList()
        {
            head = NULL;
            tail = NULL;
            numNodes = 0;
        }
        void ~LinkedList();
        int getLength();
        double getNodeValue(int position);
        void insertNode(int position, double num);


};

template <typename T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = head;
    while (nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}


template <typename T>
int LinkedList<T>::getLength()
{
    int numNodes = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr != tail)
	{
		numNodes++;
		nodePtr = nodePtr->next;
        if(numPtr == tail)
        {
            numNodes++
        }
	}
	return numNodes;
}

template <typename T>
double LinkedList<T>::getNodeValue(int position)
{
    ListNode *nodePtr;
    if(!head)
    {
        return -1
    }
        else
	{
		if(position == 0)
			return head->value;
		nodePtr = head;
		int currentSpot = 0;
		while(nodePtr != NULL && position >= currentSpot)
		{
			if(position == currentSpot)
				return nodePtr->value;
			currentSpot++;
			nodePtr = nodePtr->next;				
		}
	}
	return -1;
    
}

template <typename T>
void LinkedList<T>::insertNode(int position, double num)
{
    ListNode *nodePtr;
    ListNode *nextNode;

    newNode = new ListNode;
    newNode->value = num;

    if(!head)
    {
        if(position != 0)
        {
            cout << "OOPS! Cannot insert a node there! Try again." << endl;
        }
        head = newNode;
        tail = newNode;
    }
    else
    {
        nodePtr = head;
        int numNodes = 0;
        if(position == 0)
        {
            newNode->next = head->next;
			head = newNode;
        }
        while(nodePtr != tail && numNodes < position)
        {
            numNodes++;
			if(numNodes == position)
				break;
			nodePtr = nodePtr->next;
        }

        if(nodePtr->next == NULL)
        {
            tail = newNode;
        }

        newNode->next = nodePtr->next;
		nodePtr->next = newNode;
    }
}
