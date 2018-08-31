// Array.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Vector.h"
#include<iostream>

using namespace std;

int main()
{
	Vector <int> vector(2);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(7);
	vector.insert(5, 3);
	vector.add(7);
	vector.prepend(78);
	vector.pop();
	vector.deleteAt(1);
	vector.remove(7);

	cout << vector.toString() << endl;

	system("Pause");
    return 0;
}

