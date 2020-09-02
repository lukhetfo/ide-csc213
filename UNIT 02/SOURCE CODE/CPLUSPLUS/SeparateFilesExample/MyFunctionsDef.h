#pragma once

int factorial(int n) {
	return (n == 0) ? 1 : n * factorial(n - 1);
}

int MyPower(int x = 1, int n = 0) {
	return (n == 0) ? 1 : x * MyPower(x, n - 1);
}
