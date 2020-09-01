#pragma once
#include <iostream>
struct Account {
	float balance;

	void create(float openingBalance = 0) { balance = openingBalance; }
	void withdraw(float amount) { balance -= amount; }
	void deposit(float amount) { balance += amount; }
	void displayBalance() {
		std::cout << "Balance is " << balance << " Emalangeni" << std::endl;
	}
};
