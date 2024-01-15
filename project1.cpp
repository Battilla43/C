#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <cstddef>
#include <cstring>

/* edge_t.
 *
 * Vertices will be stored as a std::size_t. This typedef has been added
 * for convenience.
 * */
typedef std::size_t vertex_t;

/* edge_t.
 *
 * Edges read in from the graph file will be stored as ordered pairs in a
 * std::pair<vertex_t,vertex_t>. This typedef has been added for convenience.
 * */
typedef std::pair<vertex_t,vertex_t> edge_t;

/* Prints an edge_t.
 *
 * This function is used to add an edge_t to an ostream. The edge is
 * printed in the form "pt.first -> pt.second".
 *
 * @param os - the ostream the edge is copied to
 * @param edge - the edge_t to copy to the ostream 
 * */
std::ostream & operator<<(std::ostream &os, const edge_t &edge);

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

/* Get the source of an edge.
 *
 * This function returns the source of an edge (i.e., edge.first).
 *
 * @param edge - the edge
 * 
 * @return edge.first
 * */
const vertex_t & get_source(const edge_t &edge);

/* Get the destination of an edge.
 *
 * This function returns the destination of an edge (i.e., edge.second).
 *
 * @param edge - the edge
 * 
 * @return edge.first
 * */
const vertex_t & get_destination(const edge_t &edge);

/* Displays the useage message.
 *
 * This function displays the command line usage message on how to run the
 * program.
 *
 * @param name - the name of the program executable
 * */
void usage(char *name);

/* Reads edges in a file.
 *
 * This function reads edges from filename and returns them as a
 * std::vector<edge_t>. each line of the file is assumed to be of the form
 * "src dst" where src is the source vertex and dst is the destination vertex.
 * All vertices are assumed to be unsigned integers that can be stored as a
 * std::size_t. Duplicate edges found in the file are ignored. 
 *
 * @param filename - name of the file to read
 *
 * @return a vector of edges read from filename
 *
 * @throws std::runtime_error - thrown if there is an i/o or conversion error
 * */
std::vector<edge_t> read_graph(const std::string &filename);

/*
 * Decrease-and-conquer topological sorting algorithm.
 *
 * This function finds a topological sorting of the vertices of a directed
 * graph. It accepts the number of vertices in the graph (n_vertices) as an
 * an unsigned int (n_vertices) and the directed edges of the graph as a
 * std::vetor<edge_t> (edges). All vertices in the graph are represented as
 * non-negative integers between 0 and n_vertices-1 (inclusive).
 *
 * @param n_vertices - an unsinged integer greater than 0 indicating the number
 *                     of vertices in the graph
 * @param edges - the undirected edges composing the directed graph; all
 *                vertices will be numbers between 0 and n_vertices-1 inclusive
 *
 * @return a vector vertices in topological order
 *
 * @throws std::runtime_error - thrown if no topological sort exists
 * */
std::vector<vertex_t> sort_vertices(unsigned int n_vertices, const std::vector<edge_t> &edges);

/*
 * Topological sort the vertices of a directed graph.
 *
 * This function is a wrapper to the sort_vertices function. It accepts a
 * collection edges and passes them to the sort_vertices function. The vector
 * retruned by the sort_vertices is returned by this function after printing
 * the execution time of the sort_vertices algorithm.
 *
 * @param edges - the edges comprising the directed graph
 *
 * @return a vector vertices in topological order
 * */
std::vector<vertex_t> get_topological_sorting(const std::vector<edge_t> &edges);






std::ostream & operator<<(std::ostream &os, const edge_t &edge) {
	os << edge.first << " -> " << edge.second;
	return os;
}

template <typename T, template<typename E, typename A=std::allocator<E> > class Container>
std::ostream& operator<< (std::ostream& os, const Container<T>& container) {
	typename Container<T>::const_iterator iter = container.begin();
	while(iter != container.end()) {
		os << *iter;
		++iter;
		if(iter != container.end()) {
			os << std::endl;
		}
	}
	return os;
}

const vertex_t & get_source(const edge_t &edge) {
	return edge.first;
}

const vertex_t & get_destination(const edge_t &edge) {
	return edge.second;
}

void usage(char *name) {
	std::cout << "usage: ";
	std::cout << name << " infile" << std::endl;
	std::cout << "  infile - file containing a directed graph" << std::endl << std::endl;
	std::cout << "It is assumed that each line of <infile> contains" << std::endl; 
	std::cout << "a directed edge of form src dst where src and dst are non-negative integers." << std::endl;
}

