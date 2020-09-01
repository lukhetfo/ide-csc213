// BankAccountExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Account.h"


	int main()
	{
		Account A;
		A.create(1000);
		A.displayBalance();

		A.deposit(500);
		A.displayBalance();

		A.withdraw(300);
		A.displayBalance();

		system("pause");
		return 0;
	}
