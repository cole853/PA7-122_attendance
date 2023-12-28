/*
		Programmer: Cole Clark
		Date: 4/6/2021

			Description: application to manage attendance for PA7
*/

#pragma once

#include "Data.h"

template <class T>
class Node
{
public:

	//constructor
	Node();

	//destructor
	~Node();

	//setters
	void setData(T* newData);

	void setNext(Node* newNext);

	//getters
	T* getData();

	Node* getNext();


private:

	T* data;

	Node* next;

};


//constructor
template <class T>
Node<T>::Node()
{
	data = nullptr;
	next = nullptr;
}

//destructor
template <class T>
Node<T>::~Node()
{
	cout << "Inside Node's destructor!" << endl;
}

//setters
template <class T>
void Node<T>::setData(T* newData)
{
	data = newData;
}

template <class T>
void Node<T>::setNext(Node* newNext)
{
	next = newNext;
}

//getters
template <class T>
T* Node<T>::getData()
{
	return data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}