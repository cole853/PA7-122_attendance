/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/


#pragma once

#include "Stack.h"
#include <fstream>

using std::fstream;
using std::ifstream;
using std::ostream;

class Data
{
public:

	//constructor
	Data();

	//destructor
	~Data();

	//setters
	void setRecordNumber(int& newRecordNumber);
	void setIdNumber(int& newIdNumber);
	void setName(string& newName);
	void setEmail(string& newEmail);
	void setUnits(int& newUnits);
	void setProgram(string& newProgram);
	void setLevel(string& newLevel);

	void setAbsencesNumber(int newAbsencesNumber);

	//add an absence to the stack
	void addAbsenceDate(string newAbsenceDate);

	//remove an absence from the stack
	void removeAbsenceDate(string removeAbsence);

	//getters
	int getRecordNumber();
	int getIdNumber();
	string getName();
	string getEmail();
	int getUnits();
	string getProgram();
	string getLevel();

	int getAbsencesNumber();
	Stack* getAbsencesDates();

private:

	int recordNumber;
	int idNumber;
	string name;
	string email;
	int units;
	string program;
	string level;

	int absencesNumber;
	Stack* absenceDates;
};

ifstream& operator >> (ifstream& input, Data* &rhs);

fstream& operator >> (fstream& input, Data* rhs);

fstream& operator << (fstream& output, Data* rhs);

ostream& operator << (ostream& output, Data* rhs);