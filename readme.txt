*** INSTRUCTION FOR MODIFIYING THE FOLLOWING TEXT FILES: ***
*** WEIWEI SU & LINQI WANG  11/22/2016

** DEPARTMENT.TXT
LINE 1: Department ID (EXAMPLE: 020)
LINE 2: Department Name (EXAMPLE: Mathematics)

** COURSE.TXT
LINE 1: Department ID (Must Corresponds to existing information stored in Department.txt!!)
LINE 2: Course Name (EXAMPLE: Computer Logic Design)
LINE 3: Course ID (EXAMPLE: CDA3208)
LINE 4: Course Level ("0" for Undergraduate, "1" for Graduate, "2" for Doctorate)
//A DEPARTMENT CAN ONLY HAVE 50 COURSES
//A COURSE CAN ONLY HAVE 3 TEACHERS

** STUDENT.TXT
LINE 1: Department ID (Must Corresponds to existing information stored in Department.txt!!)
LINE 2: Last Name
LINE 3: First Name
LINE 4: Campus ID (We use U number)
LINE 5: Date of Birth (FORMAT: yyyy-mm-dd)
LINE 6: Sex (M or F)
LINE 7: Degree (Bachelor, Master or Doctor[PhD, M.D.])
LINE 8: Position (Teaching Assistant, Research Assistant, Student)
LINE 9: Number of Courses this student are/is taking (Number Only, No more than 6)
LINE 10: Course ID
LINE 11: Grade that corresponding to the Course ID on the last line
**NOTE**: MUST PUT SUFFICIENT COURSE ID AND GRADE BELOW LINE 9.
	  FOR EXAMPLE PUT 2 ON LINE 9 THEN MUST PUT TWO COURSE ID AND THE GRADES FOLLOW
	  BY THE FORMAT ON LINE 10 AND 11.
	  OTHERWISE THE PROGRAM MIGHT NOT WORK AS EXPECTED OR JUST CRASH OR GO BOOM.
//A STUDENT CAN ONLY TAKE 6 COURSES

** TEACHER.TXT
LINE 1: Department ID (Must Corresponds to existing information stored in Department.txt!!)
LINE 2: Last Name
LINE 3: First Name
LINE 4: Campus ID (We use U number)
LINE 5: Date of Birth (FORMAT: yyyy-mm-dd)
LINE 6: Sex (M or F))
LINE 7: Position (Professor/Lecturer/Adjunct)
LINE 8: Number of Courses this Professor/Lecturer/Adjunct are/is teaching (Number Only, No more than 6)
LINE 9: Course ID
**NOTE**: MUST PUT SUFFICIENT COURSE ID BELOW LINE 8.
//A TEACHER CAN ONLY TEACH 6 COURSES
	  FOR EXAMPLE PUT 2 ON LINE 9 THEN MUST PUT TWO COURSE ID AND THE GRADES FOLLOW
	  BY THE FORMAT ON LINE 9.
	  OTHERWISE THE PROGRAM MIGHT NOT WORK AS EXPECTED OR JUST CRASH OR GO BOOM.
