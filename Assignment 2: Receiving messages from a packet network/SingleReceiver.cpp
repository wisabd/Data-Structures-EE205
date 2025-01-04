#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <sstream>
#include "single_list.h"

using namespace std;

/* DO NOT CHANGE INCLUDED HEADERS */

int main(int argc, char* argv[])
{
  /* 1st arg: input file name , 2nd arg: output file name */


  ///////////////////////////////////////////////////////
  //                                                   //
  //  SINGLY LINKED LIST RECEIVER IMPLEMENTATION HERE  //
  //                                                   //
  ///////////////////////////////////////////////////////
  	single_list* msg[600];            // array of linked lists
  	int i;
  	for(i=0; i<600; i++){msg[i] = new single_list();}    // temporary NULL now, not initialized yet
  	
  	/* Step 1: Parse the input file and form the list element, and add to the list in the correct order*/
  	ifstream fd;
  	string line;
  	fd.open(argv[1]);
  	char *token, *m;
  	const char *message;
  	
  	int data1, data2;                      // element of a message instance
	string string1, string2, data3;
	time_t start, end;
	
	/* Read the input file */
  	while(getline(fd, line)){
  		time(&start);
  		/* Extract the needed information (message number, packet number, message) */
  		char* store;
  		string s;
  		message = new char[line.length()+1];
  		message = line.c_str();
  		m = new char[line.length()+1];
  		strcpy(m, message);
  		int position1, position2;
  		position1 = line.find("\t", 0);
  		store = new char[position1 + 1];
  		strncpy(store, m, position1);
  		string1 = std::string(store);
  		delete store;
  		position2 = line.find("\t", position1+1);
  		store = new char[position2-position1];
  		strncpy(store, m+position1+1, position2-position1-1);
  		string2 = std::string(store);
  		delete store;
  		data3 = std::string(m+position2+1);
  		
	
		/* Form an instance of list element */
		std::stringstream convert1, convert2;
		convert1 << string1 ;
		convert1 >> data1;
		convert2 << string2;
		convert2 >> data2;
		
		/* data1 is number of the message, messages with number i will be store in the list msg[i] */
		list_elem *elem, *curr;
		elem = new list_elem(data1, data2, data3);
		
		/* Add the message to the appropriate position of the list */
		if(msg[data1]->list_empty()){msg[data1]->list_insert_front(elem);}    // if the list is empty, just add the element to the front
		else{
			/* First, find if there is any element that is already in the list having the same data2 with the "elem" */                                                                 // otherwise, please add the element in the correct order
			curr = msg[data1]->list_head();
			while(curr != NULL && msg[data1]->list_get_data2(curr) < data2){curr = msg[i]->list_next(curr);}
			if (curr == NULL){  // 
				curr = msg[data1]->list_head();
				while(msg[data1]->list_next(curr) != NULL ){curr = msg[i]->list_next(curr);}
				msg[data1]->list_insert_after(curr, elem);
			}
			else if (msg[data1]->list_get_data2(curr) == data2){
				msg[data1]->list_replace(curr, elem);
			}
			else{
				msg[data1]->list_insert_before(curr, elem);
			}	
			
		}
  	}
  	fd.close();
  	
  	/* Step 2: Print the messages  and the time using timediff(), and warnings as well :) */
  	/* Actually you need to print to the output file, not the standard output. so modifications are needed*/
  	list_elem *cursor;
  	
  	ofstream filed;
  	filed.open(argv[2]);
  	
  	std::cout << "reach here\n" << std::endl;
  	int count;
  	for(i=1; i<600;i++){
  		if(msg[i]->list_head() != NULL){
  			count = 0;
  			filed << "- Message " << i << std::endl;
  			cursor = msg[i]->list_head();
  			while(cursor != NULL){
  				/* Print all packet contents of message i */
  				/* A lost packet is replaced by a packet with warning message */
  				while(msg[i]->list_get_data2(cursor) > count + 1){
  					count++;
  					filed << "WARNING: packet " << count << " of message " << i << " is missing. " << std::endl;
				}
				/* now, msg[i]->list_get_data2(cursor) = count+1 */
  				filed << msg[i]->list_get_data3(cursor) << std::endl;
  				count++;
  				cursor = msg[i]->list_next(cursor);
  				/* count+1 is expected to be cursor->data2, will be checked in the next loop, if not then warnings will be printed */
			  }
  			filed << "- End Message " << i << "\n" << std::endl;
		  }
	  }
	time(&end);
	filed << "Running time: " << difftime(end, start) << "s" << std::endl;
	filed.close();
	return 0;
}
