/* Riley Battilla
    lab1
    2 February 2022
    course program
*/


#include "course.h"
#include <iostream>
#include <iomanip>

using namespace std;

Course* createCourse(string name, string location, int numSections, int numHours)
{
    Course* course = new Course;

    course->name = name;
    course->location = location;
    course->numSections = numSections;
    course->numHours = numHours;
    course->sections = new string[course->numSections];

    return course;

}
void destroyCourse(Course* myCourse)
{
    if(myCourse != NULL)
    {
        delete [] myCourse->sections;
        delete myCourse;
    }
}
void printCourse(Course* myCourse)
{
    if(myCourse != NULL)
    {
        cout << left << setw(5) << "Course Name:" << myCourse->name << endl;
        cout << left << setw(5) << "Course location:" << myCourse->location << endl;
        cout << left << setw(5) << "Course hours:" << myCourse->numHours << endl;
        cout << "Course sections:\n";
        for(int i=0; i<myCourse->numSections;i++)
        {
            cout << setw(5) << myCourse->sections[i];
        }
    }
}