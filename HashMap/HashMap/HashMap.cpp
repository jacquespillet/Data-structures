// HashMap.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <string>
#include <stdlib.h>
#include "HashMap.h"
#include "LinkedList.h"


int main()
{
	HashMap<std::string, std::string> hashmap;
	hashmap.add("pillet", "generated_id_0");
	hashmap.add("azeoij", "generated_id_1");
	hashmap.add("apzldapl", "generated_id_0");

	hashmap.add("apoa", "jacques");
	hashmap.add("cdjsz", "jacques2");
	hashmap.add("pazfdazj", "jacques2");
	hashmap.add("ezujifzj", "jacques2");
	hashmap.add("aoapz", "jacques2");
	hashmap.add("azola", "jacques2");
	hashmap.add("zaoiazaza", "jacques2");

	std::cout << hashmap.get("azola") << std::endl;
	std::cout << hashmap.exists("azola") << std::endl;

	hashmap.remove("azola");
	
	std::cout << hashmap.get("azola") << std::endl;
	std::cout << hashmap.exists("azola") << std::endl;

	//LinkedList<int> list;
	//list.add(1);
	//list.add(2);
	//list.add(3);
	//list.add(4);
	//list.add(5);
	//list.add(6);

	//list.eraseFromEnd(3);
	//list.goThrough();


	
	//hashmap.add()
	system("pause");
    return 0;
}

