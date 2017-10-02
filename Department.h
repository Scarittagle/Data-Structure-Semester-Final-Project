//Project
//Department.h
//Header file of Department.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department 
{
private:
	static map<string, Department*> s_mapDepartment;

public:
	static Department* getDepartment(string strID)
	{
		auto itr = s_mapDepartment.find(strID);
		if (itr == s_mapDepartment.end())
		{
			return nullptr;
		}
		else
		{
			return itr->second;
		}
	}

private:
	string DeptName;
	string departmentID;
	int numCourse;
	int numPeople;

public:

	//Default constructor
	Department();

	//Copy Constructor
	Department(string m_name, string m_deptID);

	//Destructor
	~Department();

	//setter
	void addOneCourse();
	void addOnePerson();

	//getter
	string getDeptID();
	string getDeptName();

	//DisplayResult
	void displayDeptInfo();

};

#endif