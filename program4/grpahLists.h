/* Program 4
    Riley Battilla
    11/16/21
    depth first search of a graph
*/

#include <iostream>
using namespace std;

class GraphList
{
    private:
    struct listNode
    {
        int value;
        listNode* next;
    };
    listNode** headArray;
    int numVertices;
    int numEdges = 0;

    public:
    GraphList(int);
    ~GraphList();
    void addEdge(int, int);
    void printGraph();
    
};

GraphList::GraphList(int sizeV)
{
    numEdges = 0;
    numVertices = sizeV ;
    headArray = new listNode*[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        headArray[i] = new listNode [numVertices];
    }
    for(int i=0;i<numVertices;i++)
    {
        for(int j;j<numVertices;j++)
        {
            headArray[i][j].next = NULL;
            headArray[i][j].value = NULL;
        }
    } 
}

GraphList::~GraphList()
{   
    delete[] headArray;
}

void GraphList::addEdge(int verticeOne,int verticeTwo)
{
    listNode* node = new listNode;
    node->value = verticeTwo;
    node->next = NULL;

    headArray[verticeOne][verticeTwo].value = verticeOne;
    headArray[verticeOne][verticeTwo].next = node;
    numEdges += 1;
}  

void GraphList::printGraph()
{
    for(int i=0;i<numVertices;i++)
    {
        cout << i << "-->";
        
        for(int j=0;j<numVertices;j++)
        {
            cout << headArray[i][j].value << " ";
            if(headArray[i][j].next != NULL)
            {
                cout << headArray[i][j].next->value << "-->";
            }
        }
        cout << " NULL\n";
    }
}
