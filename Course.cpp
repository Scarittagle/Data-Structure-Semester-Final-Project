//Project
//course.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "Course.h"

using namespace std;

Course::Course(string m_deptID, string m_name, string m_ID, string m_Level)
{
	//Setup Course Basic Info
	courseName = m_name;
	courseID = m_ID;

	//NEED TO CONVERT STRING TO INT FOR COMPARISON
	stringstream convertcl(m_Level); //Course Level
	convertcl >> courseLevelint;

	strDeptID = m_deptID;
	stringstream convertdeptID(m_deptID); //Department ID
	convertdeptID >> deptID;

	//initialize variables
	numStudent = 0;
	numTeacher = 0;
	numTA = 0;
}

Course::Course()
{
	//Default Constructor
}

Course::~Course()
{
	//Destructor
}

void Course::displayCourseInfo()
{
	cout << "//////////////////////////////////////////////////////////////////" << endl;
	cout << "CourseID: " << courseID << endl;
	cout << "Course Name: " << courseName << endl;
	cout << "Course Level: ";
	switch (courseLevelint) {
	case 0:
		cout << "Undergraduate" << endl;
		break;
	case 1:
		cout << "Graduate" << endl;
		break;
	case 2:
		cout << "Doctorate" << endl;
		break;
	}

	cout << "Department: " << Department::getDepartment(strDeptID)->getDeptName() << endl;
	cout << "//////////////////////////////////////////////////////////////////" << endl;
}
