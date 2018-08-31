#pragma once
#include <string>

template <class T>
class CircularBuffer
{
public:
	CircularBuffer(int capacity);

	~CircularBuffer();
	void add(int val);
	void remove();
	std::string toString();
private:
	int capacity;
	int startValid;
	int endValid;
	T* buffer;
	bool willOverwrite = false;
};


template <class T>
CircularBuffer<T>::CircularBuffer(int capacity)
{
	this->capacity = capacity;
	this->startValid = (int) capacity / 2;
	this->endValid = this->startValid;
	this->buffer = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		buffer[i] = 0;
	}
}

template <class T>
CircularBuffer<T>::~CircularBuffer()
{
}

template<class T>
inline void CircularBuffer<T>::add(int val)
{
	if (endValid == capacity) {
		endValid = 0;
		willOverwrite = true;
	}
	if (endValid == startValid && willOverwrite) {
		startValid++;
	}

	this->buffer[endValid] = val;
	endValid++;
}

template<class T>
inline void CircularBuffer<T>::remove()
{
	this->buffer[startValid] = 0;
	startValid++;

	if (startValid == capacity) {
		startValid = 0;
	}
	if (startValid == endValid && this->willOverwrite) {
		willOverwrite = false;
	}
}

template<class T>
inline std::string CircularBuffer<T>::toString()
{
	std::string ret("[ ");
	for (int i = 0; i < this->capacity; i++) {
		ret.append(" ");
		T element = this->buffer[i];
		ret.append(std::to_string(element));
		ret.append(" ");
	}
	ret.append(" ]");
	return ret;
}