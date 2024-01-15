/* Pokemon.h
    Riley Battilla
    11/10/21
    Pokedex
*/

#include "BinaryTree.h"
#include <iomanip>

class Pokemon
{
    private:
    
        int numIndex;
        string name;

    public:
    Pokemon(string none = "None")
    {
        numIndex = 0;
        name = none;
    }
    void setId()
    {
        numIndex = 0;
    }
    void setName(string none)
    {
        name = none;
    }
    int getID()
    {
        return numIndex;
    }
    string getName(string none)
    {
        return name;
    }

    bool operator==(const Pokemon & right)const;

    friend ostream &operator << (ostream &strm, Pokemon &p)
    {
        strm << left << "Pokemon Index Number: " << setw(4) << p.numIndex << "\tName: " << p.name << endl;
            return strm; 
    }

    bool operator <(const Pokemon&p)
    {
        return numIndex < p.numIndex;
    }



};