// DrawFigureExample_CLI_Decomp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void writeChar(char ch, int n) {
	for (int i = 1; i <= n; i++)
		std::cout << ch;
}

void drawLine(int height, int lineNumber) {
	writeChar(' ', height - lineNumber);
	writeChar('*', 2 * lineNumber - 1);
}

void drawFigure(int height) {
	for (int lineNumber = 1; lineNumber <= height; lineNumber++) {
		drawLine(height, lineNumber);
		std::cout << std::endl;
	}


}

int main()
{
	//read figure height from standard input
	int height = 1;
	std::cout << "Enter integer height of figure: ";
	std::cin >> height;

	//draw figure
	drawFigure(height);

	system("pause");
}

