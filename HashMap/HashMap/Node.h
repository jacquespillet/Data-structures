#pragma once
template <class T>
class Node
{
public:
	T value;
	Node<T>* next;
	Node(Node<T> *next, T value);
	Node();
	~Node();

	bool isHead();
};

template<class T>
inline Node<T>::Node(Node * next, T value)
{
	this->next = next;
	this->value = value;
}

template<class T>
inline Node<T>::Node()
{
}

template<class T>
inline Node<T>::~Node()
{
}

template<class T>
inline bool Node<T>::isHead()
{
	if (next == NULL) {
		return true;
	}
	return false;
}
