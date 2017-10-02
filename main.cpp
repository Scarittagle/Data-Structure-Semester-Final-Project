//Project
//main.cpp
//The goal of this project is to design and implement a university administration system.
//
// WEIWEI SU & LINQI WANG @ 11/17/2016
//
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "Department.h"
#include "Course.h"
#include "Person.h"

using namespace std;

//UNIVERSAL VARIABLES
int nol; //Number of Lines
int nod; //Number of Departments
int v_temp; //TEMP VALUE
string temp;
string tpa; //TEMP STRING A
string tpb; //TEMP STRING B
string tpc; //TEMP STRING C
string tpd; //TEMP STRING D
vector<Department*>vecDepts; //List of Departments
vector<Course*>vecCourses; //List of Courses
vector<Person*>vecPersons; //List of People

int main(void) {

	//OPEN FILE//
	ifstream readfile;
	string fileName;
	/////////////

	//PRELOAD ALL REQUIRED FILES//
	//LOAD DEPARTMENT.TXT//
	cout << "LOADING FILE 'Department.txt'...." << endl;
	readfile.open("department.txt");
	if (readfile.is_open()) {
		cout << "LOAD SUCCESS." << endl;

		//Count number of lines in text file.
		temp.empty();
		nol = 0;
		while (getline(readfile, temp)) {
			++nol;
		}

		//reset getline() to the fisrt line in txt file
		readfile.clear();
		readfile.seekg(0);

		//EMPTY TEMPORAL STRING FOR FURTHER USE
		tpa.empty();
		tpb.empty();

		//scan though each line for input value
		for (int n = 1; n < nol + 1; ++n) {
			if (n % 2 == 1) {
				getline(readfile, tpa);
				n++;
			}
			if (n % 2 == 0) {
				getline(readfile, tpb);
			}

			Department *pDept = new Department(tpb, tpa);
			vecDepts.push_back(pDept);
			nod++;
		}

		//AFTER FINISHED, CLOSE FILE
		readfile.close();
	}
	else {
		cerr << "CANNOT LOAD FILE OR FILE IS MISSING." << endl;
	}
	/////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//LOAD COURSE.TXT//
	cout << "LOADING FILE 'Course.txt'...." << endl;
	readfile.open("course.txt");
	if (readfile.is_open()) {
		cout << "LOAD SUCCESS." << endl;

		//Count number of lines in text file.
		temp.empty();
		nol = 0;
		while (getline(readfile, temp)) {
			++nol;
		}
		
		//EMPTY TEMPORAL STRING FOR FURTHER USE
		tpa.empty();
		tpb.empty();
		tpc.empty();
		tpd.empty();

		//reset getline() to the fisrt line in txt file
		readfile.clear();
		readfile.seekg(0);

		//scan though each line for input value
		for (int n = 1; n < nol + 1; ++n) {
			if (n % 4 == 1) {
				//if DeptID match, add 1 to number of Courses of that Department
				getline(readfile, tpa);
				for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
					Department *pCurDept = vecDepts[i];
					if (tpa.compare(pCurDept->getDeptID()) == 0 ) {
						pCurDept->addOneCourse();
					}
				}
				n++;
			}

			//Create a Course
			if (n % 4 == 2) {
				getline(readfile, tpb);
				n++;
			}
			if (n % 4 == 3) {
				getline(readfile, tpc);
				n++;
			}
			if (n % 4 == 0) {
				getline(readfile, tpd);
			}

			Course *pCourse = new Course(tpa, tpb, tpc, tpd);
			vecCourses.push_back(pCourse);
		}

		//AFTER FINISHED, CLOSE FILE
		readfile.close();
	}
	else {
		cerr << "CANNOT LOAD FILE OR FILE IS MISSING." << endl;
	}
	/////////////////////////////
	//test output for dept
	cout << "Number of Departments in this University: " << nod << endl;
	for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
		Department *pCurDept = vecDepts[i];
		pCurDept->displayDeptInfo();
	}

	//test output
	for (int i = 0, maxNum = (int)vecCourses.size(); i < maxNum; ++i) {
		Course *pCurCourse = vecCourses[i];
		pCurCourse->displayCourseInfo();
	}

	//PROMPT USER TO SELECT FUNCTION//
	char CMD;
	//cout << "Enter COMMAND: ";
	//cin >> CMD;

	//
	

}