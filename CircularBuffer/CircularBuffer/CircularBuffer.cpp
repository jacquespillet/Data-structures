// CircularBuffer.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "CircularBuffer.h"
#include <stdlib.h>
#include <iostream>
#include <string>

int main()
{
	CircularBuffer<int> buffer(10);
	system("pause");
    return 0;
}

