//Project
//Student.h
//Header file of Student.cpp
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

#ifndef STUDENT_H
#define STUDENT_H

class Student : public Person {
private:
	string Position;
	string Degree;
	string DeptID;

	int cur = 0; //current position in courselist
	string courselist[7];

public:

	//Default Constructor
	Student();

	//Copy Constructor
	Student(string F, string L, string ID, string degree);

	//Destructor
	~Student();

	//Display Info
	void displayInfo();

	//setter
	void setDeptID(string m_deptID);
	void setPosition(string m_position);
	void setDegree(string m_degree);
	void addCourse(string m_addcourse);

	//getter
	string getPosition();
	string getDegree();
};

#endif