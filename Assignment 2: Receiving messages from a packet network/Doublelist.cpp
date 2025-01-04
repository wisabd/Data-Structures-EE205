#include <iostream>
#include <string>

#include "double_list.h"

using namespace std;

// TODO: write a simple program to test the doubly-linked list

//////////////////////////////////////////////
// CAUTION: DO NOT CHANGE INCLUDED HEADERS  //
//////////////////////////////////////////////

/* Our doubly linked lists have two header elements: the "head"
   just before the first element and the "tail" just after the
   last element. The 'prev' link of the front header is null, as
   is the 'next' link of the back header. Their other two links
   point toward each other via the interior elements of the list.

   An empty list looks like this:

                      +------+     +------+
                  <---| head |<--->| tail |--->
                      +------+     +------+

   A list with two elements in it looks like this:

        +------+     +-------+     +-------+     +------+
    <---| head |<--->|   1   |<--->|   2   |<--->| tail |<--->
        +------+     +-------+     +-------+     +------+

   The symmetry of this arrangement eliminates lots of special
   cases in list processing. That's a lot simpler than the code 
   would be without header elements.

   (Because only one of the pointers in each header element is used,
   we could in fact combine them into a single header element
   without sacrificing this simplicity.  But using two separate
   elements allows us to do a little bit of checking on some
   operations, which can be valuable.) 

   You SHOULD NOT change the name, input arguments, and
   input/output data types of existing functions. */



/*** COMPLETE FUNCTIONS BELOW ***/

/* Doubly LINKED LIST */

/* Initializes LIST as an empty list. 'prev' of 'head' and 'next' of
   'tail' in LIST have null. 'next' of 'head' points 'tail' and 'prev'
   of 'tail' points 'head'. */
double_list::double_list()
{
  /*** MODIFY HERE ***/
  this->head = new d_list_elem();
  this->tail = new d_list_elem();
  this->head->next = tail;
  this->tail->prev = head;
}

double_list::~double_list()
{
  /*** MODIFY HERE ***/
  d_list_elem *curr, *next_;
  curr = this->head;
  while(curr->next != NULL){
  	next_ = curr->next;
  	delete curr;
  	curr = next_;
  }
}

int
double_list::d_list_get_data1(d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->data1;
}

int
double_list::d_list_get_data2(d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->data2;
}

string
double_list::d_list_get_data3(d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->data3;
}

/* Returns the element before ELEM in its list. If ELEM is the first 
   element in its list, returns the list head. Results are undefined 
   if ELEM is itself a list head. */
d_list_elem *
double_list::d_list_prev (d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  if(elem == this->head){   // undefined behaviour
  	/* throw an exception here */
  		std::cerr << "There is no element before the HEAD\n" << std::endl;
  }
  return elem->prev;
}

/* Returns the element after ELEM in its list. If ELEM is the last
   element in its list, returns the list tail. Return NULL if ELEM is
   itself a list tail. */
d_list_elem *
double_list::d_list_next (d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  return elem->next;
}


/* Returns LIST's head. */
d_list_elem *
double_list::d_list_head (void)
{
  /*** MODIFY HERE ***/
  return this->head;
}

/* Returns LIST's tail. */
d_list_elem *
double_list::d_list_tail (void)
{
  /*** MODIFY HERE ***/
  return this->tail;
}

/* Returns the front element in LIST. Return NULL if LIST is empty. */
d_list_elem *
double_list::d_list_front (void)
{
  /*** MODIFY HERE ***/
  if(this->head->next == this->tail){   // the list is empty 
  	return NULL;
  }
  else{
  	return this->head->next;
  }
}

/* Returns the back element in LIST. Return NULL if LIST is empty. */
d_list_elem *
double_list::d_list_back (void)
{
  /*** MODIFY HERE ***/
  if(this->head->next == this->tail){   /* this list is empty */
  	return NULL;
  }
  else{
  	return this->tail->prev;
  }
}


/* Insert ELEM at the beginning of LIST, so that it becomes the front 
   in LIST. */
void 
double_list::d_list_insert_front (d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  elem->next = this->head->next;
  d_list_elem *next_;
  next_ = this->head->next;
  next_->prev = elem;
  elem->prev = this->head;
  this->head->next = elem;
}

