/* Program 4
    Riley Battilla
    11/16/21
    depth first search of a graph
*/

#include "Stack.h"
#include "graphMatrix.h"
#include "grpahLists.h"
#include <fstream>
#include <string>
#include <sstream>

int main()
{

    int numVertex;
    int edgeOne, edgeTwo;
    int count;
    string fileName, item; 
    graphMatrix *matrix = NULL;
    GraphList *list = NULL;
    
    
    
    

    cout << "Enter the name of your file that contains the graph vertices: ";
    getline(cin, fileName);

    ifstream myfile(fileName);
    myfile.open(fileName);

    while(myfile.is_open())
    {
        count = 0;
        while(getline(myfile, item))
        {
            stringstream ss(item);
            if(count == 0)
            {
                ss >> numVertex;

                list = new GraphList(numVertex);
                matrix = new graphMatrix(numVertex);

                count = 1;
            }
            else
            {
                ss >> edgeOne;
                ss >> edgeTwo;
                list->addEdge(edgeOne,edgeTwo);
                matrix->addEdge(edgeOne,edgeTwo);



            }
        }
    }
    myfile.close();
    

    cout << "\nAdjacency Matrix...\n" << endl;
    matrix->printGraph();

    cout << "\n\n";

    cout << "Adjacency List...\n" << endl;
    list->printGraph();

    cout << "\n\n";

    cout << "Now traversing and printing graph vertices with DFS...\n";
    void DFS();
    

    matrix->~graphMatrix();
    list->~GraphList();



}

void DFS(int numVertex)
{
    Stack<int> stack;
    bool *visit = new bool[numVertex];

    for(int i=0;i<numVertex;i++)
    {
        if(visit[i] = false)
        {
            stack.push(numVertex);
            cout << numVertex;
    }   }
}
