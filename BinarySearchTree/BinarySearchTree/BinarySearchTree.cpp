// BinarySearchTree.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "Tree.h"

int main()
{
	Tree tree;
	tree.root = tree.add(tree.root, 8, "eight");
	tree.root = tree.add(tree.root, 6, "six");
	tree.root = tree.add(tree.root, 7, "seven");
	tree.root = tree.add(tree.root, 10, "ten");
	tree.root = tree.add(tree.root, 15, "fifteen");
	tree.root = tree.add(tree.root, 13, "thirteen");
	tree.root = tree.add(tree.root, 16, "sixteen");
	

	//tree.deleteValue(tree.root, 7);
	//tree.inOrder(tree.root);
	//std::cout << tree.height(tree.root) << std::endl;
	//std::cout << tree.max(tree.root) << std::endl;
	tree.levelOrder(tree.root);
	system("pause");
}

