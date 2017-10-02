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
	setDeptName(m_name);

	//Setup Department ID
	setDeptID(m_deptID);

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

void Department::setDeptID(string m_deptID)
{
	departmentID = m_deptID;
}

void Department::setDeptName(string m_name)
{
	DeptName = m_name;
}

void Department::addCourse(string m_CID, string m_Coursename)
{
	array_courselist[cur][1] = m_CID;
	array_courselist[cur][2] = m_Coursename;
	cur++;
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
	cout << "Department Name: " << getDeptName() << endl;
	cout << "Department ID: " << getDeptID() << endl;
	cout << "Number of People: " << numPeople << endl;
	cout << "NUmber of Courses: " << numCourse << endl;
	cout << "Course List: " << endl;
	for (int i = 0; i < cur; i++) {
		cout << array_courselist[i][1] << ' ' << array_courselist[i][2] << endl;
	}
	cout << "//////////////////////////////////////////////////////////////////" << endl;
}

