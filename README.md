# PA7-122_attendance
Attendance recording system for CPTS 122 programming assignment 7. Completed on 4/6/2021.

This program allows the user to mark students absent or present, load students from the Records.csv file, load absences from the Master.txt file, store the updated absences to Master.txt, generate a report for all students, generate a report for students with more than a user input number of absences, or exit.

# Eleven Files Are Required:

Stack.h: contains the Stack class which is a stack of strings.

Stack.cpp: contains definitions for Stack class functions.

Data.h: contains the Data class which stores information for each student when it is loaded from the Records.csv file. Absence dates are kept as a stack in this class.

Data.cpp: contains definitions for Data class functions.

Node.h: contains the Node template class and definitions for Node class functions.

List.h: contains the List template class and definitions for List class functions.

Menu.h: contains the Menu class where a list of student data is modified.

Menu.cpp: contains definitions for Menu class functions.

Main.cpp: contains the main function for the program where Menu.runApp() is called.

Records.csv: contains student information.

Master.txt: contains absence dates for each student.

# Possible Improvements

The user should be able to edit absences if a mistake is made. This could be done by adding a function to the Menu.

The stack class could be a template class to make it easier to use for future updates.
