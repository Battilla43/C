/* Lab 8
    Riley Battilla
    11/7/21
    read graph
*/

#include "GraphList.h"
#include <string>
#include <fstream>
#include <sstream>

int main()
{
    string graph;
    int b=0;
    ifstream myfile("graph.txt");
    if(myfile.is_open())
    {
        while(getline(myfile, graph))
        {
            stringstream graphLine(graph);
            graphLine >> b;
            cout << "There are 7 vertices in the graph\n\n";
            break;
        

        }
    }
    cout << "Add Adjacency List:\n";
    cout << GraphList::printGraph << endl;

    
    

}