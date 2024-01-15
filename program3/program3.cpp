/* Program3.cpp
    Riley Battilla
    11/10/21
    Pokedex
*/

#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>
using namespace std;

int main()
{
    BinaryTree<string> Tree;

    ifstream pokedex;
    int index;
    string pokemon;
    int counter = 0;

    pokedex.open("pokedex");


    while(pokedex, index, '#');
    {

        getline(pokedex, pokemon, '#');
        index = stoi(pokemon);
        getline(pokedex, pokemon, '#');


        if(index = Tree.searchNode(pokemon))
        {
            cout << "OOPS! The pokemon with index " << index << " has already been entered.\n";
        }
        else if(!Tree.searchNode(pokemon))
        {
            Tree.insertNode(pokemon);
            cout << "Inserting pokemon with index number " << index << " into the PokeDex.\n";
        }

        counter++;
    }

    cout << "There are " << counter << " pokemon in the pokedex\n";
    cout << "\n**********POKEDEX**********\n";
    cout << "\n\n";

    while((cin, pokedex, index, '#'))
    {
        (cin, pokedex, index, '#');
        getline(pokedex, pokemon, '#');

        Tree.displayInOrder();

        cout << "Pokemon index number:  " << index << "Name: " << pokemon << endl;
        


    }





    Tree.~BinaryTree();



}

