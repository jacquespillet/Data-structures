// BinarySearch.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

int recursiveBinarySearch(int value, int* array, int min, int max) {
	int midpoint = 0;
	if (max < min)
		return -1;
	else
		midpoint = (max + min) / 2;


	if (array[midpoint] < value)
		recursiveBinarySearch(value, array, midpoint + 1, max);
	else if (array[midpoint] > value)
		recursiveBinarySearch(value, array, min, midpoint - 1);
	else {
		return midpoint;
	}	
}

int binarySearch(int value, int* array, int size) {
	int min = 0;
	int max = size;
	int midpoint = 0;

	while (min <= max) {
		midpoint = (max + min) / 2;
		if (array[midpoint] < value)
			min = midpoint + 1;  
		else if (array[midpoint] > value)
			max = midpoint - 1;
		else 
			min = max + 1;
	}
	return midpoint;
}

int* generateArray(int size) {
	int* randomArray = new int[size];
	int value = 0;
	for (int i = 0; i < size; i++) {
		int tmp = value +1;
		randomArray[i] = tmp;
		value = tmp;
	}

	return randomArray;
}

void printArray(int* arrayElement, int size) {
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << arrayElement[i] << " ";
	}
	std::cout << "]" << std::endl;;
}

int main()
{
	int size = 100;
	int* randomArray = generateArray(size);
	printArray(randomArray, size);
	//int res = binarySearch(30, randomArray, size-1);
	int res = recursiveBinarySearch(30, randomArray, 0, size - 1);
	std::cout << "result : " << res << std::endl;
	system("pause");
    return 0;
}

