//Project
//Department.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <vector>
#include <iostream>
#include "Department.h"

using namespace std;

map<string, Department*> Department::s_mapDepartment;

Department::Department(string m_name, string m_deptID)
{
	//Setup Department's Name
	DeptName = m_name;

	//Setup Department ID
	departmentID = m_deptID;

	//Initialize Number of People and Courses.
	numPeople = 0;
	numCourse = 0;

	if (s_mapDepartment.find(m_deptID) == s_mapDepartment.end())
	{
		s_mapDepartment[m_deptID] = this;
	}
}


Department::Department()
{
	//Default Constructor
}

Department::~Department()
{
	//Destructor
}

void Department::addOneCourse()
{
	numCourse++;
}

void Department::addOnePerson()
{
	numPeople++;
}

std::string Department::getDeptID()
{
	return departmentID;
}

std::string Department::getDeptName()
{
	return DeptName;
}

void Department::displayDeptInfo()
{
	cout << "//////////////////////////////////////////////////////////////////" << endl;
	cout << "Department Name: " << DeptName << endl;
	cout << "Department ID: " << departmentID << endl;
	cout << "Number of People: " << numPeople << endl;
	cout << "NUmber of Courses: " << numCourse << endl;
	cout << "//////////////////////////////////////////////////////////////////" << endl;
}

