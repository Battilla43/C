/* Lab 10
    Riley Battilla
    11/20/21
    min heap
*/
#include "Creature.h"
#include <iostream>
using namespace std;

class ArrayMinHeap
{
    private:
        Creature *heapArray;
        int capacity; 		
		int heap_size; 		
		
		void swap(int *x, int *y)
		{
			int temp = *x;
			*x = *y;
			*y = temp;
		}			
		
		int parent(int i) 			
		{ 
			return (i-1)/2; 
		}
		int left(int i) 			
		{ 
			return (2*i + 1); 
		}
		int right(int i) 	
		{ 
			return (2*i + 2); 
		}

        public:
        ArrayMinHeap(int capacity);	
		~ArrayMinHeap();		
		
		void minHeapify(int);		
		
	 	int peek() 					
		{ 
			if(isEmpty())
			{
				cout << "Error:  there are no nodes in the heap.\n";
				return -1;
			}
			else
				return heapArray[0]; 
		}
		
		int remove();				
		
		void insert(int);			
		
		void resizeArray();		

		void display();

		void saveToFile();	
		
		bool isEmpty()
		{
			if(heap_size == 0)
				return true;
			else
				return false;
		}
		
		int getNumberOfNodes()
		{
			return heap_size;
		}
		
		int getHeight()
		{
			return ceil(log2(heap_size + 1));
		}

		

};
 

ArrayMinHeap::ArrayMinHeap(int cap)			
{
	heap_size = 0;
	capacity = cap;
	heapArray = new int[cap];
}

ArrayMinHeap::~ArrayMinHeap()
{
	delete [] heapArray;
}
 
void ArrayMinHeap::insert(int newValue)
{
	if (heap_size == capacity)
	{
		resizeArray();
    }

	heapArray[heap_size] = newValue;
	heap_size++;
	int i = heap_size - 1;


	while (i != 0 && heapArray[parent(i)] > heapArray[i])
	{
		swap(&heapArray[i], &heapArray[parent(i)]);
		i = parent(i);
	}
}

void ArrayMinHeap::resizeArray()	
{
	int cap = capacity * 2; 
	int *newHeapArray = new int[cap];
	
	for(int x = 0; x < capacity; x++)
	{
		newHeapArray[x] = heapArray[x];
	}
	delete [] heapArray;
	heapArray = newHeapArray;
	capacity = cap;
}
 

int ArrayMinHeap::remove()
{
    if (heap_size == 0)
	{
		cout << "Error:  there is no nodes in the heap.\n";
		return -1;
	}
    else if (heap_size == 1)
    {
        heap_size--;
        return heapArray[0];
    }

    int root = heapArray[0]; 				
    heapArray[0] = heapArray[heap_size-1];
    heap_size--;							
    minHeapify(0);							
    return root;
}
 

void ArrayMinHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && heapArray[l] < heapArray[i])
        smallest = l;
    if (r < heap_size && heapArray[r] < heapArray[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&heapArray[i], &heapArray[smallest]);
        minHeapify(smallest);
    }
}

void ArrayMinHeap::display()
{
	for(int i=0;i<heap_size;i++)
	{								// I was not sure about these last two or zoo.cpp :(//
		cout << getName();
	}
}

void ArrayMinHeap::saveToFile()
{
	printCreatureToFile("savedCreatures.txt");
}

