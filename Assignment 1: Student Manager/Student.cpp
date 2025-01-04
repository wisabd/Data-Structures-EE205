#include <iostream>
#include <cstdlib>
#include <string>
#include "student.h"



// //****************************************************************
// //                   REQUIRED FUNCTIONALITY IN PROJECT
// //****************************************************************

// 1. You need to implement every detail of the function defined below
// 2. You additionally need to implement getInfo methods in each classes.
// 3. You additionally need to implement 'operator overloading' with '==' which compares two students whether all the members are the same




/* Functions for Student classes */

/* Base class Student */
Student::Student(){      
	Student::name = "";
	Student::stu_num = 20170000;
}

Student::Student(string stu_name, int stu_ID){
	
	Student::name = stu_name;
	Student::stu_num = stu_ID;
}

void Student::getInfo(){
	cout << "Student name is: " << Student::name << " " << std::endl;
	cout << "Student number is: " << Student::stu_num << "\n" << std::endl;
}
/* Provice interfaces to grant "some" access to private members of the class */
string Student::getLab(){
	return "no lab";
}

int Student::getClass(){
	return (-1);
}

int Student::getType(){
	return Student::type;
}

int Student::getStuNum(){
	return Student::stu_num;
}

string Student::getName(){
	return Student::name;
}

bool Student::operator ==(Student* x){
	return x->getType() == this->getType()
	    && x->getName() == this->getName()
	    && x->getStuNum() == this->getStuNum()
	    && (x->getLab() == this->getLab() || x->getClass() == this->getClass());
} 

/* Derived Grad_Student class */
Grad_Student::Grad_Student():Student(){
	Grad_Student::lab_name = "not assigned yet";
	}

Grad_Student::Grad_Student(string lab):Student(){
	Grad_Student::lab_name = lab;
}

Grad_Student::Grad_Student(string lab, string stu_name, int stu_ID):Student(stu_name, stu_ID){
	Grad_Student::lab_name = lab;
}

void Grad_Student::getInfo(){
	cout << "Student's name is: " << this->getName() << " " << std::endl;
	cout << "Student number is: " << this->getStuNum() << " " << std::endl;
	cout << "Student's lab is: " << Grad_Student::lab_name << "\n" << std::endl;
}

string Grad_Student::getLab(){
	return Grad_Student::lab_name;
}

/* Derived Undergrad_Student class */
Undergrad_Student::Undergrad_Student():Student(){
	Undergrad_Student::freshmen_class = rand() % 31;     // if this information is not given, randomly assign a class
}

Undergrad_Student::Undergrad_Student(int freshman_class):Student(){
	Undergrad_Student::freshmen_class = freshman_class;
}

Undergrad_Student::Undergrad_Student(int freshman_class, string stu_name, int stu_ID):Student(stu_name, stu_ID){
	Undergrad_Student::freshmen_class = freshman_class;
}

void Undergrad_Student::getInfo(){
	cout << "Student's name is: " << this->getName() << "\n";
	cout << "Student number is: " << this->getStuNum() << "\n";
	cout << "Student's freshmen calss is: " << Undergrad_Student::freshmen_class << "\n";
}

int Undergrad_Student::getClass(){
	return Undergrad_Student::freshmen_class;
}

/* Functions for Manager class */

/* Constructor */
Manager::Manager(){
	size = 0;
	int i;
	for (i = 0; i<300; i++){
		record[i] = NULL;
	}
}

/* Supporting function */
/* Find the first index in the record that is not storing any student */
int Manager::find_null(){   
	int i = 0;
	while(this->record[i] != NULL && i<300){
		i++;
	}
	if(i == 299){                                                // the record is full now
		return (-1);     
	}
	return i;
}

int Manager::add_student(std::string name, int stunum, std::string labname)
{
  // Adds Grad_Student object with given argument
  // Returns the total number of objects in the student array after adding
  if(size == 300){
  	std::cout<< "the record is full T_T\n" << std::endl;
  	return (-1);                                                 // Error
  }
  int index = Manager::find_null();
  if(index == -1){
  	std::cout<< "the record is full T_T\n" << std::endl;
  	return (-1);                                                 // Error
  }
  this->record[index] = new Grad_Student(labname, name, stunum);
  this->record[index]->type = 1;
  size++;
  std::cout << "add graduate student DONE" << std::endl;
  return 0;
};

