/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#include "Stack.h"

//constructor
Stack::Stack()
{
	size = 1;
	maxSize = 100;
	absences = new string[100];
}

//destructor
Stack::~Stack()
{
	cout << "Inside Stack's destructor!" << endl;
}

bool Stack::push(string &newAbsence)
{
	if (size != maxSize)
	{
		absences[size] = newAbsence;
		size++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(string &poppedItem)
{
	if (!isEmpty())
	{
		size--;
		poppedItem = absences[size];
		return true;
	}
	else
	{
		return false;
	}
}

string Stack::peek()
{
	return absences[size - 2];
}

bool Stack::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string* Stack::getAbsences()
{
	return absences;
}

void Stack::setSize(int newSize)
{
	size = newSize;
}

int Stack::getSize()
{
	return size;
}