/* Program 4
    Riley Battilla
    11/16/21
    depth first search of a graph
*/

#include "grpahLists.h"

class graphMatrix
{
    private:
        int** vertexMatrix;
        int numVertices;
        int numEdges;
    
    public:
        graphMatrix(int);
        ~graphMatrix();
        void addEdge(int, int);
        void printGraph();
        bool isThereAnEdge(int, int);

};

graphMatrix::graphMatrix(int sizeV)
{
    numVertices = sizeV;
    numEdges = 0;

    vertexMatrix = new int*[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            vertexMatrix[i][j] = 0;
        }
    }
}

graphMatrix::~graphMatrix()
{
    delete[] vertexMatrix;
}

void graphMatrix::addEdge(int vertexOne, int vertexTwo)
{
   
    vertexMatrix[vertexOne][vertexTwo] = 1;
    numEdges++;

}

void graphMatrix::printGraph()
{
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            if(vertexMatrix[i][j] == 1)
            {
                cout << 1 << " ";
            }
           else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

bool graphMatrix::isThereAnEdge(int row, int column)
{
    if(vertexMatrix[row][column] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}



