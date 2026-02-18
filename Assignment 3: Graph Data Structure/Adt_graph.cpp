/*
 * Skeleton code for project 4 in EE205 2017 FALL KAIST
 * Created by Joonki Hong
 */

#include "ADT_graph.h"
#include <iostream>

using namespace std;


/*
 * Tips!!!!
 *
 * 1. Search 'YOUR CODE GOES HERE' to find where to implement.
 * 2. Use commented Debug to get the insight of adjacency list structure.
 * 3. You can compile this file by 'g++ -c ADT_graph.cpp'.
 * 4. You can compile with main.cpp by 'g++ main.cpp ADT_graph.cpp' after you fill the blanks.
 */


/*
 * I know that this project is a little bit tough, but I beleive you can do this!!!
 * Feel free to ask TA!!!
 */

/*
	12/05, 11:15pm UPDATES:
	- Some parts have been modified for Task 2
	- Please note those modifications in the readme file
	- Reference: https://support.microsoft.com/en-us/help/837697/how-to-use-the-stl-priority-queue-class-with-a-custom-type
*/

/*************************** ADT_Node ***************************/

/* Get node name */
template <class T>
string ADT_Node<T>::get_node_name(void) {
	return node_name;
}

/* Get node value */
template <class T>
const T ADT_Node<T>::get_node_value(void) {
	return node_value;
}

/* Add new incidence collection */
template <class T>
int ADT_Node<T>::add_incidence(void){
	incidence = new ADT_Incidence<T>;
	return 1;
}

/* Remove incidence */
template <class T>
int ADT_Node<T>::remove_incidence(void){
	delete incidence;	
	return 1;
}

/* erase one edge from incidence list */
template <class T>
int ADT_Node<T>::erase_edge_from_incidence(ADT_Edge<T>* edge) {
	incidence->remove_incidence_list(edge);
	return 1;
}

/* return the begining of incidence list */
template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Node<T>::get_begin(void){
	return incidence->get_begin();
}

/* return the end of incidence list */
template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Node<T>::get_end(void){
	return incidence->get_end();
}

/* Call add_incidence_list in incidence collection */
template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Node<T>::add_incidence_list(ADT_Edge<T>* edge){
	return incidence->add_incidence_list(edge);
}

/* Save the node position information */
template <class T>
int ADT_Node<T>::add_nodelist_info(typename list<ADT_Node<T>*>::iterator node_position){
	this->node_position = node_position;
	return 1;
}


/* Basic functionality of ADT_Node */
/* TOBECHECKED */
template <class T>
list<ADT_Edge<T>*> ADT_Node<T>::incidentEdges(void) { 
	/* use incidentEdges in incidence list */

	/*
	 * YOUR CODE GOES HERE
	 */
	return this->incidence->incidentEdges();
}

/* Return 1 if YES, 0 if NO */
/* TOBECHECKED */
template <class T>
int ADT_Node<T>::isAdjacentTo(string node_name) {
	/* use isAdjacentTo() function in incidence list	 */
	
	/*
	 * YOUR CODE GOES HERE
	 */
	typename list<ADT_Edge<T>*>::iterator p;
	list< ADT_Edge<T>* > incident_list = this->incidentEdges();
	
	if(incident_list.empty()){return 0;}                        // corner case
	
	for(p = incident_list.begin(); p != incident_list.end(); ++p){
		if(((*p)->get_first_node()).get_node_name().compare(node_name) == 0 || ((*p)->get_second_node()).get_node_name().compare(node_name) == 0){
			return 1;
		}
	}
	return 0;
}

/* Constructor, initializing the node name and the node value, add new incidence collcetion*/
template <class T>
ADT_Node<T>::ADT_Node(string node_name, T node_value) {

	this->node_name = node_name;
	this->node_value = node_value;
	add_incidence();
	this->prev = NULL;
	/* Debug */
	/* cout << "Test2: node name "<< get_node_name()<<", node_value "<<get_node_value() <<endl << endl; */
}

/* Modified part, for task 2 only */
template <class T>
int ADT_Node<T>::set_node_value(T newValue){
	this->node_value = newValue;
	return 1;
}

template<class T>
int ADT_Node<T>::set_prev(ADT_Node<T>* previous){
	this->prev = previous;
	return 1;
}

template<class T>
int ADT_Node<T>::set_D_value(int newValue){
	this->D_value = newValue;
	return 1;
}

template <class T>
int ADT_Node<T>::set_previous(int p){
	this->previous = p;
	return 1;
}
/*************************** Incidence Collection ***************************/

