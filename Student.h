//Project
//Student.h
//Header file of Student.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <iostream>
#include <string>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
	enum position { position_researchAssistant = 0, position_teachingAssistant };
	enum degree { degree_Bachelor = 0, degree_Master, degree_Doctorate };
public:

	//Default Constructor
	Student();

	//Copy Constructor
	Student(string F, string L, int ID);

	//Destructor
	~Student();

	//setter
	void setPosition(position p);
	void setDegree(degree d);

	//getter
	position getPosition();
	degree getDegree();
};

#endif