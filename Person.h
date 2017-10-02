//Project
//Person.h
//Header file of Person.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include "Department.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {

protected:
	string firstName;
	string lastName;
	string ID;
	string DOB;
	string Gender;

public:
	//Default Constructor
	Person();

	//Copy Constructor
	Person(string m_last, string m_first, string m_ID);

	//Destructor
	~Person();

	//setter
	void setLastName(string last);
	void setFirstName(string first);
	void setID(string m_id);
	void setDOB(string m_dob);
	void setGender(string m_gender);

	//getter
	string getLastName();
	string getFirstName();
	string getID();
	string getDOB();
	string getGender();

	//Display info
	void displayInfo();

};

#endif
