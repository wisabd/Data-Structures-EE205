#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include "student.h"


// //****************************************************************
// //                   MAIN FUNCTION IN PROJECT
// //****************************************************************

int main()
{
  char command;
  Manager myman;
  int isgrad;
  std::string name;
  int stunum;
  std::string labname;
  int freshmenclass;
  int index;

  while(1){
	std::cout << "\n\n\n*---------------------Welcome to Student Management System---------------------*" << std::endl;

	std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c\n3. Find student:f\n4. Delete student:d\n5. Change student:c\n6. Print all student:p" << std::endl;

	// ******Modify here****** 
	//You need to handle wrong argument format
	std::cin >> command;
	while(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid command, please type again\n" << std::endl;
		std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c\n3. Find student:f\n4. Delete student:d\n5. Change student:c\n6. Print all student:p" << std::endl;
		std::cin >> command;
	}
	switch(command)
	  {
	  case 'a':{
		// Type of student you want to add (Graduate student or Undergraduate student)
		std::cout << "Add student executed\n\nType\nUndergraduate:0 Graduate:1"<< std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format (not integer? )
		
		std::cin >> isgrad;
		while(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid student type, must be 0 or 1\n" << std::endl;
			std::cout << "Type\nUndergraduate:0 Graduate:1"<< std::endl;
			std::cin >> isgrad;
		}
		if (isgrad == 1){
		  std::cout << "\nFormat: (name, stunum, labname)" << std::endl;
		  
		  // ******Modify here****** 
		  //You need to handle wrong argument format, but how?? T__T
		  std::cin >> name >> stunum >> labname;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Format: (name, stunum, labname)" << std::endl;
		  	std::cin >> name >> stunum >> labname;
		  }
		  myman.add_student(name, stunum, labname);		  
		}

		else if (isgrad == 0){
		  std::cout << "\nFormat: (name, stunum, freshmenclass) " << std::endl;
		  
		  // ******Modify here****** 
		  //You need to handle wrong argument format, how???????
		  std::cin >> name >> stunum >> freshmenclass;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Format: (name, stunum, freshmenclass)" << std::endl;
		  	std::cin >> name >> stunum >> freshmenclass;
		  }
		  myman.add_student(name, stunum, freshmenclass);		  
		}
		
	  }break;

	  case 'c':{
		std::cout << "Compare student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format
		std::cin >> isgrad;
		while(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid student type, must be 0 or 1\n" << std::endl;
			std::cout << "Type\nUndergraduate:0 Graduate:1" << std::endl;
			std::cin >> isgrad;
		}
		if (isgrad == 1){
		  std::cout << "\nTarget student\nFormat: (index, name, stunum, labname)" << std::endl;
		  
		  // ******Modify here****** 
		  //You need to handle wrong argument format
		  std::cin >> index >> name >> stunum >> labname;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Target student\nFormat: (index, name, stunum, labname)" << std::endl;
		  	std::cin >> name >> stunum >> labname;
		  }
		  myman.compare_student(index, name, stunum, labname);
		}

		else if (isgrad == 0){
		  std::cout << "\nTarget student\nFormat: (index, name, stunum, freshmenclass) " << std::endl;
		  std::cin >> index >> name >> stunum >> freshmenclass;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Target student\nFormat: (index, name, stunum, freshmenclass) " << std::endl;
		  	std::cin >> name >> stunum >> freshmenclass;
		  }
		  myman.compare_student(index, name, stunum, freshmenclass);
		}
	  }break;

	  case 'f':{
		std::cout << "Find student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format
		std::cin >> isgrad;
		while(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid student type, must be 0 or 1\n" << std::endl;
			std::cout << "Type\nUndergraduate:0 Graduate:1" << std::endl;
			std::cin >> isgrad;
		}
		if (isgrad == 1){
		  std::cout << "\nFormat: (name, stunum, labname)" << std::endl;

		  // ******Modify here****** 
		  //You need to handle wrong argument format
		  std::cin >> name >> stunum >> labname;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Format: (name, stunum, labname)" << std::endl;
		  	std::cin >> name >> stunum >> labname;
		  }
		  myman.find_student(name, stunum, labname);
		}
		else if (isgrad == 0){
		  std::cout << "\nFormat: (name, stunum, freshmenclass)" << std::endl;

		  // ******Modify here****** 
		  //You need to handle wrong argument format
		  std::cin >> name >> stunum >> freshmenclass;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Format: (name, stunum, freshmenclass)" << std::endl;
		  	std::cin >> name >> stunum >> freshmenclass;
		  }
		  myman.find_student(name, stunum, freshmenclass);
		}
	  }break;


	  case 'd':{
		std::cout << "Delete student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;

		// ******Modify here****** 
		//You need to handle wrong argument format
		std::cin >> isgrad;
		while(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid student type, must be 0 or 1\n" << std::endl;
			std::cout << "Type\nUndergraduate:0 Graduate:1" << std::endl;
			std::cin >> isgrad;
		}
		if (isgrad == 1){
		  std::cout << "\nFormat: (name, stunum, labname)" << std::endl;
		  
		  // ******Modify here****** 
		  //You need to handle wrong argument format
		  std::cin >> name >> stunum >> labname;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Format: (name, stunum, labname)" << std::endl;
		  	std::cin >> name >> stunum >> labname;
		  }
		  myman.delete_student(name, stunum, labname);
		}
		else if (isgrad == 0){
		  std::cout << "\nFormat: (name, stunum, freshmenclass)" << std::endl;
		  
		  // ******Modify here****** 
		  //You need to handle wrong argument format
		  std::cin >> name >> stunum >> freshmenclass;
		  while(std::cin.fail()){
		  	std::cin.clear();
			std::cin.ignore();
		  	std::cout << "Invalid input format, please try again\n" << std::endl;
		  	std::cout << "Format: (name, stunum, freshmenclass)" << std::endl;
		  	std::cin >> name >> stunum >> freshmenclass;
		  }
		  myman.delete_student(name, stunum, freshmenclass);
		}
	  }break;

	  case 'p':{
		std::cout << "Print all executed" << std::endl;
		myman.print_all();
	  }break;

	  default:{
		std::cout << "Invalid argument" << std::endl;
	  }break;
	  }
  }
  return 0;
}
