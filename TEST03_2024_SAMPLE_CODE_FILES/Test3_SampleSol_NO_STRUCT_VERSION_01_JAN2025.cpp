// Test3_Jan2025_SampleSol.cpp : This file contains the 'main' function. Program execution begins and ends there.
// NO STRUCT

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


//QUESTION 1 -- sample pseudocode
/*
INPUTS:  COURSE data file, ENROLMENT data file)
begin
	open COURSE data file for reading
	remove header line in COURSE data file
	write report header text to standard output
	initialize overall count total(number of enrolments) to 0
	Loop through each record in COURSE data file
	begin

		read  course_code, description, caRate, examRate;
		write course_code and  description to standard output
		initialize CA_total to 0;
		initialize EXAM_total to 0;
		initialize enrolment student count to 0;

		open ENROLMENT data file for reading
		remove header line in  ENROLMENT data file
		Loop through each record in ENROLMENT data file
		begin
			read  enrolment_code,sid, caMark, examMark;
			if (enrolment_code matches course_code)
			begin
				increment CA_total by caMark;
				increment EXAM_total by examMark;
				increment student enrolment count by 1;
			end
		end ENROLMENT data file loop
		close ENROLMENT data file
		increment overall count_total by student enrolment count

		calculate CA_average as CA_total / student enrolment count;
		calculate EXAM_average as CA_total / student enrolment count;
		write student enrolment count, CA_average and EXAM_avearge to
			standard output
		   go to new output line

	end COURSE data file loop
	close COURSE data file
	write report footer text plus overall total number of students
end
*/


//QUESTION 2 -- SOLUTION WITHOUT STRUCTS
// Solution can be written using structs and overloaded operators


//UTILITY FUNCTION -- optional
void writeChar(char ch, int count)
{
	for (int i = 1; i < count; i++)
		std::cout << ch;
}

void generateCourseSummaryReport(const char* courseDataFileName, const char* enrolmentDataFileName)
{
	//open COURSE data file for reading
	ifstream CourseInF;
	CourseInF.open(courseDataFileName, ios::in);
	
	// write header text
	std::cout << "Course Summary Report" << endl;
	writeChar('=', SEP_LINE_W); std::cout << endl;
	std::cout << left << setw(CODE_W) << "CID" << setw(TITLE_W) << "TITLE" 
		<< setw(MARK_W*2) << "NUMBER OF STUDENTS"
		<<setw(MARK_W+3) << "CA_AVERAGE" << setw(MARK_W+3) << "EXAM_AVERAGE"
		<< endl;
	writeChar('=', SEP_LINE_W); std::cout << endl;
	
	//ignore header text in  COURSE data file
	string headerStrRedundent;
	getline(CourseInF, headerStrRedundent);

	//initialize count total
	int count_total = 0;
	//begin loop to read each COURSE record from TEXT file
	string course_str;
	while (getline(CourseInF, course_str))
	{
		istringstream courseSS(course_str);
		string course_code, description;
		double caRate, examRate;
		courseSS >> course_code >> description >> caRate >> examRate;
		std::cout << setw(CODE_W) << course_code << setw(TITLE_W) << description;

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
		
		string enrolment_str;
		while (getline(EnrolmentInF, enrolment_str))
		{
			istringstream enrolmentSS(enrolment_str);
			string enrolment_code,sid;
			int caMark, examMark;
			enrolmentSS >> enrolment_code >> sid >> caMark >> examMark;
			if (enrolment_code == course_code) {
				CA_total += caMark;
				EXAM_total += examMark;
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
		std::cout << left << setw(MARK_W*2) << count 
			<< fixed << setw(MARK_W+3) << setprecision (2) << CA_average
			<< fixed << setw(MARK_W+3) << setprecision(2) << EXAM_average
			<< endl;
	    //close enrolment file
		EnrolmentInF.close();
	}
	//write overall total
	writeChar('=', SEP_LINE_W); std::cout << endl;
	std::cout << left << "Total Number of Students = "<< count_total << endl;
	writeChar('=', SEP_LINE_W); std::cout << endl; std::cout << endl;

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

