#pragma once
#include <string>

template <class T>
class Vector {
public:
	Vector(T first)
	{
		this->capacity = 2;
		this->size = 0;
		this->buffer = new T[capacity];
	}
	int Size();
	int Capacity();
	bool isEmpty();
	void add(T element);
	void insert(T element, int index);
	void prepend(T element);
	void pop();
	void deleteAt(int index);
	void remove(T item);
	int find(T item);
	std::string toString();
	T at(int index);
private:
	int capacity;
	T * buffer;
	int size;
	void resize();
};


template<class T>
inline void Vector<T>::resize()
{
	if (this->size == this->capacity) {
		this->capacity = capacity * 2;
		T* newBuffer = new T[capacity];
		for (int i = 0; i < size; i++) {
			newBuffer[i] = buffer[i];
		}
		delete [] buffer;
		this->buffer = newBuffer;
	} 
	else if (size <= (capacity / 4)) {
		this->capacity = capacity / 2;
		T* newBuffer = new T[capacity];
		for (int i = 0; i < size; i++) {
			newBuffer[i] = buffer[i];
		}
		delete[] buffer;
		this->buffer = newBuffer;
	}
}


template<class T>
inline void Vector<T>::add(T element)
{
	this->resize();
	this->buffer[size] = element;
	this->size++;
}

template<class T>
inline std::string Vector<T>::toString()
{
	std::string ret("[ ");
	for (int i = 0; i < this->size; i++) {
		ret.append(" ");
		T element = this->at(i);
		ret.append(std::to_string(element));
		ret.append(" ");
	}
	ret.append(" ]");
	return ret;
}

template<class T>
inline T Vector<T>::at(int index)
{
	try {
		if (index < 0 || index >= this->size) {
			throw std::out_of_range("Out of range");
		}
		T element = this->buffer[index];
		return element;
	}
	catch(std::out_of_range e) {
		cout << "exception : " << e.what() << endl;
	}
}

template<class T>
inline int Vector<T>::Size()
{
	return this->size;
}

template<class T>
inline int Vector<T>::Capacity()
{
	return this->capacity;
}

template<class T>
inline bool Vector<T>::isEmpty()
{
	return (this->size == 0) ? true : false;
}

template<class T>
inline void Vector<T>::insert(T element, int index)
{
	this->resize();
	if (index >= size) {
		this->add(element);
	} else {
		for (int i = this->size-1; i >= index; i--) {
			this->buffer[i+1] = this->buffer[i];
		}
		this->buffer[index] = element;
		size++;
	}
}

template<class T>
inline void Vector<T>::prepend(T element)
{
	this->insert(element, 0);
}

template<class T>
inline void Vector<T>::pop()
{
	this->resize();
	this->buffer[size - 1] = 0;
	this->size--;
}

template<class T>
inline void Vector<T>::deleteAt(int index)
{
	this->resize();
	for (int i = index; i < this->size; i++) {
		this->buffer[i] = this->buffer[i + 1];
	}
	this->size--;
}

template<class T>
inline void Vector<T>::remove(T item)
{
	for (int i = 0; i < this->size; i++) {
		if (this->buffer[i] == item) {
			this->deleteAt(i);
		}
	}
}

template<class T>
inline int Vector<T>::find(T item)
{
	for (int i = 0; i < this->size; i++) {
		if (this->buffer[i] == item) {
			return i;
		}
	}
	return -1;
}