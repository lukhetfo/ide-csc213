//Test 01 Sample Solution

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//for purposes of TEST and EXAMINATION add following line and remove std::
//setw formating may also be omitted
using namespace std;

//FIELD WIDTH VARIABLE - USEFUL BUT NOT REQUIRED/OPTIONAL
const int SID_W = 12;
const int SURNAME_W = 10;
const int INITIALS_W = 5;
const int NAME_W = INITIALS_W + SURNAME_W + 1;
const int GENDER_W = 8;
const int WEIGHT_W = 5;
const int HEIGHT_W = 5;
const int AGE_W = 5;
const int BMR_W = 10;
const int CALORIES_W = 12;
const int LEVEL_W = 5;
const int SEP_LINE_W = SID_W + NAME_W + GENDER_W + WEIGHT_W +
HEIGHT_W + AGE_W + BMR_W + CALORIES_W + 3;
const int SUMMARY_LABEL_W = 45;

//QUESTION 1 (a)
double calculateBMR(string gender, double weight, double height, double age)
{
	if (gender == "MALE")
		return  (66 + 13.7 * weight + 5 * height - 6.8 * age);
	else
		return (65 + 9.6 * weight + 1.8 * height - 4.7 * age);
}

//QUESTION 1 (b)
double calculateCalorieNeeds(double BMR, int level)
{   //can use IF statement or CASE statement
	double calorieNeed = 0;
	switch (level) {
	case 1: { calorieNeed = 1.2 * BMR; break; }
	case 2: { calorieNeed = 1.375 * BMR; break; }
	case 3: { calorieNeed = 1.55 * BMR; break; }
	case 4: { calorieNeed = 1.725 * BMR; break; }
	case 5: { calorieNeed = 1.9 * BMR; break; }
	}
	return calorieNeed;
}


//QUESTION 2
// PSEUDOCODE - as per student response



//QUESTION 3
//UTILITY FUNCTION -- optional
void writeChar(char ch, int count)
{
	for (int i = 1; i < count; i++)
		cout << ch;
}

//UTILITY FUNCTION -- optional
void displayHeader()
{
	cout << "                                UNIVERSITY OF SWAZILAND" << endl;
	cout << "                  BMR/ CALORIE NEEDS FOR CSC213 CLASS, NOVEMBER, 2024" << endl;
	cout << "                              PRODUCED BY : 101112 XY" << endl;
	writeChar('=', SEP_LINE_W); cout << endl;
	cout << left << setw(SID_W) << "ID"
		<< setw(NAME_W) << "NAME"
		<< setw(GENDER_W) << "GENDER"
		<< setw(WEIGHT_W) << "WT"
		<< setw(HEIGHT_W) << "HT"
		<< fixed << setw(AGE_W) << "AGE"
		<< fixed << right << setw(BMR_W) << "BMR"
		<< fixed << right << setw(CALORIES_W) << "CALORIES"
		<< endl;
	writeChar('=', SEP_LINE_W); cout << endl;
}

void generateStudentBMRreport(const char* dataFileName)
{
	//display header
	displayHeader();

	//initialize summary variables =0
	int student_count = 0;
	double CALORIE_total = 0;
	double BMR_total = 0;

	//open file for reading
	ifstream studInF;
	studInF.open(dataFileName, ios::in);

	string studRecStr;

	//ignore header text in  data file
	getline(studInF, studRecStr);

	
	while (getline(studInF, studRecStr))
	{
		// convert studRecStr to a string stream
		istringstream studLineSS(studRecStr);

		// declare field variables
		string	surname, initials, gender, sid;
		int weight, height, age, level;

		//extract field variable values

		studLineSS >> surname >> initials >> gender >> sid >>
			weight >> height >> age >> level;

		//calculate BMR and CALORIE INTAKE
		double BMR = calculateBMR(gender, weight, height, age);
		double CALORIE_NEEDS = calculateCalorieNeeds(BMR, level);

		//output record
		
		cout << left << setw(SID_W) << sid
			<< left << setw(NAME_W)
			<< initials + " " + surname
			<< setw(GENDER_W) << gender
			<< setw(WEIGHT_W) << weight
			<< setw(HEIGHT_W) << height
			<< setw(AGE_W) << age
			<< right << setw(BMR_W) << setprecision(2) << BMR
			<< right << setw(CALORIES_W)
			<< setprecision(2) << CALORIE_NEEDS
			<< endl;

		//incremnt or calculate summary variable
		student_count += 1;
		BMR_total += BMR;
		CALORIE_total += CALORIE_NEEDS;
	}

	writeChar('=', SEP_LINE_W); cout << endl;
	//go to new line
	cout << endl;

	//write summary
	cout << "========" << endl;
	cout << "SUMMARY" << endl;
	cout << "========" << endl;
	cout << left << setw(SUMMARY_LABEL_W) << "TOTAL NUMBER OF STUDENTS" << setw(3) << "= " << student_count << endl;;
	cout << setw(SUMMARY_LABEL_W) << "AVERAGE BMR OF ALL STUDENTS" << setw(3) << "= " << fixed << setprecision(2)
		<< BMR_total * 1.0 / student_count << endl;
	cout << setw(SUMMARY_LABEL_W) << "AVERAGE CALORIE INTAKE OF ALL STUDENTS" << setw(3) << "= " << fixed << setprecision(2)
		<< CALORIE_total * 1.0 / student_count << endl << endl;

	studInF.close();
}



//QUESTION 4
int main()
{
	generateStudentBMRreport("data.txt");
	system("pause");
	return 0;
}
