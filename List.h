/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#pragma once

#include "Node.h"

template <class T>
class List
{
public:

	List();

	~List();

	void insertNode(T* newNode);

	//setters
	void setHead(T* newHead);

	void setTail(T* newTail);

	//getters
	T* getHead();

	T* getTail();


	bool isEmpty();

private:

	T* head;

	T* tail;

};

//constructor
template <class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;

}

//destructor
template <class T>
List<T>::~List()
{
	cout << "Inside List's destructor! Deleting all Nodes" << endl;

	while (head != nullptr)
	{
		T* temp = head;
		head = head->getNext();

		delete temp->getData()->getAbsencesDates();
		delete temp->getData();
		delete temp;

		tail = nullptr;
	}
}

//setters
template <class T>
void List<T>::setHead(T* newHead)
{
	head = newHead;
}

template <class T>
void List<T>::setTail(T* newTail)
{
	tail = newTail;
}

//getters
template <class T>
T* List<T>::getHead()
{
	return head;
}

template <class T>
T* List<T>::getTail()
{
	return tail;
}

template <class T>
void List<T>::insertNode(T* newNode)
{
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		T* temp = head;
		head = newNode;
		head->setNext(temp);
	}
}


template <class T>
bool List<T>::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}