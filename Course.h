//Project
//Course.h
//Header file of Course.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <vector>
#include <iostream>
#include <string>
#include "Department.h"

using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Course {

private:
	string courseID;
	string courseName;
	int numStudent;
	int numTeacher;
	int numTA;
	//enum courseLevel{ level_Undergraduate = 0, level_Graduate, level_Doctorate };
	int courseLevelint;
	int deptID;
	string strDeptID;

public:
	//vector<Student*>vecStudentList;
	//vector<Student*>vecGrade;

	//Default Constructor
	Course();

	//Copy Constructor
	Course(string m_deptID, string m_name, string m_ID, string m_Level);

	//Destructor
	~Course();

	//setter
	void setNumStudent(int numStudent);
	void setNumTeacher(int numTeacher);
	void setNumTA(int numTA);
	void setGrade(int grade);

	//getter
	int getCourseID();
	string getCourseName();
	int getNumStudent();
	int getNumTeacher();
	int getNumTA();
	int getGrade();

	//Displayinfo
	void displayCourseInfo();

};

#endif