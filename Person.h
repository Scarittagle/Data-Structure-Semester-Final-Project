//Project
//Person.h
//Header file of Person.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {

private:
	string firstName;
	string lastName;
	int ID;
	string DOB;
	string Gender;

public:
	//Default Constructor
	Person();

	//Destructor
	~Person();

	//setter
	void setLastName(string last);
	void setFirstName(string first);
	void setID(int id);
	void setDOB(string dob);
	void setGender(string gender);

	//getter
	string getLastName();
	string getFirstName();
	int getID();
	string getDOB();
	string getGender();

	//Operations
	void assign(string F, string L, int ID, int CID);
	void enroll(string F, string L, int ID, int CID);

	//Display info
	void displayPersonInfo();

};

#endif
