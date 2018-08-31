#pragma once
#include <iostream>
#include "Node.h"
#include <algorithm>

template <class T>
class LinkedList
{
public:
	Node<T>* head;
	Node<T>* first;
	Node<T>* current;
	LinkedList();
	~LinkedList();
	void add(T value);
	T at(int index);
	void pushFront(T item);
	void popFront();
	void pushBack(T item);
	void popBack();
	T front();
	T back();
	void insert(T item, int index);
	void eraseFromStart(int index);
	void eraseFromEnd(int index);
	bool isLast();
	void next();
	void setIterator();
	//void reverse();

	int Size();
	bool empty();
	void goThrough();

private:
	int size;
};


template <class T>
LinkedList<T>::LinkedList()
{
	this->size = 0;
	Node<T> headNode;
	this->current = &headNode;
	this->head = &headNode;
	this->first = &headNode;
}

template <class T>
LinkedList<T>::~LinkedList()
{
}

template <class T>
inline void LinkedList<T>::add(T value)
{
	this->head = new Node<T>(this->head, value);
	size++;
}

template<class T>
inline void LinkedList<T>::goThrough()
{
	Node<T>* parent = head;
	bool isLast = false;

	while (!isLast) {
		std::cout << parent->value << "                " << parent->next << "         " << first <<   std::endl;
		//std::cout << parent->value.key<< "-->" << parent->value.item << "                " << parent->next << "         " << first << std::endl;
		if (parent->next == first) isLast = true;
		parent = parent->next;
	}
	std::cout << "-------------------------------" << std::endl;
}

template<class T>
inline int LinkedList<T>::Size()
{
	return this->size;
}

template<class T>
inline bool LinkedList<T>::empty()
{
	if (this->size == 0) return true;
	return false;
}

template<class T>
inline T LinkedList<T>::at(int index)
{
	T ret;
	Node<T>* parent = head;
	int numIterations = std::max(this->size - index - 1, 1);
	for (int i = 0; i < numIterations; i++) {
		parent = parent->next;
		ret = parent->value;
	}
	return ret;
}

template<class T>
inline void LinkedList<T>::pushFront(T item)
{
	Node<T>* current = head;
	bool isLast = false;

	while (!isLast) {
		if (current->next == first) isLast = true;
		if (isLast) {
			Node<T> * node = new Node<T>(first, item);
			current->next = node;
			size++;
		}
		current = current->next;
	}
}

template<class T>
inline void LinkedList<T>::popFront()
{
	Node<T>* current = head;
	Node<T>* previous = current;
	bool isLast = false;

	while (!isLast) {
		if (current->next == first) isLast = true;
		
		if (isLast) {
			delete current;
			previous->next = first;
			size--;
		}
		previous = current;
		current = current->next;
	}
}

template<class T>
inline void LinkedList<T>::pushBack(T item)
{
	Node<T> * node = new Node<T>(head, item);
	this->head = node;
	size++;
}


template<class T>
inline void LinkedList<T>::popBack()
{
	Node<T> * tmp = head->next;
	delete head;
	head = tmp;
	size--;
}

template<class T>
inline T LinkedList<T>::front()
{
	return this->at(0);
}

template<class T>
inline T LinkedList<T>::back()
{
	return head->value;
}

template<class T>
inline void LinkedList<T>::insert(T item, int index)
{
	Node<T>* parent = head;
	int numIterations = this->size - index -1;
	for (int i = 0; i <= numIterations; i++) {
		if (i == numIterations) {
			Node<T> * node = new Node<T>(parent->next, item);
			parent->next = node;
			this->size++;
		}
		parent = parent->next;
	}
}

template<class T>
inline void LinkedList<T>::eraseFromStart(int index)
{
	Node<T>* parent = head;
	Node<T>* previous = parent;

	int numIterations = this->size - index -1;
	for (int i = 0; i <= numIterations; i++) {
		if (i == numIterations) {
			previous->next = parent->next;
			delete parent;
			size--;
		}
		previous = parent;
		parent = parent->next;
	}
}

template<class T>
inline void LinkedList<T>::eraseFromEnd(int index)
{
	Node<T>* parent = head;
	Node<T>* previous = parent;

	for (int i = 0; i <= index; i++) {
		if (i == index) {
			previous->next = parent->next;
			delete parent;
			size--;
		}
		previous = parent;
		parent = parent->next;
	}
}

template<class T>
inline bool LinkedList<T>::isLast()
{
	if (current->next == first) return true;
	else return false;
}

template<class T>
inline void LinkedList<T>::setIterator()
{
	current = head;
}

template<class T>
inline void LinkedList<T>::next()
{
	if (!this->isLast()) {
		this->current = this->current->next;
	}
}
//template<class T>
//inline void LinkedList<T>::reverse()
//{
//	Node<T>* current = head;
//	Node<T>* tmpFirst = first;
//
//	for (int i = 0; i < this->size; i++) {
//		Node<T>* tmp = current->next;
//		current->next = tmpFirst;
//
//		tmpFirst = current;
//		current = tmp;
//
//		std::cout << tmp << "   " << current << std::endl;
//	}
//}