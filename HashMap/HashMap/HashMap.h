#pragma once
#include "LinkedList.h"


template <class KeyType, class ItemType>
class HashMap
{
public:
	HashMap();
	~HashMap();
	void add(KeyType key, ItemType item);
	ItemType get(KeyType key);
	bool exists(KeyType key);
	void remove(KeyType key);

private:
	void resize();
	struct NodeStruct { KeyType key; ItemType item;};
	LinkedList<NodeStruct> * buffer;
	int size;
	int capacity;
};

template<class KeyType, class ItemType>
inline HashMap<KeyType, ItemType>::HashMap()
{
	this->capacity = 8;
	this->size = 0;
	this->buffer = new LinkedList<NodeStruct>[capacity];
}

template<class KeyType, class ItemType>
inline HashMap<KeyType, ItemType>::~HashMap()
{
}

template<class KeyType, class ItemType>
inline void HashMap<KeyType, ItemType>::add(KeyType key, ItemType item)
{
	this->resize();

	std::hash<KeyType> hash_fn;
	size_t hash = hash_fn(key) % (this->capacity - 1);
	struct NodeStruct node; node.key = key; node.item = item;

	LinkedList<NodeStruct>* list = &this->buffer[hash];
	bool alreadyExists = false;
	if (list->Size() > 0) {
		list->setIterator();
		do {
			if (list->current->value.key == key) {
				alreadyExists = true;
				break;
			}
			list->next();
		} while (!list->isLast());
		
		if (alreadyExists) {
			list->current->value = node;
		}
	}
	if (!alreadyExists) {
		list->add(node);
		this->size++;
	}
}

template<class KeyType, class ItemType>
inline ItemType HashMap<KeyType, ItemType>::get(KeyType key)
{
	std::hash<KeyType> hash_fn;
	size_t hash = hash_fn(key) % (this->capacity - 1);
	NodeStruct res;
	LinkedList<NodeStruct>* list = &this->buffer[hash];
	if (list->Size() > 0) {
		list->setIterator();
		do {
			if (list->current->value.key == key) {
				res = list->current->value;
				break;
			}
			list->next();
		} while (!list->isLast());
	}

	return res.item;
}

template<class KeyType, class ItemType>
inline bool HashMap<KeyType, ItemType>::exists(KeyType key)
{
	std::hash<KeyType> hash_fn;
	size_t hash = hash_fn(key) % (this->capacity - 1);
	NodeStruct res;
	LinkedList<NodeStruct>* list = &this->buffer[hash];
	bool exists = false;
	if (list->Size() > 0) {
		list->setIterator();
		do {
			if (list->current->value.key == key) {
				exists = true;
				break;
			}
			list->next();
		} while (!list->isLast());
	}
	return exists;
}

template<class KeyType, class ItemType>
inline void HashMap<KeyType, ItemType>::remove(KeyType key)
{
	int index = 0;
	std::hash<KeyType> hash_fn;
	size_t hash = hash_fn(key) % (this->capacity - 1);
	NodeStruct res;
	LinkedList<NodeStruct>* list = &this->buffer[hash];
	bool exists = false;
	if (list->Size() > 0) {
		list->setIterator();
		do {
			if (list->current->value.key == key) {
				exists = true;
				break;
			}
			list->next();
			index++;
		} while (!list->isLast());
	}
	if (exists) {
		list->eraseFromEnd(index);
	}
}
template<class KeyType, class ItemType>
inline void HashMap<KeyType, ItemType>::resize()
{
	if (this->size == this->capacity) {
		this->capacity = capacity * 2;
		LinkedList<NodeStruct> *  newBuffer = new LinkedList<NodeStruct>[capacity];

		for (int i = 0; i < size; i++) {
			newBuffer[i] = buffer[i];
		}
		delete[] buffer;
		this->buffer = newBuffer;
	}

	else if (size <= (capacity / 4)) {
		this->capacity = capacity / 2;
		LinkedList<NodeStruct> *  newBuffer = new LinkedList<NodeStruct>[capacity];
		for (int i = 0; i < size; i++) {
			newBuffer[i] = buffer[i];
		}
		delete[] buffer;
		this->buffer = newBuffer;
	}
}
