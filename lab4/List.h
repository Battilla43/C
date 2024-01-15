/* Riley Battilla
    lab4 header
    9/24/21
*/

#include <iostream>
#include <string>
using namespace std;


class List
{
    
    private:
    struct ListNode
    {
        string value;
        ListNode* next;

    };

    ListNode* Head;
    ListNode* Tail;

    public:
    List()
    {
        Head = NULL;
        Tail = NULL;
    }

    ~List();

    void appendNode(string);
    void insertNode(string);
    void deleteNode(string);
    void displayList();

};

void List::appendNode(string value)
{
    ListNode *newNode;

    newNode = new ListNode;
    newNode -> value;
    newNode -> next = NULL;

    if(!Head)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        Tail -> next = newNode;
        Tail = newNode;
    }
}

void List::insertNode(string value)
{
    ListNode *nodePointer;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->value = value;
	
	{
		nodePointer = Head;
		int nodeCount = 0;
		if(nodeCount == 0)
		{
			newNode->next = Head->next;
			Head = newNode;
		}
		while(nodePointer != Tail && nodeCount < nodeCount)
		{
			nodeCount++;
			if(nodeCount == nodeCount)
				break;
			nodePointer = nodePointer->next;
		}
		
		if(nodePointer->next == NULL)
			Tail = newNode;
			
		newNode->next = nodePointer->next;
		nodePointer->next = newNode;
		
	}
}

void List::deleteNode(string value)
{
    ListNode *nodePointer;       
	ListNode *previousNode;  
	if (!Head)
    {
		return;
    }

	if (Head -> value)
	{
		nodePointer = Head->next;
		delete Head;
		Head = nodePointer;
	}
	else
	{
		nodePointer = Head;

		while (nodePointer != NULL && nodePointer->value != value)
		{  
			previousNode = nodePointer;
			nodePointer = nodePointer->next;
		}

		if (nodePointer)
		{
			if(nodePointer == Tail)
			{
				Tail = previousNode;
			}
			previousNode->next = nodePointer->next;
			delete nodePointer;
		}
	}
}

void List::displayList()
{
    ListNode* nodePointer;

    if(Head != NULL)
    {
        nodePointer = Head;

        while(nodePointer != NULL)
        {
            cout << nodePointer -> value << endl;
        }
    }
    else{
        cout << "There are no more nodes in this list." << endl;
    }
}

List::~List()
{
    ListNode *nodePointer;
    ListNode *nextNode;

    nodePointer = Head;

    while(nodePointer != NULL)
    {
        nextNode = nodePointer -> next;

        delete nodePointer;
        nodePointer = nextNode;
    }

}