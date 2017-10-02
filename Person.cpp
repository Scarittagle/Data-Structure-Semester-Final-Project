//Project
//Person.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <vector>
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
	//Default Constructor
}

Person::Person(string m_last, string m_first, string m_ID)
{
	//initialize object
	setLastName(m_last);
	setFirstName(m_first);
	setID(m_ID);
}

Person::~Person()
{
	//Destructor
}

void Person::setLastName(string last)
{
	lastName = last;
}

void Person::setFirstName(string first)
{
	firstName = first;
}

void Person::setID(string m_id)
{
	ID = m_id;
}

void Person::setDOB(string m_dob)
{
	DOB = m_dob;
}

void Person::setGender(string m_gender)
{
	Gender = m_gender;
}

std::string Person::getLastName()
{
	return lastName;
}

std::string Person::getFirstName()
{
	return firstName;
}

std::string Person::getID()
{
	return ID;
}

std::string Person::getDOB()
{
	return DOB;
}

std::string Person::getGender()
{
	return Gender;
}

void Person::displayInfo()
{
	cout << "//////////////////////////////////////////////////////////////////" << endl;
	cout << "Name: " << getLastName() << ", " << getFirstName() << endl;
	cout << "UID: " << getID() << endl;
	cout << "Date of Birth: " << getDOB() << endl;
	cout << "Gender: " << getGender() << endl;
}
