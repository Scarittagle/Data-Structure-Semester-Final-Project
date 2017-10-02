//Project
//Student.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <vector>
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(string L, string F, string ID, string degree) : Person(L, F, ID) 
{
	setDegree(degree);
}

Student::Student()
{
	//default constructor
}

Student::~Student()
{
	//destructor
}

void Student::setDeptID(string m_deptID)
{
	DeptID = m_deptID;
}

void Student::setPosition(string m_position)
{
	Position = m_position;
}

void Student::setDegree(string m_degree)
{
	Degree = m_degree;
}

void Student::addCourse(string m_addcourse)
{
	courselist[cur] = m_addcourse;
	cur++;
}

std::string Student::getPosition()
{
	return Position;
}

std::string Student::getDegree()
{
	return Degree;
}

void Student::displayInfo()
{
	Person::displayInfo();
	cout << "Degree: " << getDegree() << endl;
	cout << "Position: " << getPosition() << endl;
	cout << "Department: " << Department::getDepartment(DeptID)->getDeptName() << endl;
	cout << "Courses this person taking: " << endl;
	for (int i = 0; i < cur; i++) {
		cout << courselist[i] << "\t" << Course::getCourse(courselist[i])->getCourseName() << endl;
	}
	cout << "//////////////////////////////////////////////////////////////////" << endl;
}