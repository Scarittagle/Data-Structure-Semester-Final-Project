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
#include <sstream>

#include "Department.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

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
string tpe; //TEMP STRING E
string tpf; //TEMP STRING F
string tpg; //TEMP STRING G
string tph; //TEMP STRING H
string tpi; //TEMP STRING I
vector<Department*>vecDepts; //List of Departments
vector<Course*>vecCourses; //List of Courses
vector<Student*>vecStudentList; //List of Students
vector<Teacher*>vecTeacherList; //List of Teachers
vector<Student*>vecGrade; //List of Student's Grade

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
			for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
				Department *pCurDepartment = vecDepts[i];
				if (tpa.compare(pCurDepartment->getDeptID()) == 0) {
					pCurDepartment->addCourse(tpc, tpb);
				}
			}
			vecCourses.push_back(pCourse);
		}

		//AFTER FINISHED, CLOSE FILE
		readfile.close();
	}
	else {
		cerr << "CANNOT LOAD FILE OR FILE IS MISSING." << endl;
	}

	//LOAD STUDENT.TXT//
	cout << "LOADING FILE 'Student.txt'...." << endl;
	readfile.open("student.txt");
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
		tpc.empty();
		tpd.empty();
		tpe.empty();
		tpf.empty();
		tpg.empty();
		tph.empty();
		tpi.empty();

		//scan though each line for input value
		for (int n = 1; n < nol + 1; ++n) {
			if (n % 9 == 1) {
				//if DeptID match, add 1 to number of Person of that Department
				getline(readfile, tpa);
				for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
					Department *pCurDept = vecDepts[i];
					if (tpa.compare(pCurDept->getDeptID()) == 0) {
						pCurDept->addOnePerson();
					}
				}
				n++;
			}

			//Create a Student
			if (n % 9 == 2) {
				getline(readfile, tpb);
				n++;
			}
			if (n % 9 == 3) {
				getline(readfile, tpc);
				n++;
			}
			if (n % 9 == 4) {
				getline(readfile, tpd);
				n++;
			}
			if (n % 9 == 5) {
				getline(readfile, tpe);
				n++;
			}
			if (n % 9 == 6) {
				getline(readfile, tpf);
				n++;
			}
			if (n % 9 == 7) {
				getline(readfile, tpg);
				n++;
			}
			if (n % 9 == 8) {
				getline(readfile, tph);
				n++;
			}

			Student *pStudent = new Student(tpb, tpc, tpd, tpg);
			pStudent->setDOB(tpe);
			pStudent->setGender(tpf);
			pStudent->setDeptID(tpa);
			pStudent->setPosition(tph);

			//EMPTY TEMPORAL STRING FOR FURTHER USE
			tpa.empty();
			tpe.empty();
			tpf.empty();

			//Assign Student to a Course and Store grades, Also store courses into Student object,
			//Number of Courses should no more than 6.
			int numofcourse = 0;
			if (n % 9 == 0) {
				getline(readfile, tpa);
				stringstream convertnoc(tpa);
				convertnoc >> numofcourse;
				for (int j = 1; j <= numofcourse; ++j) {
					getline(readfile, tpe);
					getline(readfile, tpf);
					pStudent->addCourse(tpe);
					for (int i = 0, maxNum = (int)vecCourses.size(); i < maxNum; ++i) {
						Course *pCurCourse = vecCourses[i];
						if (tpe.compare(pCurCourse->getCourseID()) == 0) {
							string fullname;
							string space = " ";
							fullname = tpc + space + tpb + space + tpd;
							pCurCourse->addStudent(fullname, tpf);
						}
					}
				}
			}

			//EMPTY TEMPORAL STRING FOR NEXT ENTRY
			tpa.empty();
			tpb.empty();
			tpc.empty();
			tpd.empty();
			tpe.empty();
			tpf.empty();
			
			//reset counter
			nol = nol - (n + (numofcourse * 2));
			n = 0;


			vecStudentList.push_back(pStudent);
		}
		
		//AFTER FINISHED, CLOSE FILE
		readfile.close();
	}
	else {
		cerr << "CANNOT LOAD FILE OR FILE IS MISSING." << endl;
	}
	/////////////////////////////

	//LOAD TEACHER.TXT//
	cout << "LOADING FILE 'Teacher.txt'...." << endl;
	readfile.open("teacher.txt");
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
		tpc.empty();
		tpd.empty();
		tpe.empty();
		tpf.empty();
		tpg.empty();
		tph.empty();
		tpi.empty();

		//scan though each line for input value
		for (int n = 1; n < nol + 1; ++n) {
			if (n % 8 == 1) {
				//if DeptID match, add 1 to number of Person of that Department
				getline(readfile, tpa);
				for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
					Department *pCurDept = vecDepts[i];
					if (tpa.compare(pCurDept->getDeptID()) == 0) {
						pCurDept->addOnePerson();
					}
				}
				n++;
			}

			//Create a Teacher
			if (n % 8 == 2) {
				getline(readfile, tpb);
				n++;
			}
			if (n % 8 == 3) {
				getline(readfile, tpc);
				n++;
			}
			if (n % 8 == 4) {
				getline(readfile, tpd);
				n++;
			}
			if (n % 8 == 5) {
				getline(readfile, tpe);
				n++;
			}
			if (n % 8 == 6) {
				getline(readfile, tpf);
				n++;
			}
			if (n % 8 == 7) {
				getline(readfile, tpg);
				n++;
			}

			Teacher *pTeacher = new Teacher(tpb, tpc, tpd, tpg);
			pTeacher->setDOB(tpe);
			pTeacher->setGender(tpf);
			pTeacher->setDeptID(tpa);

			//EMPTY TEMPORAL STRING FOR FURTHER USE
			tpa.empty();
			tpe.empty();
			tpf.empty();


			//Assign Teacher to a Course
			int numofcourse = 0;
			if (n % 8 == 0) {
				getline(readfile, tpa);
				stringstream convertnoc(tpa);
				convertnoc >> numofcourse;
				if (numofcourse > 6) {
					cerr << "Number of Courses should no more than 6." << endl;
				}
				for (int j = 1; j <= numofcourse; ++j) {
					getline(readfile, tpe);
					pTeacher->addCourse(tpe);
					for (int i = 0, maxNum = (int)vecCourses.size(); i < maxNum; ++i) {
						Course *pCurCourse = vecCourses[i];
						if (tpe.compare(pCurCourse->getCourseID()) == 0) {
							string fullname;
							string space = " ";
							fullname = tpc + space + tpb;
							pCurCourse->addTeacher(fullname, tpg);
						}
					}
				}
			}

			//EMPTY TEMPORAL STRING FOR NEXT ENTRY
			tpa.empty();
			tpb.empty();
			tpc.empty();
			tpd.empty();
			tpe.empty();
			tpf.empty();
			tpg.empty();

			//reset counter
			nol = nol - (n + numofcourse);
			n = 0;


			vecTeacherList.push_back(pTeacher);
		}

		//AFTER FINISHED, CLOSE FILE
		readfile.close();
	}
	else {
		cerr << "CANNOT LOAD FILE OR FILE IS MISSING." << endl;
	}
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////
	//test output for dept list
	cout << "Number of Departments in this University: " << nod << endl;
	for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
		Department *pCurDept = vecDepts[i];
		pCurDept->displayDeptInfo();
	}

	//test output for course list
	for (int i = 0, maxNum = (int)vecDepts.size(); i < maxNum; ++i) {
		Course *pCurCourse = vecCourses[i];
		pCurCourse->displayCourseInfo();
	}

	//test output for student list
	for (int i = 0, maxNum = (int)vecStudentList.size(); i < maxNum; ++i) {
		Student *pCurStudent = vecStudentList[i];
		pCurStudent->displayInfo();
	}

	//test output for Teacher list
	for (int i = 0, maxNum = (int)vecTeacherList.size(); i < maxNum; ++i) {
		Teacher *pCurTeacher = vecTeacherList[i];
		pCurTeacher->displayInfo();
	}

	//1) Printing information of a student object
	cout << "1) Printing information of a student object" << endl;
	Student *ptestStudent = vecStudentList[0];
	ptestStudent->displayInfo();

	//2) Printing information of a teacher object.
	cout << "2) Printing information of a teacher object." << endl;
	Teacher *ptestTeacher = vecTeacherList[0];
	ptestTeacher->displayInfo();

	//3) Printing information of a student object through a person object.	//not sure what that mean tho.
	Person *ptestPerson1 = vecStudentList[1];
	ptestPerson1->displayInfo();

	//4) Printing information of a teacher object through a person object.
	//not sure what that mean either.
	Person *ptestPerson2 = vecTeacherList[0];
	ptestPerson2->displayInfo();

	//5) Printing student's names and IDs who are enrolled in a course.	//included on that test course list.

	//6) Printing course names in which a student is enrolled in.	//included on that test student list.

	//7) Printing teachers assigned to a course
	//that operation is done thu modifying txt file.

	//8) Printing courses that a teacher teaches
	//included on that test teacher list.

	//9) Printing all teachers, students or courses of a department,
	//per restriction on late-posted guideline, I only managed to figure out printing all courses of a
	//department.
	//included on that test department list.
}