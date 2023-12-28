/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#include "Data.h"


//constructor
Data::Data()
{
	recordNumber = 0;
	idNumber = 0;
	name = "";
	email = "";
	units = 0;
	program = "";
	level = "";

	absencesNumber = 0;
	absenceDates = new Stack;
}

//destructor
Data::~Data()
{
	cout << "Inside Data's destructor!" << endl;

}

//setters
void Data::setRecordNumber(int& newRecordNumber)
{
	recordNumber = newRecordNumber;
}

void Data::setIdNumber(int& newIdNumber)
{
	idNumber = newIdNumber;
}

void Data::setName(string& newName)
{
	name = newName;
}

void Data::setEmail(string& newEmail)
{
	email = newEmail;
}

void Data::setUnits(int& newUnits)
{
	units = newUnits;
}

void Data::setProgram(string& newProgram)
{
	program = newProgram;
}

void Data::setLevel(string& newLevel)
{
	level = newLevel;
}

void Data::setAbsencesNumber(int newAbsencesNumber)
{
	absencesNumber = newAbsencesNumber;
}

//add an absence to the stack
void Data::addAbsenceDate(string newAbsenceDate)
{
	absenceDates->push(newAbsenceDate);
	absencesNumber++;
}

//remove an absence from the stack
void Data::removeAbsenceDate(string removeAbsence)
{
	cout << "removeAbsenceDate() in class Data is not finished." << endl;
}

//getters
int Data::getRecordNumber()
{
	return recordNumber;
}

int Data::getIdNumber()
{
	return idNumber;
}

string Data::getName()
{
	return name;
}

string Data::getEmail()
{
	return email;
}

int Data::getUnits()
{
	return units;
}

string Data::getProgram()
{
	return program;
}

string Data::getLevel()
{
	return level;
}



int Data::getAbsencesNumber()
{
	return absencesNumber;
} 

Stack* Data::getAbsencesDates()
{
	return absenceDates;
}

ifstream& operator >> (ifstream& input, Data* &rhs)
{
	char tempRecord[5] = "";
	char tempId[10] = "";
	char tempName[50] = "";
	char tempEmail[50] = "";
	char tempUnits[5] = "";
	char tempProgram[5] = "";
	char tempLevel[50] = "";
	char dummy[5] = "";

	input.getline(tempRecord, 5, ',');
	input.getline(tempId, 10, '"');
	input.getline(tempName, 50, '"');
	input.getline(dummy, 5, ',');
	input.getline(tempEmail, 50, ',');
	input.getline(tempUnits, 5, ',');
	input.getline(tempProgram, 5, ',');
	input.getline(tempLevel, 50);

	int newRecordNumber = atoi(tempRecord);
	int newIdNumber = atoi(tempId);
	string newName = tempName;
	string newEmail = tempEmail;
	string newProgram = tempProgram;
	string newLevel = tempLevel;
	int newUnits = 0;

	if (tempUnits != "AU")
	{
		newUnits = atoi(tempUnits);
	}

	rhs->setRecordNumber(newRecordNumber);
	rhs->setIdNumber(newIdNumber);
	rhs->setName(newName);
	rhs->setEmail(newEmail);
	rhs->setUnits(newUnits);
	rhs->setProgram(newProgram);
	rhs->setLevel(newLevel);

	return input;
}

fstream& operator >> (fstream& input, Data* rhs)
{
	char tempAbsences[5] = "";
	input.getline(tempAbsences, 5);
	int newAbsences = atoi(tempAbsences);
	rhs->setAbsencesNumber(newAbsences);

	char tempDate[15] = "";
	string newDate = "";

	do
	{
		input.getline(tempDate, 15);
		newDate = tempDate;

		rhs->getAbsencesDates()->push(newDate);

	} while (newDate != "");

	return input;
}

fstream& operator << (fstream& output, Data* rhs)
{
	output << rhs->getAbsencesNumber() << endl;
	string* temp = rhs->getAbsencesDates()->getAbsences();

	for (int i = 1; temp[i] != ""; ++i)
	{
		output << temp[i] << endl;
	}

	output << endl;

	return output;
}


ostream& operator << (ostream& output, Data* rhs)
{
	output << rhs->getRecordNumber() << endl
		<< rhs->getIdNumber() << endl
		<< rhs->getName() << endl
		<< rhs->getEmail() << endl
		<< rhs->getUnits() << endl
		<< rhs->getProgram() << endl
		<< rhs->getLevel() << endl << endl;

	output << rhs->getAbsencesNumber() << endl;
	string* temp = rhs->getAbsencesDates()->getAbsences();

	for (int i = 1; temp[i] != ""; ++i)
	{
		output << temp[i] << endl;
	}

	output << endl;

	return output;
}