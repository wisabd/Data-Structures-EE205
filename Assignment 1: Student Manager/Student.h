// //***************************************************************
// //                   CLASS USED IN PROJECT
// //****************************************************************


/*********************************/
/* To be finished: */
/* Operator overloading, delete some debugging print statements, debug T_T */
/*********************************/
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/* Pre-define some values, subject to changes */

class Student{
	// ******Modify here******
	// You need to properly define member variable in Student class
 private:
 	string name;
 	int stu_num;
 	int type;                // Undergraduate 0, Graduate 1
 protected:
 public:
	// ******Modify here******
	// You need to implement get function which prints out every information about student argument in pure virtual function here
	
	/* Constructor */
	Student();
	Student(string stu_name, int stu_ID);
	
	/* virtual function getinfo() */
	virtual void getInfo();
	
	/* Supporting functions */
	virtual int getClass();
	virtual string getLab();
	int getType();
	string getName();
	int getStuNum();
	
	/* Operator overloading */
	bool operator == (Student* x);
	
 friend class Manager;
	};


class Grad_Student: public Student{
	// ******Modify here******
	// You need to properly define member variable in Grad_Student class
 private:
 	string lab_name;
 protected:
 public:	
	// ******Modify here******
	// You need to implement get function in detail
	
	/* Constructor */
	Grad_Student();
	Grad_Student(string lab);
	Grad_Student(string lab, string stu_name, int stu_ID);
	
	void getInfo();
	string getLab();
};

class Undergrad_Student: public Student{
	// ******Modify here******
	// You need to properly define member variable in Undergrad_Student class
 private:
 	int freshmen_class;       // I'm assuming it is similar to KAIST
 protected:
 public:
	// ******Modify here******
	// You need to implement get function in detail
	
	/* Constructor */
	Undergrad_Student();
	Undergrad_Student(int freshman_class);
	Undergrad_Student(int freshman_class, string stu_name, int stu_ID);
	
	void getInfo();
	int getClass();
};

class Manager{
	// ******Modify here******
	// You need to properly define member variable in Manager class
 private:
 	Student* record[300];          // array holding pointers to Student objects
 	int size;                      // number of registered students
 protected:
 public:
 	
	// ******Modify here******
	// You need to implement every methods in Manager class
	int add_student(std::string name, int stunum, std::string labname);
	int add_student(std::string name, int stunum, int freshmenclass);
	bool compare_student(int index, std::string name, int stunum, std::string labname);
	bool compare_student(int index, std::string name, int stunum, int freshmenclass);
	int find_student(std::string name, int stunum, std::string labname);
	int find_student(std::string name, int stunum, int freshemenclass);
	int delete_student(std::string name, int stunum, std::string labname);
	int delete_student(std::string name, int stunum, int freshmenclass);
	int print_all();
	
	// Constructor
	Manager();
	
	int find_null();
};

