// ComplexNumbersExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>


struct Complex {
	float x;     //real part
	float y;     //imaginary part
};

void Inititialize(Complex& Z, float xp, float yp) { Z.x = xp; Z.y = yp; }
float Re(Complex Z) { return Z.x; }
float Im(Complex Z) { return Z.y; }

//overload insertion operator
std::ostream& operator<< (std::ostream& os, Complex Z) {
os << Re(Z) << " + " << Im(Z) << "i";
	return os;
}

//overload addition operator
Complex& operator+ (Complex Z1, Complex Z2) {
	Z1.x = Re(Z1) +  Re(Z2);
	Z1.y = Im(Z1) + Im(Z2);
	return Z1;
}

//overload multiplication operator
Complex& operator* (Complex Z1, Complex Z2) {
	float temp = Re(Z1);
	Z1.x = Re(Z1) * Re(Z2) - Im(Z1) * Im(Z2);
	Z1.y = temp * Im(Z2) + Im(Z1)*Re(Z2);
	return Z1;
}

//overload extraction operator
std::istream & operator >> (std::istream &in, Complex &Z) {
	in >> Z.x >> Z.y;
	return in;
}




int main()
{
	Complex Z1, Z2;  

	Inititialize(Z1,5, 10);
	Inititialize(Z2, 4, 5);

	std::cout << Z1 << std::endl;
	std::cout << Z2 << std::endl;

	std::cout << Z1 + Z2 << std::endl;

	std::cout << Z1 * Z2 << std::endl;


	std::cout << "Enter value of x and y in complex number :  " << std::endl;
	Complex Z;
	std::cin >> Z;
	std::cout << Z << std::endl;
	


	system("pause");
	return 0;
}