int Manager::add_student(std::string name, int stunum, int freshmenclass)
{
  // Creates Undergrad_Student object with given argument
  // Returns the total number of objects in the student array after adding
  if(size == 300){
  	std::cout<< "the record is full T_T\n" << std::endl;
  	return (-1);                                                 // Error
  }
  
  int index = Manager::find_null();
  if(index == -1){
  	std::cout<< "the record is full T_T\n" << std::endl;
  	return (-1);                                                 // Error
  }
  this->record[index] = new Undergrad_Student(freshmenclass, name, stunum);
  this->record[index]->type = 0;
  size++;
  std::cout << "add undergraduate student DONE" << std::endl;
  return 0;
};

// You need to implement operator overloading and use it in compare_student ( to be done later)

bool Manager::compare_student(int index, std::string name, int stunum, int freshmenclass)
{  // to be done later 
  // Compares whether the object with given index argument in the student array is the same to Undergrad_Student object with given arguments followed by index.
  // Returns true if they are the same, false otherwise
  
  /* Double-checking the validity of index */
  if( index < 0 || index > 299){
  	std::cout << "invalid index X_X\n";
  	return false;
  }
  
  Student *p, *q;
  p = this->record[index];
  q = new Undergrad_Student(freshmenclass, name, stunum);
  int i;
  if(p == q){i = 1; }
  else{i = 0; }
  delete q;
  q = NULL;
  std::cout << "compare undergraduate student done" << std::endl;
  return (i == 1);
};

bool Manager::compare_student(int index, std::string name, int stunum, std::string labname)
{  // to be done later
  // Compares whether the (index argument)th object in the student array is the same to Grad_Student object with given given argument follwed by index.
  // Returns true if they are the same, false otherwise
  
  /* Double-checking the validity of index */
  if( index < 0 || index > 299){
  	std::cout << "invalid index X_X\n";
  	return false;
  }
  Student *p, *q;
  p = this->record[index];
  q = new Grad_Student(labname, name, stunum);
  int i;
  if(p == q){i = 1; }
  else{i = 0; }
  delete q;
  q = NULL;
 std::cout << "compare graduate student done" << std::endl;
  return (i == 1);
};

int Manager::find_student(std::string name, int stunum, std::string labname)
{
  // Finds the Grad_Student object in the student array which is the same to Grad_Student object with given argument
  // This method should print all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
  // But index in the array starts at 0 ???
  int i;
  Student* p;
  for(i = 0; i<300; i++){
  	p = this->record[i];
  	if(p != NULL && p->getType() == 1 && p->getName() == name && p->getStuNum() == stunum && p->getLab() == labname){
  		std::cout << "find graduate student DONE" << std::endl;
		return (i+1);
	  }
  }
  std::cout << "find graduate student DONE" << std::endl;
  return 0;
};

int Manager::find_student(std::string name, int stunum, int freshmenclass)
{
  // Finds the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument
  // This method should prints all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
  int i;
  Student* p;
  for(i = 0; i<300; i++){
  	p = this->record[i];
  	if(p != NULL && p->getType() == 0 && p->getName() == name && p->getStuNum() == stunum && p->getClass() == freshmenclass){
  		std::cout << p->getName() << std::endl;
  		std::cout << "find undergraduate student DONE" << std::endl;
  		return (i+1);
	  }
	}
  std::cout << "find undergraduate student DONE" << std::endl;
  return 0;
}

int Manager::delete_student(std::string name, int stunum, std::string labname)
{
  // Deletes the Grad_Student object in the student array which is the same to Grad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after 
  int index = Manager::find_student(name, stunum, labname);
  std::cout << "find done\n" << std::endl;
  if(index != 0){
  	delete Manager::record[index-1];
  	Manager::record[index-1] = NULL;
  	size--;
  }
  std::cout << "delete graduate student DONE" << std::endl;
  return 0;
}

int Manager::delete_student(std::string name, int stunum, int freshmenclass)
{
  // Deletes the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
  std::cout << "now find\n" << std::endl;
  int index = Manager::find_student(name, stunum, freshmenclass);
  std::cout << "find done\n" << std::endl;
  if(index != 0){
  	delete Manager::record[index-1];
  	Manager::record[index-1] = NULL;
  	if(Manager::record[index-1] == NULL){
  		std::cout << "NULL\n";
	  }
  	size--;
  }
  std::cout << "delete undergraduate student DONE" << std::endl;
  return 0;
};

int Manager::print_all()
{
  // Prints the all the information of existing object in the student array
  // Returns the total number of objects in the student array
  int i;
  for(i = 0; i < 300; i++){
  	if(Manager::record[i] != NULL){                    // only print those added by add_student()
  		std::cout << "Student " << (i+1) << std::endl;
  		Manager::record[i]->getInfo();                 // prints all information, dynamic binding
	  }
  }
  std::cout << "print all DONE" << std::endl;
  return 0;
};