/* Add new edge connection in the incidence collection */
template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Incidence<T>::add_incidence_list(ADT_Edge<T>* edge) {
	return incidence_list.insert(incidence_list.end(), edge); // pointer will be replaced later	
}

/* Remove an edge connection in the incidence collection */
template <class T>
int ADT_Incidence<T>::remove_incidence_list(ADT_Edge<T>* edge) {
	incidence_list.remove(edge); 
	return 1;
}

template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Incidence<T>::get_begin(void){
	return incidence_list.begin();
}

template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Incidence<T>::get_end(void){
	return incidence_list.end();
}

/* TOBECHECKED */
template <class T>
int ADT_Incidence<T>::isAdjacentTo(string node_name) {
	/* check through incidence list for input node_name  */
	/* return 1 if you find it return 0 if you don't find it  */

	/*
	 * YOUR CODE GOES HERE
	 */
	typename list<ADT_Node<T>*>::iterator p;
	list< ADT_Edge<T>* > incident_list = this->incidence_list;
	if(incident_list.empty()){return 0;}                                     // corner case
	for(p = incident_list.begin(); p!= incident_list.end(); ++p){
		if(((*p)->first_node->node_name).compare(node_name) == 0 || ((*p)->second_node->node_name).compare(node_name) == 0){
			return 1;
		}
	}
	return 0;
	
}

/* TOBECHECKED */
template <class T>
list<ADT_Edge<T>*> ADT_Incidence<T>::incidentEdges(void) {
	/* return list of incident edges */
	/*
	 * YOUR CODE GOES HERE
	 */
	return this->incidence_list;
}
/*************************** ADT_Edge ***************************/

/* Get edge name */
template <class T>
string ADT_Edge<T>::get_edge_name(void) {
	return edge_name;	
}

/* Get edge value */
template <class T>
T ADT_Edge<T>::get_edge_value(void) {
	return edge_value;
}

/* Get first node */
template <class T>
ADT_Node<T> ADT_Edge<T>::get_first_node(void) {
	return *first_node;
}


/* Get second node */
template <class T>
ADT_Node<T> ADT_Edge<T>::get_second_node(void) {
	return *second_node;
}

/* Save pointer to the incidence collection of the first vertex and the second vertex */
template <class T>
int ADT_Edge<T>::add_incidence_info(typename list<ADT_Edge<T>*>::iterator first_incidence_position, typename list<ADT_Edge<T>*>::iterator second_incidence_position) {
	this->first_incidence_position = first_incidence_position;
	this->second_incidence_position = second_incidence_position;
	return 1;
}

/* Save the edge position information */
template <class T>
int ADT_Edge<T>::add_edgelist_info(typename list<ADT_Edge<T>*>::iterator edge_position) {
	this->edge_position = edge_position;
	return 1;
}

/* TOBECHECKED */
template <class T>
list<ADT_Node<T>*> ADT_Edge<T>::endVertices(void) {
	/* return a list that have pointer to the first node and second node of the edge */

	/*
	 * YOUR CODE GOES HERE
	 */
	list<ADT_Node<T>*> end_list;
	end_list.push_back(this->first_node);
	end_list.push_back(this->second_node);
	return end_list;
}

/* TOBECHECKED */
template <class T>
string ADT_Edge<T>::opposite(string node_name) {
	/* return the opposite node of given vertex in string */
	/* if given vertex is not included in this edge return 0 */
	/* e.g. for edge A-B, given A, return B */
	/* e.g. for edge A-B, given C, return 0 */

	/*
	 * YOUR CODE GOES HERE
	 */
	string first_name = this->first_node->get_node_name();
	string second_name = this->second_node->get_node_name();
	if(first_name.compare(node_name) == 0){return second_name;}
	else if(second_name.compare(node_name) == 0){return first_name;}
	else{return "";}                                                 // not found
}

