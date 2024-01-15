/* Lab 7
    Riley Battilla
    10/19/21
    Terror Park 
*/

#include "Queue.h"

int main()
{
    terrorQueue* fastPass = new terrorQueue();
    terrorQueue* normal = new terrorQueue();
    bool leave = true;
    
    while(leave)
    {
        int choice;
        cout << "1. Add rider" << endl;
        cout << "2. Remove rider" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                string title;
                int pass;
                cout << "Enter rider name: ";
                getline(cin,title);
                cout << "Select 1. Instant pass" << endl;
                cout << "Select 2. Normal pass" << endl;
                cin >> pass;
                if(pass == 1)
                {
                    fastPass->enqueue(title);
                }
                if(pass == 2)
                {
                    normal->enqueue(title);
                }
                break;
            }
            case 2:
            {
                if(fastPass->isEmpty() == true)
                {
                    normal->dequeue();
                }
                else
                {
                    fastPass->dequeue();
                }
                break;
            }
            case 3:
            {
                delete fastPass;
                delete normal;
                fastPass->~terrorQueue();
                normal->~terrorQueue();
            }
        }
    }
}