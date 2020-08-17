// ProcessEmployeeDataExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

#include <fstream>
#include <sstream>
#include <iomanip>

/***********************************************************************
*                          FUNCTION DEFINITIONS                        *
************************************************************************/
//calculate grossPay
double calculateGrossPay(double rate, int hoursWorked)
{
	return rate * hoursWorked;
}

//calculate net pay
double calculateTax(double amount)
{
	if (amount <= 1000.00)
		return 0.0;
	else
		return 0.33*(amount - 1000.00);
}

//read and process employee data from file
void readEmployeeDataFromFile(const char* fromFilename, std::ostream& os)
{

	
	std::ifstream inF;
	inF.open(fromFilename, std::ios::in);


	std::string str;
	while (getline(inF, str))
	{
		std::istringstream lineSS(str);


		//declare strings for name and surname:
		std::string name, surname, sentinel;


		//read and write employee name, and surnames; include sentinel
		lineSS >> name >> surname >> sentinel;
		os << std::setw(15) << std::left << surname << std::setw(15) << name;


		// read and write rate per hour
		double ratePerHour;
		lineSS >> ratePerHour;
		os << std::setw(8) << std::fixed << std::setprecision(2) << ratePerHour << "\t";

		//read hoursWorked
		int hoursPerWeek = 0;
		int totalHoursWorked = 0;
		while (lineSS >> hoursPerWeek)
			totalHoursWorked += hoursPerWeek;

		//write totalHoursWorked 
		os << std::setw(8) << totalHoursWorked << "\t";

		//calculate and display gross pay
		double grossPay = calculateGrossPay(ratePerHour, totalHoursWorked);
		os << std::setw(8) << grossPay << "\t";

		//caclulate and write tax
		double tax = calculateTax(grossPay);
		os << std::setw(8) << std::right << tax << "\t";

		//calculate and display net pay
		double netPay = grossPay - tax;
		os << std::setw(8) << std::right << netPay;

		//write new line
		os << std::endl << std::endl;
	}

	inF.close();

	return;
}
/********************* END FUNCTION DEFINITIONS   **********************/


int main()
{
	//testing
	readEmployeeDataFromFile("employeedata.txt", std::cout);
	system("pause");

}