/* Insert ELEM at the end of LIST, so that it becomes the back in LIST. */
void 
double_list::d_list_insert_back (d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  d_list_elem *prev_;
  prev_ = this->tail->prev;
  prev_->next = elem;
  elem->prev = prev_;
  elem->next = this->tail;
  this->tail->prev = elem;
}

/* Insert ELEM just before BEFORE, which may be either an interior
 element or a tail. The latter case is equivalent to list_insert_back().
 Results are undefined if BEFORE is itself a list head. */
void 
double_list::d_list_insert_before (d_list_elem *before, d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  	if(before == this->head){   // undefined behaviour
  		/* throw an exception */
  		std::cerr << "Cannot insert any element before the HEAD\n" <<std::endl;
  	}
  	d_list_elem *curr;
  	/* Confirm with "before" is actually an element of the list */
	curr = this->head;
	while(curr->next != before && curr->next != this->tail){
		curr = curr->next;
	}
	if(curr->next == this->tail){ // we reach the last element but have not found "before"
		/* throw an exception */
		std::cerr << "Cannot insert before an element that does not even belong to the list\n" << std::endl;
	}
	/* otherwise, curr->next == before now, i.e curr == before->prev */
  	elem->prev = curr;
  	curr->next = elem;
  	elem->next = before;
  	before->prev = elem;
}

/* Insert ELEM just after AFTER, which may be either an interior
 element or a head. The latter case is equivalent to list_insert_front().
 Results are undefined if AFTER is itself a list tail. */
void 
double_list::d_list_insert_after (d_list_elem *after, d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  	if (after == this->tail){ // undefined behaviour
  		/* throw an exception */
  		std::cerr << "Cannot insert any element after the TAIL\n" <<std::endl;
  	}
  	d_list_elem *next_, *curr;
  	/* Confirm if "after" is actually an element of the list */
  	curr = this->head;
	while(curr->next != after && curr->next != this->tail){
		curr = curr->next;
	}
	if(curr->next == this->tail){ // we reach the last element but have not found "after"
		/* throw an exception */
		std::cerr << "Cannot insert after an element that does not belong to the list\n" << std::endl;
	}
	/* otherwise, curr->next == after now, normal case */
  	next_ = after->next;
  	next_->prev = elem;
  	elem->next = next_;
  	elem->prev = after;
  	after->next = elem;
}

/* Replace FROM with TO and deconstruct FROM*/
void 
double_list::d_list_replace (d_list_elem *from, d_list_elem *to)
{
  /*** MODIFY HERE ***/
  	/* Confirm if "after" is actually an element of the list */
  	if(from == this->head || from == this->tail){  // asked to remove the head/tail of the list?
  			/* throw an exception */
  			std::cerr << "Cannot replace the HEAD or the TAIL of the list\n" << std::endl;
	  }
  	d_list_elem *curr;
  	curr = this->head;
	while(curr->next != from && curr->next != this->tail){
		curr = curr->next;
	}
	if(curr->next == this->tail){ // we reach the last element but have not found "after"
		/* throw an exception */
		std::cerr << "Cannot replace an element that does not belong to the list\n" << std::endl;
	}
	/* otherwise, curr->next == from now, normal case */
	curr->next = to;
	to->prev = curr;
	from->next->prev = to;
	to->next = from->next;
	delete from;
	from = NULL;
}


/* Removes ELEM from its list and deconstruct it.
   Undefined behavior if ELEM is not in a list. Results are undefined
   if ELEM is not an interior element of its list.
*/

void
double_list::d_list_remove (d_list_elem *elem)
{
  /*** MODIFY HERE ***/
  	if (elem == this->head || elem == this->tail){
  		std::cerr << "Cannot remove the HEAD/TAIL of the list\n" << std::endl;
	  }
  /* Confirm if "elem" is actually an element of the list */
  	d_list_elem *curr, *next_;
  	curr = this->head;
	while(curr->next != elem && curr->next != this->tail){
		curr = curr->next;
	}
	if(curr->next == this->tail){ // we reach the last element but have not found "after"
		/* throw an exception */
		std::cerr << "Cannot delete an element that does not belong to the list\n" << std::endl;
	}
	/* otherwise, curr->next == elem now, normal case */
	next_ = elem->next;
	curr->next = next_;
	next_->prev = curr;
	delete elem;
	elem = NULL;
}

/* Returns true if LIST is empty, false otherwise. */
bool 
double_list::d_list_empty (void)
{
  /*** MODIFY HERE ***/
  return (this->head->next == this->tail);
}
