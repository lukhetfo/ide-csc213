// Test3_Jan2025_SampleSol.cpp : This file contains the 'main' function. Program execution begins and ends there.
// SOLUTION USING STRUCTS AND OVERLOADED OPERATORS

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//FIELD WIDTH VARIABLE - USEFUL BUT NOT REQUIRED/OPTIONAL
const int CODE_W = 10;
const int TITLE_W = 45;
const int MARK_W = 10;
const int SEP_LINE_W = CODE_W + TITLE_W + 4*MARK_W+6;

//for purposes of TEST and EXAMINATION add following line and remove std::
// setw formating may also be ommitted
using namespace std;

//QUESTION 1 -- pseudocode
//AS PER STUDENT RESPONSE


//QUESTION 2 -- SOLUTION USING STRUCTS AND OVERLOADED OPERATORS
// Solution can be written without struct

//structure and operators for course records
struct Course {
	string code;
	string description;
	double caRate;
	double examRate;
};

istream& operator>> (istream& is, Course& C) {
	is >> C.code >> C.description >> C.caRate >> C.examRate;
	return is;
}

ostream& operator<< (ostream& os, Course C) {
	os << setw(CODE_W) << C.code << setw(TITLE_W) << C.description;	
	return os;
}

//structure and operators for enrolment records
struct Enrolment {
	string code;
	string sid;
	int caMark;
	int examMark;
};


istream& operator>> (ifstream& is, Enrolment& E) {
	is >> E.code >> E.sid >> E.caMark >> E.examMark;
	return is;
}


//UTILITY FUNCTION -- optional
void writeChar(char ch, int count)
{
	for (int i = 1; i < count; i++)
		cout << ch;
}

void generateCourseSummaryReport(const char* courseDataFileName, const char* enrolmentDataFileName)
{
	//open COURSE data file for reading
	ifstream CourseInF;
	CourseInF.open(courseDataFileName, ios::in);

	// write header text
	cout << "Course Summary Report" << endl;
	writeChar('=', SEP_LINE_W); cout << endl;
	cout << left << setw(CODE_W) << "CID" << setw(TITLE_W) << "TITLE" 
		<< setw(MARK_W*2) << "NUMBER OF STUDENTS"
		<<setw(MARK_W+3) << "CA_AVERAGE" << setw(MARK_W+3) << "EXAM_AVERAGE"
		<< endl;
	writeChar('=', SEP_LINE_W); cout << endl;
	
	//ignore header text in  COURSE data file
	string headerStrRedundent;
	getline(CourseInF, headerStrRedundent);

	//initialize count total
	int count_total = 0;
	//begin loop to read  each COURSE record from TEXT file
	Course C;
	while (CourseInF >> C)
	{
		cout << C;
		/********************************************************************
		*        find matching records in enrolment data file                *
		* ******************************************************************/
		//initialize summary variables =0
		double CA_total = 0;
		double EXAM_total = 0;
		int count = 0;

		//open enrolment data file for reading
		ifstream EnrolmentInF;
		EnrolmentInF.open(enrolmentDataFileName, ios::in);


		//ignore header text in  ENROLMENT data file
		getline(EnrolmentInF, headerStrRedundent);


		//begin loop to read and find matching course code from enrolment  TEXT file
		Enrolment  E;
		while (EnrolmentInF >> E)
		{
			if (C.code == E.code) {
				CA_total += E.caMark;
				EXAM_total += E.examMark;
				count += 1;
			}
		}
		//increment count total
		count_total += count;

		//calculate  averages
		double CA_average = 0;
		double EXAM_average = 0;
		if (count > 0) {
			CA_average= CA_total * 1.0 / count;
			EXAM_average = EXAM_total * 1.0 / count;
		}
		//write count and averages	
		cout << left << setw(MARK_W*2) << count 
			<< fixed << setw(MARK_W+3) << setprecision (2) << CA_average
			<< fixed << setw(MARK_W+3) << setprecision(2) << EXAM_average
			<< endl;
	    //close enrolment file
		EnrolmentInF.close();
	}
	//write overall total
	writeChar('=', SEP_LINE_W); cout << endl;
	cout << left << "Total Number of Students = "<< count_total << endl;
	writeChar('=', SEP_LINE_W); cout << endl; cout << endl;

	//close course file
	CourseInF.close();
}


//QUESTION 3
int main()
{
	generateCourseSummaryReport("courses.txt", "enrolments.txt");
	system("pause");
	return 0;
}