std::vector<edge_t> read_graph(const std::string &filename) {
	std::vector<edge_t> edges;
	std::ifstream ifs(filename.c_str());
	if(ifs) {
		edge_t edge;
		// read edges into a set to remove duplicates
		std::set<edge_t> edge_set;
		while(ifs >> edge.first && ifs >> edge.second) {
			edge_set.insert(edge);
		}

		// check if there was an error reading in the file
		if(ifs.bad()) { // i/o error
			std::ostringstream oss;
			oss << filename << ": " << strerror(errno);
			throw std::runtime_error(oss.str());
		}
		else if((ifs.fail() && !ifs.eof())) { // conversion error
			std::ostringstream oss;
			oss << filename << ": error reading edge";
			throw std::runtime_error(oss.str());
		}

		// copy the edges read to the edges vector
		std::copy(edge_set.begin(), edge_set.end(), std::back_inserter(edges));
	}
	else { // error opening file
		std::ostringstream oss;
		oss << filename << ": " << strerror(errno);
		throw std::runtime_error(oss.str());
	}

	return edges;
}

std::vector<vertex_t> sort_vertices(unsigned int n_vertices, const std::vector<edge_t> &edges) {

std::vector<std::list<vertex_t>> adj_list(n_vertices);    //initialize list and sorted_vertices //
std::vector<vertex_t> sorted_vertices; 

bool visited[n_vertices] = {false}; 
for (edge_t edge : edges) 
{
	adj_list.at(edge.second).push_back(edge.first);     // going through the amount of edges push back each one //

}

vertex_t node;               //initialize node and check //
bool check = false;

for(unsigned int i = 0; i < n_vertices; i++)
{

	for (unsigned int i = 0; i < n_vertices; i++)	
	{
		check = false;
		if(adj_list[i].empty() && !visited[i])	// if list is empty and visited has not been, node =i, and check and visted are true //
			{

				node = i;
				check = true;
				visited[i] = true;
				break;
			}
	} 

	if (check)
	{
		sorted_vertices.push_back(node);                  // pushes back node then loops through n_vertices to remove and push back //
		for(unsigned int i = 0; i < n_vertices; i++) { 
		adj_list[i].remove(node); 
		adj_list.at(node).push_back(n_vertices + 1);
		}

	}	
	else
	{
		/* use this code to raise an error when no topological sorting exists */
		std::ostringstream oss;
		oss << "error: no topological sorting exists";
		throw std::runtime_error(oss.str());
	}

} 
 
	return sorted_vertices;
}



std::vector<vertex_t> get_topological_sorting(const std::vector<edge_t> &edges) {
	std::vector<vertex_t> sorted_vertices;
	if(edges.size() == 0) {
		std::ostringstream oss;
		oss << "error: one or more edges are required for topological sorting";
		throw std::runtime_error(oss.str());
	}
	else {
		unsigned int n_vertices;
		std::set<vertex_t> vertex_set;
		std::chrono::high_resolution_clock::time_point start, end;
		
		/* add the source vertices to vertex_set */	
		std::transform(
			edges.begin(),
			edges.end(),
			std::inserter(vertex_set, vertex_set.end()),
			get_source
		);
		/* add the destination vertices to vertex_set */	
		std::transform(
			edges.begin(),
			edges.end(),
			std::inserter(vertex_set, vertex_set.end()),
			get_destination
		);

		/* get the largest vertex from vertex_set and add 1 */
		n_vertices = *std::max_element(vertex_set.begin(), vertex_set.end()) + 1;
		
		start = std::chrono::high_resolution_clock::now();
		/* call the topological sorting algorithm */
		sort_vertices(n_vertices, edges).swap(sorted_vertices);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "Elapsed Time: "
			<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
			<< " microseconds" << std::endl;
	}

	return sorted_vertices;
}






int main (int argc, char *argv[]) {
	if(argc != 2) {
		std::cerr << "Invalid number of arguments." << std::endl << std::endl;
		usage(argv[0]);
	}
	else {
		try {
			std::string infile(argv[1]);
			std::vector<edge_t> edges = read_graph(infile);
			std::vector<vertex_t> sorted_vertices = get_topological_sorting(edges);
			std::cout << sorted_vertices << std::endl;
		}
		catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}

	return 0;
}
