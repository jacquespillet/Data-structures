#pragma once
#include "Node.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

class Tree
{
public:
	Tree();
	~Tree();
	Node* root;
	Node* add(Node* root, int value, std::string str);
	bool exists(Node* root, int value);
	
	//Tree traversal
	void inOrder(Node* root); // Left, root, right
	void preOrder(Node* root); //root, left, right
	void postOrder(Node* root); //Left, right, root
	void levelOrder(Node* root); //Breadth first

	int Size();
	int height(Node* root);
	int min(Node* node);
	int max(Node* node);
	//void deleteValue(Node* node, int value);
private:
	int size;
	void visit(Node* root, std::queue<Node*>* toVisit);
};



inline Tree::Tree()
{
	this->root = NULL;
	this->size = 0;
}

inline Tree::~Tree()
{
}

inline Node* Tree::add(Node* root, int value, std::string str)
{
	if (root == NULL) {
		Node* node = new Node();
		node->value = value;
		node->str = str;
		root = node;
		this->size++;
		return root;
	}
	else if (value < root->value) {
		root->left = this->add(root->left, value, str);
	}
	else if (value > root->value) {
		root->right = this->add(root->right, value, str);
	}
	return root;
}

inline bool Tree::exists(Node * root, int value)
{
	if (root == NULL) {
		return false;
	} else if (root->value == value) {
		return true; 
	} else if(value < root->value) {
		return this->exists(root->left, value);
	} else {
		return this->exists(root->right, value);
	}
}


inline void Tree::inOrder(Node * root)
{
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	std::cout << root->value << "  " << root->str << std::endl;
	inOrder(root->right);
}

inline void Tree::preOrder(Node * root)
{
	if (root == NULL) {
		return;
	}
	std::cout << root->value << "  " << root->str << std::endl;
	preOrder(root->left);
	preOrder(root->right);
}

inline void Tree::postOrder(Node * root)
{
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->value << "  " << root->str << std::endl;
}

inline void Tree::levelOrder(Node * root)
{
	std::queue<Node*> toVisit;
	toVisit.push(root);
	visit(root, &toVisit);
}

inline void Tree::visit(Node * root, std::queue<Node*>* toVisit)
{
	
	std::cout << toVisit->front()->value << "  " << toVisit->front()->str << std::endl;
	Node* right = toVisit->front()->right;
	Node* left = toVisit->front()->left;
	toVisit->pop();
	if (left != NULL) {
		toVisit->push(left);
	}
	if (right != NULL) {
		toVisit->push(right);
	}

	while (toVisit->size() != 0) {
		visit(this->root, toVisit);
	}
}

inline int Tree::Size()
{
	return this->size;
}

inline int Tree::height(Node* root)
{
	if (root == NULL) {
		return -1;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return std::max(leftHeight, rightHeight) + 1;
}

inline int Tree::min(Node* node)
{
	int minVal = 0;
	if (node->left != NULL) {
		minVal = min(node->left);
		return minVal;
	}
	else {
		return node->value;
	}
}

inline int Tree::max(Node* node)
{
	int maxVal = 0;
	if (node->right != NULL) {
		maxVal = max(node->right);
		return maxVal;
	}
	else {
		return node->value;
	}
}

//inline void Tree::deleteValue(Node * node, int value)
//{
//	if (node == NULL) {
//		return;
//	}
//	else if (node->value == value) {
//		if (node->left == NULL && node->right == NULL) {
//			std::cout << "pas d'enfants" << std::endl;
//			delete node;
//			node = NULL;
//		} else if (node->left == NULL || node->right == NULL) {
//			std::cout << "un" << std::endl;
//		} else if (node->left != NULL && node->right != NULL) {
//			std::cout << "2 enfants" << std::endl;
//		}
//		return;
//	}
//	else if (value < node->value) {
//		this->deleteValue(root->left, value);
//	}
//	else {
//		this->deleteValue(node->right, value);
//	}
//}
