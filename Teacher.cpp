//Project
//Teacher.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include "Teacher.h"
#include <vector>
#include <iostream>

using namespace std;

Teacher::Teacher()
{
	//Default constructor
}

Teacher::Teacher(string F, string L, string ID, string position) : Person(F, L, ID) {
	setPosition(position);
}

Teacher::~Teacher()
{
	//Destructor
}

void Teacher::addCourse(string m_addcourse)
{
	courselist[cur] = m_addcourse;
	cur++;
}

void Teacher::setPosition(string p)
{
	Position = p;
}

void Teacher::setDeptID(string m_deptID)
{
	DeptID = m_deptID;
}

std::string Teacher::getPosition()
{
	return Position;
}

void Teacher::displayInfo()
{
	Person::displayInfo();
	cout << "Position: " << getPosition() << endl;
	cout << "Department: " << Department::getDepartment(DeptID)->getDeptName() << endl;
	cout << "Courses this " << getPosition() << " is teaching: " << endl;
	for (int i = 0; i < cur; i++) {
		cout << courselist[i] << "\t" << Course::getCourse(courselist[i])->getCourseName() << endl;
	}
	cout << "//////////////////////////////////////////////////////////////////" << endl;
}

