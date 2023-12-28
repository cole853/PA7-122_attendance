/* 
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;


class Stack
{
public:

	//constructor
	Stack();

	//destructor
	~Stack();

	bool push(string &newAbsence);

	bool pop(string &poppedItem);

	string peek();

	bool isEmpty();

	string* getAbsences();

	void setSize(int newSize);

	int getSize();

private:

	int size;
	int maxSize;
	string* absences;
};