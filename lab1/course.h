/* Riley Battilla
    lab1
    2 February 2022
    course program
*/

#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string name;
    string location;
    string *sections;
    int numSections;
    int numHours;
};

Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

