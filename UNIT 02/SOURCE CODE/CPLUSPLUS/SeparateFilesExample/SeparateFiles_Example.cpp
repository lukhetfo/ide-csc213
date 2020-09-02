// SeparateFiles_Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include "../SeparateFiles_Example/MyFunctionsDef.h"
#include  "MyFunctionsDef.h"

int main()
{
	for (int m = 0; m < 6; m++)
		std::cout << factorial(m) << "\t";
	std::cout << std::endl;

	for (int n = 0; n < 6; n++)
		std::cout << MyPower(2, n) << "\t";
	std::cout << std::endl;

	system("pause");

}
