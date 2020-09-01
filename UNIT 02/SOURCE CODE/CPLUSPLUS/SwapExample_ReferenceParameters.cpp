// SwapExample_RefParam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>


//reference parameters -- aka Call-by-Reference
void swap(int&  x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}


int main()
{
	int num1 = 25;
	int num2 = 78;
	swap(num1, num2);
	std::cout << num1 << "   " << num2 << std::endl;

	system("pause");
	return 0;
}

