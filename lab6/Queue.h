/* Lab 7
    Riley Battilla
    10/19/21
    Terror Park 
*/

#include <iostream>
#include <cstring>
using namespace std;

class terrorQueue
{
    private:
        struct QueueNode
        {
            string riderName; 
            struct QueueNode *next;
        };
        int numNodes;
        struct QueueNode *head;
        struct QueueNode *tail;
    
    public:
        terrorQueue()
        {
            head = NULL;
            tail = NULL;
            numNodes = 0;

        }
        void enqueue(string Title)
        {
            struct QueueNode *newNode = new QueueNode();

            newNode->riderName = Title;
            newNode->next = NULL;

            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            numNodes = numNodes + 1;
        }

        void dequeue()
        {
            if(isEmpty())
            {
                cout << "QUEUE IS EMPTY!" << endl;
                return;
            
            }
            else
            {
                cout << tail->riderName << " removed from Queue." << endl;
                
                if(tail = head)
                {
                    tail = NULL;
                    head = NULL;
                }
                else
                {
                    QueueNode* temp = head;

                    while(temp->next != tail)
                    {
                        temp = temp -> next;
                    }

                    temp->next = NULL;
                    tail = temp;
                }
                numNodes = numNodes - 1;

            }
        }
    bool isEmpty()
    {
        if(numNodes == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~terrorQueue()
    {
        struct QueueNode* temp = head;
        while(temp)
        {
            cout << "Oh shoot, I am sorry, our park is closed so " << temp->riderName << " will not get to ride today." << endl;
            temp = temp->next;
        }
    }
    
};

