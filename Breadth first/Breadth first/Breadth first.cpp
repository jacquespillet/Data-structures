// Breadth first.cpp : définit le point d'entrée pour l'application console.
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
	
	//s to a
	vertices[0].adjacents.push_back(&vertices[1]);
	vertices[1].adjacents.push_back(&vertices[0]);

	//a to z
	vertices[1].adjacents.push_back(&vertices[2]);
	vertices[2].adjacents.push_back(&vertices[1]);


	//s to x
	vertices[0].adjacents.push_back(&vertices[3]);
	vertices[3].adjacents.push_back(&vertices[0]);

	//x to d
	vertices[3].adjacents.push_back(&vertices[4]);
	vertices[4].adjacents.push_back(&vertices[3]);

	//x to c
	vertices[3].adjacents.push_back(&vertices[5]);
	vertices[5].adjacents.push_back(&vertices[3]);

	//c to d
	vertices[4].adjacents.push_back(&vertices[5]);
	vertices[5].adjacents.push_back(&vertices[4]);

	//d to f
	vertices[4].adjacents.push_back(&vertices[6]);
	vertices[6].adjacents.push_back(&vertices[4]);

	//c to f
	vertices[5].adjacents.push_back(&vertices[6]);
	vertices[6].adjacents.push_back(&vertices[5]);

	//c to v
	vertices[5].adjacents.push_back(&vertices[7]);
	vertices[7].adjacents.push_back(&vertices[5]);

	//f to v
	vertices[6].adjacents.push_back(&vertices[7]);
	vertices[7].adjacents.push_back(&vertices[6]);

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

