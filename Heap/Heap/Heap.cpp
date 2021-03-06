// Heap.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

int size = 10;

void createArray(int* elements) {
	elements[0] = 2;
	elements[1] = 8;
	elements[2] = 15;
	elements[3] = 1;
	elements[4] = 10;
	elements[5] = 5;
	elements[6] = 19;
	elements[7] = 17;
	elements[8] = 3;
	elements[9] = 6;
}

void printArray(int* elements) {
	for (int i = 0; i < size; i++) {
		std::cout << elements[i] << "  ";
	}
	std::cout << std::endl;
}

void maxHeapify(int *elements, int index, int size) {
	int left = elements[(index + 1) * 2 - 1];
	int right = ((index + 1) * 2 > size -1) ? 0 : elements[(index + 1) * 2];
	if (left > elements[index] && left > right) {
		elements[(index + 1) * 2 - 1] = elements[index];
		elements[index] = left;
		if ((index + 1) * 2 - 1 < (size / 2) - 1) {
			maxHeapify(elements, (index + 1) * 2 - 1, size);
		}
	}
	if (right > elements[index] && right > left) {
		elements[(index + 1) * 2] = elements[index];
		elements[index] = right;

		if ((index + 1) * 2 - 1 < (size / 2) - 1) {
			maxHeapify(elements, (index + 1) * 2, size);
		}
	}
}

void buildMaxHeap(int *elements) {
	for (int i = (size / 2) - 1; i >= 0; i--) {
		maxHeapify(elements, i, size);
	}
}

void heapSort(int *elements) {
	buildMaxHeap(elements);
	printArray(elements);
	int max = size - 1;
	while (max >= 0) {
		int maxElement = elements[0];
		elements[0] = elements[max];
		elements[max] = maxElement;
		maxHeapify(elements, 0, max);
		max--;
		printArray(elements);
	}
}

int main()
{
	int *elements = new int[size];
	createArray(elements);
	heapSort(elements);
	system("pause");
    return 0;
}

