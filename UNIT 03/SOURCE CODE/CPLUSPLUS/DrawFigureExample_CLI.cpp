// DrawFigureExample_CLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{

	//Read height from input
	int height = 1;
	std::cout << "Enter integer height of figure: ";
	std::cin >> height;

	//loop and output each line
	for (int lineNumber = 1; lineNumber <= height; lineNumber++)
	{
		//Write(Height – lineNumber) blank characters
		for (int i = 1; i <= height - lineNumber; i++)
			std::cout << " ";

		//Write(2 * lineNumber – 1) asterisk characters
		for (int i = 1; i <= 2 * lineNumber-1; i++)
			std::cout << "*";

		//Write(Height – lineNumber) blank character
		for (int i = 1; i <= height-lineNumber; i++)
			std::cout << " ";

		//Go to a new output line
		std::cout << std::endl;

	}
	
	system("pause");
}