/* TOBECHECKED */
template <class T>
int ADT_Edge<T>::isAdjacentTo(string edge_name) {
	/* check that the given edge is adjacent with first end node */
	/* check that the given edge is adjacent with second end node */
	/* return 1 if it is adjacent return 0 if not */

	/*
	 * YOUR CODE GOES HERE
	 */
	ADT_Node<T>* First_node = this->first_node;
	ADT_Node<T>* Second_node = this->second_node;
	list< ADT_Edge<T>* > first_incident = First_node->incidentEdges();
	list< ADT_Edge<T>* > second_incident = Second_node->incidentEdges();
	typename list< ADT_Edge<T>* >::iterator p;
	typename list< ADT_Edge<T>* >::iterator q;
	for(p = first_incident.begin(); p != first_incident.end(); ++p){
		if((*p)->edge_name.compare(edge_name) == 0){return 1;}                   // edge_name is in adjacent list of first node
	}
	for(q = second_incident.begin(); q != second_incident.end(); ++q){
		if((*q)->edge_name.compare(edge_name) == 0){return 1;}                   // edge_name is in adjacent list of second node
	}
	return 0;                                                                  // not found in adjacent lists of first node or second node
}

/* TOBECHECKED */
template <class T>
int ADT_Edge<T>::isIncidentOn(string node_name) {
	/* return 1 if given node is incident, return 0 if not  */
	/* check the first end node and the second end node  */
			
	/*
	 * YOUR CODE GOES HERE
	 */
	ADT_Node<T>* First_node = this->first_node;
	ADT_Node<T>* Second_node = this->second_node;
	if (First_node->get_node_name().compare(node_name) == 0 || Second_node->get_node_name().compare(node_name) == 0){
		return 1;
	}
	return 0;
}


/* Constuctor, initializing edge name, edge value, and vertex name */
template <class T>
ADT_Edge<T>::ADT_Edge(string edge_name, T edge_value, ADT_Node<T> *first_node, ADT_Node<T> *second_node) {

	list<ADT_Edge<T>*> temp_list;

	this->edge_name = edge_name;
	this->edge_value = edge_value;
	this->first_node = first_node;
	this->second_node = second_node;	

	/* Debug */
	/* cout << "Test5: edge name "<< get_edge_name() <<", edge value " <<get_edge_value() << endl <<endl; */
}

/*************************** ADT_Nodelist ***************************/

/* Add new node in the nodelist */
template <class T>
typename list<ADT_Node<T>*>::iterator ADT_Nodelist<T>::add_node_list(ADT_Node<T> *vertex) {
	return node_list.insert(node_list.end(),vertex);
}

/* Remove a node in the nodelist */
template <class T>
int ADT_Nodelist<T>::remove_node_list(ADT_Node<T> *vertex) {
	node_list.remove(vertex);
	return 1;
}

/* TOBECHECKED */
template <class T>
ADT_Node<T>* ADT_Nodelist<T>::search_vertex(string vertex) {
	/* return pointer to a node that has given node name */
	/* if there is no such node, return NULL */

	/*
	 * YOUT CODE GOES HERE
	 */
	list<ADT_Node<T>*> search_list = this->node_list;
	typename list<ADT_Node<T>*>::iterator p;
	for(p = search_list.begin(); p != search_list.end(); ++p){
		if((*p)->get_node_name().compare(vertex) == 0){
			return *p;
		}
	}
	return NULL;
}

/* TOBECHEKED */
template <class T>
int	ADT_Nodelist<T>::print_all_vertices(void){
	/* print all vertices in the nodelist */

	/*
	 * YOUR CODE GOES HERE
	 */
	list<ADT_Node<T>*> Node_list = this->node_list;
	typename list<ADT_Node<T>*>::iterator p;
	for(p = Node_list.begin(); p != Node_list.end(); ++p){
		std::cout << (*p)->get_node_name() << std::endl;
	}
	return 1;
}

/* Return node list */ 
template <class T>
list<ADT_Node<T>*> ADT_Nodelist<T>::get_node_list(void) {
	return node_list;
}
/*************************** ADT_Edgelist ***************************/

/* Add new edge in the edgelist */
template <class T>
typename list<ADT_Edge<T>*>::iterator ADT_Edgelist<T>::add_edge_list(ADT_Edge<T> *edge) {
	return edge_list.insert(edge_list.end(),edge);
}

/* Remove a edge in the edgelist */
template <class T>
int ADT_Edgelist<T>::remove_edge_list(ADT_Edge<T> *edge) {
	edge_list.remove(edge);
	return 1;
}

/* TOBECHECKED */
template <class T>
ADT_Edge<T>* ADT_Edgelist<T>::search_edge(string edge) {
	/* return pointer to certain edge that has given edge name */
	/* if there is no such edge, return NULL */
	
	/*
	 * YOUR CODE GOES HERE
	 */
	list<ADT_Edge<T>*> search_list = this->edge_list;
	typename list<ADT_Edge<T>*>::iterator p;
	for(p = search_list.begin(); p!= search_list.end(); ++p){
		if(((*p)->get_edge_name()).compare(edge) == 0){
			return *p;
		}
	}
	return NULL;
}

