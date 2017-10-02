//Project
//Teacher.h
//Header file of Teacher.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <iostream>
#include <string>

using namespace std;

#ifndef TEACHER_H
#define TEACHER_H

class Teacher {

private:
	enum position{ position_Professor = 0, position_Adjunct, position_Lecturer};

public:
	
	//Default Constructor
	Teacher();

	//Copy Constructor
	Teacher(string F, string L, int ID);

	//Destructor
	~Teacher();

	//setter
	position setPosition(position p);

	//getter
	position getPosition();
};

#endif // !TEACHER_H
