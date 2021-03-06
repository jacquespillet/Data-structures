// Depth first.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "Tree.h"
#include "Vertex.h"
#include <list>

Vertex* initVertices() {
	Vertex* vertices = new Vertex[8];
	for (int i = 0; i < 8; i++) {
		Vertex vert;
		vertices[i] = vert;
	}

	//0 to 1
	vertices[0].adjacents.push_back(&vertices[1]);
	//0 to 3
	vertices[0].adjacents.push_back(&vertices[3]);
	//3 to 1
	vertices[3].adjacents.push_back(&vertices[1]);
	//1 to 4
	vertices[1].adjacents.push_back(&vertices[4]);
	//4 to 3
	vertices[4].adjacents.push_back(&vertices[3]);
	//3 to 4
	vertices[2].adjacents.push_back(&vertices[4]);
	//2 to 5
	vertices[2].adjacents.push_back(&vertices[5]);


	return vertices;
}

int main()
{

	Tree tree;

	Vertex * vertices = initVertices();
	tree.vertices = vertices;
	tree.run();

	system("pause");
    return 0;
}

