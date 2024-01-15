/* Lab 8
    Riley Battilla
    11/7/21
    functions
*/

#include <iostream>
using namespace std;

class GraphList
{
    private:
        struct listNode
        {
            int vertex;
            listNode* next;
        };

        listNode **headArray;
        int numVertices;
        int numEdges=0;

        public:
            GraphList(int vertices)
            {
                numVertices = vertices;
                headArray = new listNode*[numVertices];
                for(int i=0;i<numVertices;i++)
                {
                    headArray[i] = new listNode[numVertices];
                }
                for(int i=0;i<numVertices;i++)
                {
                    for(int t=0;t<numVertices;t++);
                    {
                    for(int t=0;t<numVertices;t++)
                    {
                     headArray[i][t].vertex = NULL;
                     headArray[i][t].next = NULL;
                    }
                    }
                }

            }

            ~GraphList()
            {
                for(int i=0;i<numVertices;i++)
                {
                    listNode*pointer = headArray[i];

                    listNode*node=nullptr;

                    while(pointer!=nullptr)
                    {
                        node=pointer;
                        pointer=pointer->next;
                        delete node;
                    }

                }
                delete[]headArray;
            }

            void addEdge(int vertexOne, int vertexTwo)
            {
                listNode*node = new listNode;
                node->vertex = vertexTwo;
                node->next = NULL;

                headArray[vertexOne][vertexTwo].vertex = vertexOne;
                cout << vertexOne << endl;
                headArray[vertexOne][vertexTwo].next = node;
                cout << headArray[vertexOne][vertexTwo].next->vertex << endl;
                numEdges += 1;

                

            }

            void printGraph()
            {
                for(int i=0;i<numVertices;i++)
                {

                    cout << i << "==>";

                    for(int t=0;t<numVertices;t++)
                    {
                        cout << headArray[i][t].vertex << "  ";
                        if(headArray[i][t].next != NULL)
                        {
                            cout << headArray[i][t].next << "==>";
                        }
                        
                        
                    }
                    cout << "null\n";
                }
            }


};