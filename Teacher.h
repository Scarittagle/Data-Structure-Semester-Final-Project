//Project
//Teacher.h
//Header file of Teacher.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include "Person.h"
#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef TEACHER_H
#define TEACHER_H

class Teacher : public Person{

private:
	string Position;
	string DeptID;

	int cur = 0; //current position in courselist
	string courselist[7];

public:
	
	//Default Constructor
	Teacher();

	//Copy Constructor
	Teacher(string F, string L, string ID, string position);

	//Destructor
	~Teacher();

	//setter
	void addCourse(string m_addcourse);
	void setPosition(string p);
	void setDeptID(string m_deptID);

	//getter
	string getPosition();

	//Display Info
	void displayInfo();
};

#endif // !TEACHER_H