/* TOBECHECKED */
template <class T>
int	ADT_Edgelist<T>::print_all_edges(void){
	/* print all edges in the edgelist */

	/*
	 * YOUR CODE GOES HERE
	 */
	list<ADT_Edge<T>*> search_list = this->edge_list;
	typename list<ADT_Edge<T>*>::iterator p;
	for(p = search_list.begin(); p!= search_list.end(); ++p){
		std::cout << (*p)->get_edge_name() << std::endl;
	}
}

/* Return edge list */ 
template <class T>
list<ADT_Edge<T>*> ADT_Edgelist<T>::get_edge_list(void) {
	return edge_list;
}
/*************************** ADT_Graph ***************************/

template <class T>
int ADT_Graph<T>::vertices(void) {
	ADT_nodelist->print_all_vertices();
	return 0;
}


template <class T>
int ADT_Graph<T>::edges(void) {
	ADT_edgelist->print_all_edges();
	return 0;
}

/* TOBECHECKED */
template <class T>
int ADT_Graph<T>::insertVertex(string node_name, int node_value) {
	
	/* Hmm, the procedure is a little complicated, isn't it? */
	/* 1. make new node object */
	/* 2. add new node object to nodelist */
	/* 3. add nodelist info to node object */

	/*
	 * YOUR CODE GOES HERE
	 */
	 
	/* 1. make new node object */
	ADT_Node<T>* newNode = new ADT_Node<T>(node_name, node_value);
	
	/* 2. add new node object to nodelist */
	typename list<ADT_Node<T>*>::iterator Iter;
	Iter = this->ADT_nodelist->add_node_list(newNode);
	
	/* 3. add nodelist info to node object */
	int result = newNode->add_nodelist_info(Iter);
	
	/* Debug */
	/* cout << "Test3: node iterator is working??? " << (*node_iterator)->get_node_name() << endl << endl; */
	return result;
}

/* TOBECHECKED */
/* return 1 for success, return 0 for failure somehow */
template <class T>
int ADT_Graph<T>::insertEdge(string vertex_name1, string vertex_name2, string edge_name, int edge_value) {

	ADT_Node<T> *first_node, *second_node;
	typename list<ADT_Edge<T>*>::iterator edge_iterator, first_edge_iterator, second_edge_iterator;
	
	/* 1. Find corresponding ADT_Node with vertex name */
	/* 2. Make new edge and add it to edge list */
	/* 3. Add edge to incidence collection of the first and second vertex */
	/* 4. Add reverse connection to incidence collection */

	/*
	 * YOUR CODE GOES HERE
	 */
	 
	 /* 1. Find corresponding ADT_Node with vertex name */
	 if(vertex_name1.compare(vertex_name2) == 0){
	 	return 0;											    // corner case, 2 vertices are the same
	 }
	 ADT_Node<T> *First_node, *Second_node;
	 ADT_Nodelist<T>* Node_list = this->ADT_nodelist;
	 
	 First_node = Node_list->search_vertex(vertex_name1);
	 Second_node = Node_list->search_vertex(vertex_name2);
	 if(First_node == NULL || Second_node == NULL){return 0;}   // corner case, 1 of them is not even in the graph
	 
	 /* 2. Make new edge and add it to edge list */
	 ADT_Edge<T>* newEdge = new ADT_Edge<T>(edge_name, edge_value, First_node, Second_node);
	 ADT_Edge<T>* newEdge1 = new ADT_Edge<T>(edge_name, edge_value, First_node, Second_node);
	 ADT_Edge<T>* newEdge2 = new ADT_Edge<T>(edge_name, edge_value, First_node, Second_node);
	 this->ADT_edgelist->add_edge_list(newEdge);
	 
	 /* 3. Add edge to incidence collection of the first and second vertex */
	 First_node->add_incidence_list(newEdge);
	 Second_node->add_incidence_list(newEdge);
	 
	 /* 4. Add reverse connection to incidence collection??? */
	 

	/* Debug */
	/* cout << "Test4: search_vertex??? "<< first_node->get_node_name() <<" "<< second_node->get_node_name() << endl <<endl; */
	/* cout << "Test6: edge iterator is working ??? "<< (*edge_iterator)->get_edge_name() <<" "<< (*edge_iterator)->get_edge_value() << endl <<endl; */

	return 1;
}

