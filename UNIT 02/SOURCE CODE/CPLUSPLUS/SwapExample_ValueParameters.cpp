// SwapExample_ValueParams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

//value parameters -- aka Call-by-Value
void swap(int  x, int y)
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

