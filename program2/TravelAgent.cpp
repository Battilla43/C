/* Riley Battilla
    program 2
    10/8/21
    Travel agent
*/

#include "LinkedList.h"
#include "destination.h"
#include <fstream>
#include <limits>

void dreamVacation();
LinkedList <Destination*> travelAgent;

int main()
{
    int choice;
    string name;
    string description;
    string cost;
    string danger;
    ifstream placeFile;
    int counter = 1;

    LinkedList <Destination*> travelAgent;
do
{
  cout << "Hello!! My name is Gavin O Cleirigh, and I will be YOUR professional travel agent today!" << endl;
                                                                                       
                                                                                                         
                                                                                
                                                                                
                                                                                
 cout <<  "                        ,###(%#%##(*         "    << endl;                                   
 cout <<  "                      *//###(/******/&#/     "    << endl;                              
 cout <<  "                      *#/..,,,,*********(#   "    << endl;                             
 cout <<  "                    *(*.,,,**//*/////***(#             "     << endl;                   
 cout <<  "                    //*,(%%%%%(*(%&&&%#/(##            "     << endl;                   
 cout <<  "                    (((,(/(##(,,*//((/***%(            "     << endl;                   
 cout <<  "                    ,#(.,,,,*,,((*****/**#(,           "     << endl;                   
 cout <<  "                    ,((.*,*//**(#//*/*//**#*           "     << endl;                   
 cout <<  "                     (/.,**/((#*///(%(*///*            "     << endl;                   
 cout <<  "                      ,,,**/**/((//**///(              "                << endl;        
 cout <<  "                        *////****/////((                         "      << endl;        
 cout <<  "                         ,*(((((#####((*                         "      << endl;        
 cout <<  "                         *//((####((//,                         "      << endl;        
 cout <<  "                        *     .(((((.    *,                      "      << endl;        
 cout <<  "                     ...*/.         .   .(//*,                .. "      << endl;        
 cout <<  "                ..,,,.,,**/   %#/../*#   ,//*/***,*,.         ......   "   << endl;     
cout <<  "*/*******,..,,,,,,,,*,****,*/,,..    ,..* .////*//******/***,,,*////////*,,,**//  "  << endl;
cout <<  "****,***,,***,***************,  .  ,. .  ..//*//**//*///////////////////////////  "  << endl;
cout <<  "***/*/(///***/*****/**********.  .   .,,  ./////////(/////(((((/(///////////////  "  << endl;
cout <<  "*/,*///#//**//*******/*********,   ..   . .////////(////////((#(#///////////////  "  << endl;
cout <<  "**,*/(((#///////*///*/(*/*//*/*/ ..   .. ..///////((/////((((##(((//////////////  "  << endl;
cout <<  "/,*/(((((#///(//*///*///(///////(   ..   ,*/((/(((((///(((((#%#((((////////////(  "  << endl;
cout <<  ",*/(((((#%#(((////////(//(//////(/,.   ., /(((((((/(((((((#(%%##((((((((((((((((  "  << endl;
cout <<  ",/(#(((###&#/(//(////((/(((//((((/*  ,.  *((((((#(((((((((##@%%##((#((%%#(((((((  "  << endl;
cout <<  "*/###((###%@(((((((((((((((/(((((/(*   .*/((((##(((##(((((#%@%%%%#((#((%#(((((((  "  << endl;
cout <<  "*(###((###%@%((((//(#(((((/((((#(/((..,.,((((##((((##(((((#@@&%%%%%#/#((((((((((  "  << endl;
cout <<  "*((#######%@@#(((((((((((((((((((#(((, .((((###(((########%@@&%%%%###(#(((((((((  "  << endl;
cout <<  "/(#######%%@@%(((((((((((((((((((((#((.*(/##(##((#########%@@&&&%%%%%###((((((((  "  << endl;
cout <<  "(####%%#%%%@@&###(((#(#(((((/#.(((((#%(//%#((##((#########(@@@&%%%%%#%##((((((((  "  << endl;
cout <<  "(####%%#%%%@@@%#(((((#(((#((*.....,##(#(###(###(###########(@@&&%%%#%%%%##((((((  "      << endl;                                                 


cout << "Would you like to find your dream vacation?! Enter 1 for yes, or 2 for no." << endl;
cin >> choice;
if(choice == 1)
{
    cout << "Lets get started!" << endl;
    cout << "Below are all the vacations listed." << endl;
    
    placeFile.open("placeFile");

    while(getline(placeFile, name, '#'))
    {
        getline(placeFile, description, '#');
        getline(placeFile, cost, '#');
        getline(placeFile, danger, '#');

        cout << "\n**********DESTINATION #" << counter << "**********" << endl;
        cout << "Place:     " << name << endl;
        cout << "Description:   " << description << endl;
        cout << "Cost to travel:    $" << cost << endl;
        cout << "Danger score   " << danger << endl;

        counter ++;

        cout << "I will now ask you some questions to find your dream vacation!" <<endl;
        void dreamVacation();

    }
}  
    return 0;
} 
while (choice == 2);
{
    cout << "GOODBYE!!!" << endl;
}



void dreamVacation();
{
    string name;
    float salary;
    char response1;
    char response2;
    int randNum;

    cout << "1. What is your name?" << endl;
    getline(cin, name);

    cout << "What is your salary?" << endl;
    cin >> salary;
    while(!cin)
    {
        cin.clear(); 
        
     cin.ignore(numeric_limits<streamsize>::max(),'\n');     
     cout << "Oops!  You entered something wonky.  Please enter your salary:  ";
     cin >> salary;
    }

    cout << "Do you enjoy cleaning?" << endl;
    cin >> response1;
    while(!cin)
    {
        cin.clear(); 
        
     cin.ignore(numeric_limits<streamsize>::max(),'\n');     
     cout << "Oops!  You entered something wonky.  Please enter your answer:  ";
     cin >> response1;
    }

    cout << "Do you enjoy videogames?" << endl;
    cin >> response2;
    while(!cin)
    {
        cin.clear(); 
        
     cin.ignore(numeric_limits<streamsize>::max(),'\n');     
     cout << "Oops!  You entered something wonky.  Please enter your answer:  ";
     cin >> response2;
    }

    randNum = rand() % 7 + 1;
    




    cout << "Have fun!" << endl;
}


