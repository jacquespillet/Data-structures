// LinkedList.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <stdlib.h>
#include "Node.h"
#include "LinkedList.h"

int main()
{	LinkedList<int> list(1);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(7);

	
	list.pushFront(0);
	list.popFront();
	list.pushBack(8);
	list.popBack();
	
	list.insert(2, 1);
	list.erase(4);


	list.goThrough();
	
	system("pause");
	return 0;
}