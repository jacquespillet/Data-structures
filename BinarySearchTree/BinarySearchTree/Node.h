#pragma once
#include <string>

class Node
{
public:
	Node();
	~Node();
	int value;
	Node* left;
	Node* right;
	std::string str;
};
