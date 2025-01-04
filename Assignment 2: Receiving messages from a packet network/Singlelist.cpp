#include <iostream>
#include <string>

#include "single_list.h"

using namespace std;

// TODO: write a simple program to test the singly-linked list

//////////////////////////////////////////////
// CAUTION: DO NOT CHANGE INCLUDED HEADERS  //
//////////////////////////////////////////////


/* Our singly linked lists have one header elements: the "head" which
   points the first element. The 'next' link of the back header is
   NULL. 
   An empty list looks like this:

                  
          HEAD ---> NULL 
                  

   A list with two elements in it looks like this:
   
                   +-------+    +-------+
          HEAD --->|   1   |--->|   2   |--->NULL
                   +-------+    +-------+

   You should not change the name, input arguments, and
   input/output data types of existing functions. */



/*** COMPLETE FUNCTIONS BELOW ***/

/* SINGLY LINKED LIST */
/* NOTE: In SINGLY LINKED LIST, HEAD is the first element of the list i.e, HEAD = FRONT */

/* Initializes LIST as an empty list with a head. */
single_list::single_list()
{
  /*** MODIFY HERE ***/
  this->head = NULL;
}

/* "Destroys" all of the list elements? */
single_list::~single_list()
{
  /*** MODIFY HERE ***/
	list_elem *curr, *next_;
	curr = this->list_head();
	while(curr->next != NULL){
  		next_ = this->list_next(curr);
		delete curr;
		curr = next_;  	
	}  
}

int
single_list::list_get_data1(list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->data1;
}

int
single_list::list_get_data2(list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->data2;
}

string
single_list::list_get_data3(list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->data3;
}


/* Returns the element after ELEM in its list. */
list_elem *
single_list::list_next (list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->next;
}


/* Returns LIST's head. */
list_elem *
single_list::list_head (void)
{
  /*** MODIFY HERE ***/
  return this->head;
}

/* Insert ELEM at the beginning of LIST, so that it becomes the head 
   in LIST. */
void 
single_list::list_insert_front (list_elem *elem)
{
    /*** MODIFY HERE ***/
    elem->next = this->list_head();
    this->head = elem;
}

/* Insert ELEM just before BEFORE, which may be either an interior
 element or a head. */
void 
single_list::list_insert_before (list_elem *before, list_elem *elem)
{
  /*** MODIFY HERE ***/
	/* Since HEAD is the first element of the list, it is OKAY to insert before HEAD */
	/* There are two cases, first case is when before is actually the HEAD*/
	if (before == this->list_head()){
		elem->next = before;
		this->head = elem;
	}
	else{ // about to find the element right BEFORE the *before 
		list_elem* curr;
		curr = this->list_head();
		while(curr->next != NULL && curr->next != before){
			curr = curr->next;
		}
		if(curr->next == NULL){   /* at the end of the list but still have not found *before */
			std::cerr << "Cannot insert before an element that does not belong to the list\n" << std::endl;
		}
		/* Normal case, now curr is right before the *before */
		curr->next = elem;
		elem->next = before;	
	}	
}

/* Insert ELEM just after AFTER, which may be either an interior
 element or a head. */
void 
single_list::list_insert_after (list_elem *after, list_elem *elem)
{
  /*** MODIFY HERE ***/
  	/* Check if *after actually belongs to the list or not */
  	if(after == this->head){
  		elem->next = after->next;
  		after->next = elem;
	  }
  	else{
  		list_elem *curr;
  		curr = this->head;
  		while(curr->next != after && curr->next != NULL){
  			curr = curr->next;
		  }
		if (curr->next == NULL){ // reach the end of the list but have not found *after
			std::cerr << "Cannot insert after an element that does not belong to the list\n" <<std::endl;
		}
		/* otherwise, curr->next is after now */
		elem->next = after->next;
		after->next = elem;
	  }
}

/* Replace FROM with TO and deconstruct FROM */
void 
single_list::list_replace (list_elem *from, list_elem *to)
{
  /*** MODIFY HERE ***/
  	/* Since HEAD is just an element of the list, it is OKAY to replace the head */
  	if(from == this->head){
  		to->next = from->next;
  		this->head = to;
  		delete from;
  		from = NULL;
	  }
	  
	else{
		list_elem *curr;
		curr = this->head;
  		/* Find the element just before the *from */
		while(curr->next != NULL && curr->next != from){
			curr = curr->next;
		}
		if(curr->next == NULL){  /* from is not in the list T__T */
			std::cerr << "Cannot replace an element that is not in the list\n" << std::endl;
		}
		to->next = from->next;
		curr->next = to;
		delete from;
		from = NULL;
	}
}


/* Removes ELEM from its list and deconstructs it. */
void
single_list::list_remove (list_elem *elem)
{
	/*** MODIFY HERE ***/
	/* Since HEAD is just an element of the list, it is OKAY to remove the HEAD */
	list_elem *curr;
	if(elem == this->head){
		curr = this->head;
		this->head = curr->next;   // could be NULL
		delete curr;
		curr = NULL;
	}
	else{ // find position of *elem in the list
		curr = this->head;
		/* Find the element just before the *from */
		while(curr->next != NULL && curr->next != elem){
			curr = curr->next;
		}
		if(curr->next == NULL){    /* we reach the last element of the list, but still can't find "elem" */
			/* throw an exception because "elem" is not even in the list */	
			std::cerr << "Cannot remove an element that is not even in the list\n" << std::endl;	
		}
		/* Otherwise curr->next = elem now */
		curr->next = elem->next;
		delete elem;
		elem = NULL;
	}
	
}

/* Returns true if LIST is empty, false otherwise. */
bool 
single_list::list_empty (void)
{
  /*** MODIFY HERE ***/  
  return (this->head == NULL);
}

