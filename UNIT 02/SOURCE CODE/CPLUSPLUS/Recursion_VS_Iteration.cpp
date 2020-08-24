// Recursion_VS_Iteration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>


int factorial(int n) {
	if (n == 0) //base case/condition
		return 1; 
	else //recursive case
		return n * factorial(n - 1); 
}

int factorial_Iterative(int n) {
	int answer = 1; 
	for (int i = 1; i <= n; i++) //iteration
		answer = answer * i;
	return answer;
}


int main()
{
	std::cout << factorial(5) << std::endl;
	std::cout << factorial_Iterative(5) << std::endl;

	system("pause");
}


