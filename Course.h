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
#include <map>
#include "Department.h"

using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Course {

private:
	//Use Mapping for Student, Teacher use.
	static map<string, Course*> s_mapCourse;
	string courseID;
	string courseName;
	int numStudent;
	int numTeacher;
	int courseLevelint;
	string deptID;

	//Array to storage teacher and student and their grades.
	int s_cur = 0; //current position in the Student array
	int t_cur = 0; //current position in the Teacher array
	string array_studentList[51][3];
	string array_TeacherList[3][3];

public:
	//Default Constructor
	Course();

	//Copy Constructor
	Course(string m_deptID, string m_name, string m_CID, string m_Level);

	//Destructor
	~Course();

	//setter
	void setDeptID(string m_deptID);
	void setCourseID(string m_courseID);
	void setCourseName(string m_courseName);

	//getter
	string getDeptID();
	string getCourseID();
	string getCourseName();
	int getNumStudent();
	int getNumTeacher();

	//Display info
	void displayCourseInfo();

	//OP
	void addStudent(string m_name, string m_grade);
	void addTeacher(string m_name, string m_position);

	//Map Class
	static Course* getCourse(string strID)
	{
		auto itr = s_mapCourse.find(strID);
		if (itr == s_mapCourse.end())
		{
			return nullptr;
		}
		else
		{
			return itr->second;
		}
	}
};

#endif