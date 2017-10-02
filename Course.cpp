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

map<string, Course*> Course::s_mapCourse;

Course::Course(string m_deptID, string m_name, string m_CID, string m_Level)
{
	//Setup Course Basic Info
	setCourseName(m_name);
	setCourseID(m_CID);
	setDeptID(m_deptID);

	if (s_mapCourse.find(m_CID) == s_mapCourse.end())
	{
		s_mapCourse[m_CID] = this;
	}

	//NEED TO CONVERT STRING TO INT FOR COMPARISON
	stringstream convertcl(m_Level); //Course Level
	convertcl >> courseLevelint;

	//initialize variables
	numStudent = 0;
	numTeacher = 0;
}

Course::Course()
{
	//Default Constructor
}

Course::~Course()
{
	//Destructor
}

void Course::setDeptID(string m_deptID)
{
	deptID = m_deptID;
}

void Course::setCourseID(string m_courseID)
{
	courseID = m_courseID;
}

void Course::setCourseName(string m_courseName)
{
	courseName = m_courseName;
}

std::string Course::getDeptID()
{
	return deptID;
}

std::string Course::getCourseID()
{
	return courseID;
}

std::string Course::getCourseName()
{
	return courseName;
}

int Course::getNumStudent()
{
	return numStudent;
}

int Course::getNumTeacher()
{
	return numTeacher;
}

void Course::addStudent(string m_name, string m_grade)
{
	array_studentList[s_cur][1] = m_name;
	array_studentList[s_cur][2] = m_grade;
	s_cur++;
	numStudent++;
}

void Course::addTeacher(string m_name, string m_position)
{
	array_TeacherList[t_cur][1] = m_name;
	array_TeacherList[t_cur][2] = m_position;
	t_cur++;
	numTeacher++;
}

void Course::displayCourseInfo()
{
	cout << "//////////////////////////////////////////////////////////////////" << endl;
	cout << "CourseID: " << getCourseID() << endl;
	cout << "Course Name: " << getCourseName() << endl;
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
	cout << "Number of Student: " << getNumStudent() << endl;
	cout << "Number of Teacher: " << getNumTeacher() << endl;
	cout << "Department: " << Department::getDepartment(deptID)->getDeptName() << endl;
	cout << "Student in this Class: " << endl;
	for (int i = 0; i < s_cur; i++) {
		cout << array_studentList[i][1] << ", Grade: " << array_studentList[i][2] << endl;
	}
	cout << "Teacher in this Class: " << endl;
	for (int i = 0; i < s_cur; i++) {
		cout << array_TeacherList[i][2] << ' ' << array_TeacherList[i][1] << endl;
	}
	cout << "//////////////////////////////////////////////////////////////////" << endl;
}


