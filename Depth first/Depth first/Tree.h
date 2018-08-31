#pragma once
#include "Vertex.h"
#include <unordered_map>
#include<vector>
#include<iostream>
#include<string>

class Tree
{
public:
	Tree() {}
	~Tree() {}
	Vertex* vertices;
	int numVertices = 8;
	std::unordered_map<Vertex*, Vertex*> parents;

	void run() {
		for (int i = 0; i < numVertices; i++) {
			if (parents.count(&vertices[i]) == 0) {
				parents[&vertices[i]] = NULL;
				std::cout << "added vertex" << std::endl;
				visit(&vertices[i]);
			}
		}
	}

	void visit(Vertex* vertex) {
		for (int i = 0; i < vertex->adjacents.size(); i++) {
			if (parents.count(vertex->adjacents[i]) == 0) {
				parents[vertex->adjacents[i]] = vertex;
				std::cout << "added vertex" << std::endl;
				visit(vertex->adjacents[i]);
			}			
		}
	}

};