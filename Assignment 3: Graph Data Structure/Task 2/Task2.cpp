#include "ADT_graph.h"  
/* #include "hello.h"  */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* Supporting functions */
int findMin(int D[], int size){
	int index = 0;
	int min = D[index];
	for(int i = 0; i< size; i++){
		if(D[i] < min){
			min = D[i];
			index = i;
		}
	}
	return index;
}


int main(int argc, char* argv[]){
	
	/* Command check*/
	if(argc != 5){
		std::cerr << "Error: Invalid command." << std::endl;
		return (-1);
	}
	
	/* Step 1: read the input file and from a graph */
	
	/* Our "lovely" graph */
	ADT_Graph<int> *ourGraph = new ADT_Graph<int>("ourGraph");
	
	/* Read the input file */
	string line, s;
	ifstream fd1, fd2; 												 // fd1 to read input, fd2 to read Shortest path tasks
  	fd1.open(argv[1]);
  	int phase = 0;                                                   // phase of reading input file process
  	int count_node = 0;
	
	string node_name, node1, node2;
	int edge_length;
	
	while(getline(fd1, line)){
		if(phase == 1 && line.compare("") > 0 && line.compare("Edge") != 0){                      // phase 1, inserting vertices
			stringstream line_stream(line);
			while(line_stream.good()){line_stream >> node_name;}
			ourGraph->insertVertex(node_name, count_node);                   // 10000000000 is for Shortest Path Algorithm, acts like infinity
			count_node++;
		}
		else if(phase == 2 && line.compare("") > 0){				 // phase 2, inserting edges
			stringstream line_stream(line);
			line_stream >> node1;
			line_stream >> node2;
			line_stream >> edge_length;
			ourGraph->insertEdge(node1, node2, node1 ,edge_length);
			//std::cout << ourGraph->get_ADT_edgelist().get_edge_list().size() << std::endl;
		}
		if(line.compare("Node") == 0){phase = 1;}                    // change from phase 0 to phase 1
		if(line.compare("Edge") == 0){phase = 2;}                    // change from phase 1 to phase 2
	}
	/* Printing, for debugging only */
	
	fd1.close();
	
	/* Step 2: run the algorithm, may be from a function defined outside of main() */
	
	/* 2a. Running Dijkstra's algorithm for Short Path problem */
	string source, destination;
	fd2.open(argv[2]);
	while(getline(fd2, line)){
		stringstream line_stream(line);
		line_stream >> source;
		line_stream >> destination;
		/* Sanity check */
		ADT_Node<int> *src, *dest;
		src = ourGraph->get_ADT_nodelist().search_vertex(source);
		dest = ourGraph->get_ADT_nodelist().search_vertex(destination);
		ADT_Edge<int> *edge;
		
		if(src != NULL && dest != NULL){                                                  // now implement Dijkstra's algorithm
			// D_value 
			int size = ourGraph->get_ADT_nodelist().get_node_list().size();
			cout << "source is " << src->node_name << endl;
			cout << "destination is " << dest->node_name << endl;
			int D[size];
			int i;
			for (i = 0; i < size; i++){
				if ( i == src->node_value){D[i] = 100001;}
				else{D[i] = 100000;}
			}
			
			typename list< ADT_Edge<int>* >::iterator iterate;
			int initial_value = src->get_node_value();
			//std::cout << ourGraph->get_ADT_edgelist().get_edge_list().size() << std::endl;
			for(iterate = ((ourGraph->ADT_edgelist)->edge_list).begin(); iterate != ((ourGraph->ADT_edgelist)->edge_list).end(); ++iterate){
				//cout << (*iterate)->edge_value << endl;
 				if((*iterate)->first_node->node_name.compare(src->node_name) == 0){
					int index = (*iterate)->second_node->node_value;
					D[index] = (*iterate)->edge_value;
					//cout << "this node D value is updated as " << D[index] << endl;
					(*iterate)->second_node->set_previous(initial_value);
				}
		
				else if((*iterate)->second_node->node_name.compare(src->node_name) == 0){
					int index = (*iterate)->first_node->node_value;
					D[index]= (*iterate)->edge_value;
					//cout << "this node D value is updated as " << D[index] << endl;
					(*iterate)->first_node->set_previous(initial_value);
				}
				
			}		
			std::cout << "done initialization step" << std::endl;
			list<ADT_Node<int>* > D_list;
			typedef list< ADT_Node<int>* >::iterator Iter;
	
			for (Iter p = ourGraph->ADT_nodelist->node_list.begin(); p != ourGraph->ADT_nodelist->node_list.end(); ++p){
				if((*p)->node_name.compare(src->node_name) != 0){
					D_list.push_back(*p);
				}
			}
			
			// the "priority queue" part
			std::cout << "D_list has elements " << D_list.size() << std::endl;
			int times = 0;
			while(!D_list.empty()){
				ADT_Node<int>* Node;
				int min = findMin(D, size);
				//cout << min << endl;
				//std::cout << D[min] << std::endl;
				for(Iter t = ourGraph->ADT_nodelist->node_list.begin(); t != ourGraph->ADT_nodelist->node_list.end(); ++t){
					if((*t)->node_value == min){
						Node = *t;
						break;
					}
				}
				//cout << Node->node_value << endl;
				for(iterate = ourGraph->ADT_edgelist->edge_list.begin(); iterate != ourGraph->ADT_edgelist->edge_list.end(); ++iterate){
					edge = *iterate;
					if(edge->first_node->node_name.compare(Node->node_name) == 0){
						int index = edge->second_node->node_value;
						if(D[index] > edge->edge_value + D[min]){
							D[index] = edge->edge_value + D[min];
						}
						edge->second_node->set_previous(min);
					}
		
					else if(edge->second_node->node_name.compare(Node->node_name) == 0){
						int index = edge->first_node->node_value;
						if(D[index] > edge->edge_value + D[min]){
							D[index]= edge->edge_value + D[min];
						}
						edge->first_node->set_previous(min);
					}
				}
				if(Node->node_name.compare(dest->node_name) == 0){
					break;
				}
				D[min] = 100001;
				D_list.remove(Node);
				
				std::cout << "okay D_list removed 1 element" << endl;
				times++;
			}
			cout << D[dest->node_value] << endl;
		}
		else{
			std::cout << "Invalid input, 1 or 2 vertices are not in the graph" << std::endl;
		}
	}
	/* For debugging */
	std::cout << "Shortest path done, phooh!" << std::endl;
	
	/* 2b. Running Minimum Spanning Tree */
	/* Kruskal or Prim??? */
	
	/* Step 3: print to the output file (may already be incorporated into Step 2) */
	return 0;
}
