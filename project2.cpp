//#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <vector>

#include <cstddef>

/* Prints a standard container.
 *
 * This function is used to add the contents of a standard container to an
 * ostream. Each item in the container is added to the stream and seperated
 * using std::endl.
 *
 * @param os - the ostream the vector is copied to
 * @param container - the container to copy to the ostream
 * 
 * @return os
 * */
template <typename T, template<typename E, typename A=std::allocator<E> > class Container>
std::ostream& operator<< (std::ostream& os, const Container<T>& container);

/* Displays the useage message.
 *
 * This function displays the command line usage message on how to run the
 * program.
 *
 * @param name - the name of the program executable
 * */
void usage(char *name);

/* Unmerge Sort
 * 
 * This function accepts a sorted array of integers and rearranges them to
 * produce a worst-case input for merge sort. The "unsorting" is does in place.
 *
 * @param items - reference to the list of integers to be "unsorted"
 * */
void unmerge_sort(std::vector<int> &items);

/* Merge Sort
 *
 * This function sorts a std::vector of integers using merge sort. The sorting
 * is done in place. This function returns the number of comparisions made by
 * the algorithm.
 *
 * @param item - the vector to sort
 *
 * @return the number of key comparisons made by the algorithm.
 * */
size_t merge_sort(std::vector<int> &items);

/* Merge sort helper function.
 *
 * This function implements the merge sort algorithm and is called by the 
 * merge_sort function. It sorts the elements of items between [low,high) using
 * merge sort. The number of comparisons made is added to the count variable.
 *
 * @param item - the vector to sort
 * @param low - the beginning of the list to sort (inclusive)
 * @param high - the ending of the list to sort (exclusive)
 * @param count - a reference to a counter for the number of key comparisons made
 * */
void merge_sort_helper(std::vector<int> &items, size_t low, size_t high, size_t &count);

/* Merge sorted subarrays.
 * 
 * This function merges sorted subarrays as part of merge sort and is called
 * by the merge_sort_helper function. It is assumed the subarrays indexed from
 * [low1,high1) and [low2,high2) are already sorted. In addition, it is assumed
 * that high1 = low2 -1. The result of merging these two sorted subarrays is
 * stored in the range [low1,high2). The number of comparisons made by this
 * function are added to the count parameter.
 *
 * @param item - the vector containing the sorted subarrays
 * @param low1 - the beginning of the first sorted subarray (inclusive)
 * @param high1 - the ending of the first sorted subarray (exclusive)
 * @param low2 - the beginning of the second sorted subarray (inclusive)
 * @param high2 - the ending of the second sorted subarray (exclusive)
 * @param count - a reference to a counter for the number of key comparisons made
 * */
void merge_helper(std::vector<int> &items, size_t low1, size_t high1, size_t low2, size_t high2, size_t &count);






template <typename T, template<typename E, typename A=std::allocator<E> > class Container>
std::ostream& operator<< (std::ostream& os, const Container<T>& container) {
	typename Container<T>::const_iterator iter = container.begin();
	os << "[";
	while(iter != container.end()) {
		os << *iter;
		++iter;
		if(iter != container.end()) {
			os << " ";
		}
	}
	os << "]";
	return os;
}

void helper_unmerge(std::vector<int> &items, int start, int end);   // create helper function //

void unmerge_sort(std::vector<int> &items) {	// if items size is bigger than 1 then call helper function //
	/* IMPLEMENT THIS FUNCTION */
	if(items.size() > 1)
	{
		helper_unmerge(items, 0, items.size() - 1);
		
	}


}

void helper_unmerge(std::vector<int> &items, int start, int end) {

	if(start < end)        // if start is greater than end the function continues //
	{
		
		int m;
		int i;

		m = start + (end - start) / 2;       // finds middle of the function //

		std::vector<int> left(m - start + 1);    // creates left and right vectors //
		std::vector<int> right(end - m);

		for(int i = 0; i <= m - start; i++)  // splits vector apart // 
		{
			left[i] = items[i *2];
		}
		for(int i = 0; i < end - m; i++)
		{
			right[i] = items[i * 2 + 1];
		}

		helper_unmerge(left, start, m);
		helper_unmerge(right, m + 1, end);  // recursive //

		for(i = 0; i <= m - start; i++)        // joins vector back together //
		{
			items[i] = left[i];
		}
		for(int j = 0; j < end - m; j++)
		{
			items[i + j] = right[j];
		}



	}
	
}

void merge_helper(std::vector<int> &items, size_t low1, size_t high1, size_t low2, size_t high2, size_t &count) {
	/* copy the sorted subarrays into left and right */
	std::vector<int> left(items.begin()+low1, items.begin()+high1);
	std::vector<int> right(items.begin()+low2, items.begin()+high2);
	size_t ii=0, jj=0, kk=low1;
	while((ii < high1-low1) && (jj < high2-low2)) {
		/* a single comparison is made ever executeion of this loop */
		count++;
		if(left[ii] <= right[jj]) {
			items[kk++] = left[ii++];
		}
		else {
			items[kk++] = right[jj++];
		}	
	}
	/* no need to do an `if` to see which loop needs to be exeucted */
	while(ii < high1-low1) {
		items[kk++] = left[ii++];
	}
	while(jj < high2-low2) {
		items[kk++] = right[jj++];
	}
}

void merge_sort_helper(std::vector<int> &items, size_t low, size_t high, size_t &count) {
	/* nothing to sort unless there is more than 1 item */
	if(high-low > 1) {
		size_t low1 = low, high1 = (high-low)/2 + low;
		size_t low2 = high1, high2=high;
		merge_sort_helper(items, low1, high1, count);
		merge_sort_helper(items, low2, high2, count);
		merge_helper(items, low1, high1, low2, high2, count);
	}
}

size_t merge_sort(std::vector<int> &items) {
	size_t count = 0;
	/* call the merge_sort_helper function to do the real work */
	merge_sort_helper(items, 0, items.size(), count);
	return count;
}

void usage(char *name) {
	std::cout << "usage: ";
	std::cout << name << " [n_items]" << std::endl;
	std::cout << "  n_items - integer specifying the number of items to generate" << std::endl;
}

int main (int argc, char *argv[]) {
	int n_items;

	if(argc != 2) {
		std::cerr << "Invalid number of arguments." << std::endl << std::endl;
		usage(argv[0]);
		return -1;
	}
	
	std::istringstream iss(argv[1]);
	if((iss>>n_items).fail() || !iss.eof()) {
		std::cerr << argv[1] << " is not a valid integer." << std::endl << std::endl;
		usage(argv[0]);

		return -1;
	}   

	std::vector<int> items(n_items);
	std::iota(items.begin(), items.end(), 0);
	unmerge_sort(items);
	std::cout << items << std::endl;
	size_t n_comparisons = merge_sort(items);
	std::cout << n_comparisons << " comparison(s) required to sort" << std::endl;

	return 0;
}
