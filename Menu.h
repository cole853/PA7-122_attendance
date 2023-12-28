/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "List.h"
#include <ctime>
#include <string>

using std::cin;
using std::to_string;
using std::ofstream;

class Menu
{
public:

	//constructor
	Menu();

	//destructor
	~Menu();

	void runApp();

	int displayMenu();

	void importCourseList();

	void loadMasterList();

	void storeMasterList();

	void markAbsences();

	void generateReport();

private:

	List<Node<Data>>* masterList;

	ifstream records;

	fstream absenceFile;

	ofstream report1;

	ofstream report2;

};