/* TOBECHECKED */
/* Return 1 for normal erasal, 0 if something goes wrong */
template <class T>
int ADT_Graph<T>::eraseVertex(string node_name) {
	/* 1. Use search_vertex() to find corresponding node pointer */
	/* 2. Erase all edges in incidence collection */
	/* 3. Remove node from nodelist */
	/* 4. Remove node */

	/*
	 * YOUR CODE GOES HERE
	 */
	 
	/* 1. Use search_vertex() to find corresponding node pointer */
	ADT_Nodelist<T> *Node_list = this->ADT_nodelist;
	ADT_Node<T> *vertex = Node_list->search_vertex(node_name);
	ADT_Edgelist<T> *Edge_list = this->ADT_edgelist;
	if(vertex == NULL){
		return 0;
		}                                            // not found
	
	/* 2. Erase all edges in incidence collection */
	/* and from all adjacent vertices, "node_name" must be deleted from the their incidence lists */
	/* for example (node_name,a), (b, node_name), (node_name, c) are indicent edges of node_name then those edges must be deleted from ADT_edgelist*/
	/* and node_name must be deleted from incidence lists of a,b and c */
	
	list<ADT_Edge<T>*> Incident_list;
	Incident_list = vertex->incidentEdges();
	
	typename list<ADT_Edge<T>*>::iterator p;
	
	typename list<ADT_Edge<T>*>::iterator iter, iter_next;
	for(iter = Incident_list.begin(); iter != Incident_list.end(); ++iter){
		if((*iter)->get_first_node().get_node_name().compare(node_name) == 0){
			(*iter)->get_second_node().erase_edge_from_incidence(*iter);
			
		}
		else{
			(*iter)->get_first_node().erase_edge_from_incidence(*iter);
		}
		this->ADT_edgelist->remove_edge_list(*iter);
	}
	
	vertex->remove_incidence();

	/* 3. Remove node from nodelist */
	Node_list->remove_node_list(vertex);

	/* 4. Remove node */
	delete vertex;

	return 1;
}

/* TOBECHECKED */
/* Return 1 if normal, 0 if something goes wrong */
template <class T>
int ADT_Graph<T>::eraseEdge(string edge_name) {
	/* find correstponding edge and call eraseEdge again */

	/*
	 * YOUR CODE GOES HERE
	 */
	ADT_Edgelist<T> *Edge_list = this->ADT_edgelist;
	ADT_Edge<T>* erase_edge = Edge_list->search_edge(edge_name);
	if(erase_edge == NULL){return 0;}
	else{
		return ADT_Graph<T>::eraseEdge(erase_edge);
	}
}

/* TOBECHECKED */
/* Assuming that this edge MUST be in the graph (checked by the method above) */
template <class T>
int ADT_Graph<T>::eraseEdge(ADT_Edge<T>* erase_edge) {

	/* 1. Erase edge in the first node incidence collection */
	/* 2. Erase edge in the second node incidence collection */
	/* 3. Erase edge from the edgelist */
	/* 4. Erase edge  */

	/*
	 * YOUR CODE GOES HERE
	 */
	 /* 1. Erase edge in the first node incidence collection */
	 erase_edge->get_first_node().erase_edge_from_incidence(erase_edge);
	 /* 2. Erase edge in the second node incidence collection */
	 erase_edge->get_second_node().erase_edge_from_incidence(erase_edge);
	 
	 /* 3. Erase edge from the edgelist */
	 this->ADT_edgelist->remove_edge_list(erase_edge);
	 
	 /* 4. Erase edge, a.k.a deallocate the allocated memory  */
	delete erase_edge;
	return 1;	 
}

template <class T>
ADT_Nodelist<T> ADT_Graph<T>::get_ADT_nodelist(void) {
	return *ADT_nodelist;
}

template <class T>
ADT_Edgelist<T> ADT_Graph<T>::get_ADT_edgelist(void) {
	return *ADT_edgelist;
}

template <class T>
ADT_Graph<T>::ADT_Graph(string graph_name) {
	graph_name = graph_name;
	ADT_nodelist = new ADT_Nodelist<T>;
	ADT_edgelist = new ADT_Edgelist<T>;

	/* Debug */
	/* cout<<"Test1: graph name is "<<graph_name<<endl<<endl; */

}

template class ADT_Graph<int>;
template class ADT_Node<int>;
template class ADT_Edge<int>;
template class ADT_Edgelist<int>;
template class ADT_Nodelist<int>;
