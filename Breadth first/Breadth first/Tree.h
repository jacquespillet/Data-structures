#pragma once
#include "Vertex.h"
#include <unordered_map>
#include<vector>
#include<iostream>
#include<string>

class Tree
{
public:
	Tree(){}
	~Tree(){}
	Vertex* vertices;
	std::unordered_map<Vertex*, Vertex*> parents;
	std::unordered_map<Vertex*, int> levels;
	void run() {
		levels = {{&vertices[0], 1 }};
		parents = {{ &vertices[0], NULL}};
		std::vector<Vertex*> frontier;

		int i = 1;
		frontier.push_back(&vertices[0]);
		
		while (frontier.size() > 0) {
			std::vector<Vertex*> next;
			for (int i = 0; i < frontier.size(); i++) {
				for (int j = 0; j < frontier[i]->adjacents.size(); j++) {
					Vertex* adjacent = frontier[i]->adjacents.at(j);
					if (levels.count(adjacent) == 0) {
						levels.insert(std::pair<Vertex*, int>( adjacent, i));
						parents.insert(std::pair<Vertex*, Vertex*>(adjacent, frontier[i]));
						next.push_back(adjacent);
					}
				}
			}
			frontier = std::vector<Vertex*>(next);
			i++;
		}
	}
};