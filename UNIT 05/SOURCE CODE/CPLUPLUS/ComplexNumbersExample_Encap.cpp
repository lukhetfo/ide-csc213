// ComplexNumbersExample_Encap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>


struct Complex {

	float x;     //real part
	float y;     //imaginary part

	void Inititialize(float xp, float yp) { x = xp; y = yp; }
	float Re() { return x; }
	float Im() { return y; }


	//overload addition operator
	Complex& operator+ (Complex Z)
	{
		x = x + Z.Re();
		y = y + Z.Im();
		return *this;
	}

	//overload multiplication operator
	Complex& operator* (Complex Z)
	{
		float temp = x;
		x = x * Z.Re() - y * Z.Im();
		y = temp * Z.Im() + y * Z.Re();
		return *this;
	}
};
/*****************************************************************/
/*          NOT PART OF ENCAPSULATION                            */
/*****************************************************************/
//overload insertion operator
 std::ostream& operator<< (std::ostream& os, Complex Z) {
	os << Z.Re() << " + " << Z.Im() << "i";
	return os;
}
//overload extraction operator
 std::istream & operator >> (std::istream &in, Complex &Z) {
	in >> Z.x >> Z.y;
	return in;
}
 
/*****************************************************************/




int main()
{
	Complex Z1, Z2;

	Z1.Inititialize(5, 10);
	Z2.Inititialize(4, 5);

	std::cout << Z1 << std::endl;
	std::cout << Z2 << std::endl;

	std::cout << Z1 + Z2 << std::endl;

	Z1.Inititialize(5, 10);
	std::cout << Z1 * Z2 << std::endl;


	std::cout << "Enter value of x and y in complex number :  " << std::endl;
	Complex Z;
	std::cin >> Z;
	std::cout << Z << std::endl;



	system("pause");
	return 0;
}
