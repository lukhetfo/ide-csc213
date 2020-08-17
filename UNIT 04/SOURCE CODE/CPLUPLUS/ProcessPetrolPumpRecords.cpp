// ProcessPetrolPumpRecords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string generatePetrolPumpRecord (){

	//pick petrol pump id number
	int pumpNumber = (rand() % 15) + 1;
		
	//pick grade of petrol
	int grade = (rand() % 2) + 1;
	std::string gradeLabel;
	(grade == 1) ? gradeLabel = "Leaded": gradeLabel = "Unleaded";
	
	//generate volume of petrol betweeon 0 and 1000
	float volume_in_litres = (float)rand() / (float)(RAND_MAX / 1000);

	//convert volume_in_litres to 2 dec places
	int nDummy = (int)(volume_in_litres *100.0);
	volume_in_litres = ((float)nDummy) / 100.0;

	
	std::stringstream  result_ss;
	result_ss << std::right << std::setfill('0') << std::setw(2)   << pumpNumber
		      << std::left << std::setfill(' ') << "   "
		      << std::left << std::setw(10) << gradeLabel
			  << std::setw(10) << std::fixed << std::setprecision(2) << volume_in_litres << "\n";

	std::string result = result_ss.str();
	
	return (result);

}

//calculate Total cost
float calculateTotalCost(float unitCost, float volume) {
	return unitCost * volume;
}


int main()
{
	//initialize random seed - to assist in generating random data
	srand((unsigned)time(NULL));

	//initialize costs

	float unleadedUnitCost = 11.75;
	float leadedUnitCost = 12.15;

    
	// pick number of records :  between 1 and 10
	int numberRec = (rand() % 10) + 1;
	std::cout << "****STARTED PROCESSING " << numberRec << " RECORDS ****" << std::endl << std::endl;


	//while there are more records to process
	int record_counter = 1;
	while (record_counter <= numberRec) {
		//pick next available pump record
		std::string inputRec = generatePetrolPumpRecord();
		

		//read data from input record
		std::string pumpid, grade;
		float volume;
		std::stringstream inputRec_SS;
		inputRec_SS << inputRec;
		inputRec_SS >> pumpid >> grade >> volume;

		float grade_unitCost;
		(grade == "Leaded") ? grade_unitCost = leadedUnitCost : grade_unitCost = unleadedUnitCost;

		//calculate total cost
		float totalCost = calculateTotalCost(grade_unitCost, volume);

		std::cout << "\n =========================================" << std::endl;

		std::cout << "Pump Number      : " << pumpid << std::endl;
		std::cout << "Grade of Petrol  : " << grade  << std::endl;
		std::cout << "Unit Cost        : " << std::left << "E" << std::fixed << std::setw(7)  
										   << std::setprecision(2) << grade_unitCost << " / Litre" << std::endl;
		std::cout << "Volume Dispersed : " << volume << " Litres" <<  std::endl;
		std::cout << "Total Cost       : " << std::left << "E" << std::fixed << std::setw(7) 
										   << std::setprecision(2) << totalCost << std::endl;
		std::cout << "=========================================" << std::endl;
		std::cout << std::endl;
		

		std::cout << "...... PRESS ANY KEY TO PROCEED TO NEXT RECORD" << std::endl;
		system("pause");

		//go to next record
		record_counter++;
	}
	
	std::cout << "\n\n\n *** FINISHED PROCESSING AVAILABLE RECORDS ***" << std::endl;
	system("pause");
}


