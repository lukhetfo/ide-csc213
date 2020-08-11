// BasicConstructsDemo_CLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//Single Selection
void singleSelectionExample(int x, int y) {
	if (x > y) {
		std::cout << x << std::endl;
	}
}



//Double Selection
void doubleSelectionExample(int x, int y) {
	if (x > y) 
		std::cout << x << std::endl;
	else
		std::cout << y << std::endl;
}

//Multiple Selection
void multiplySelectionExample(int day) {
	switch (day) {
	case 6:
	case 7:
		std::cout << "Weekend" << std::endl;
		break;
	default:
		std::cout << "Week Day" << std::endl;
		break;
	}
}




//While loop

void whileLoopExample() {
	int i = 1;
	while (i < 5) {
		std::cout << i;
		i++;
	}

	std::cout << std::endl;
}

//Do ... while loop
void doWhileLoopExample() {
	int i = 1;
	do {
		std::cout << i;
		i++;
	} while (i < 5);

	std::cout << std::endl;
}

//FOR loop
void forLoopExample() {
	for (int i = 1; i < 5; i++) {
		std::cout << i;
	}

	std::cout << std::endl;
}


int main()
{

	//run selection code
	singleSelectionExample(10, 5);
	doubleSelectionExample(5, 10);
	multiplySelectionExample(4);

	//run iteration code
	whileLoopExample();
	doWhileLoopExample();
	forLoopExample();

	system("pause");
}

