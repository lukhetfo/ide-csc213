//Test 02 Sample Solution
/********************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//FIELD WIDTH VARIABLE - USEFUL BUT NOT REQUIRED/OPTIONAL
const int ID_W = 12;
const int CODE_W = 10;
const int NAME_W = 30;
const int POPULATION_W = 15;
const int RATIO_W = 5;
const int SEP_LINE_W = ID_W + CODE_W + NAME_W + 2* POPULATION_W +3;

//for purposes of TEST and EXAMINATION add following line and remove std::
// setw formating may also be omitted
using namespace std;

//QUESTION 1 (a)
struct Province {
	string code;
	string id;
	string name;
};

//QUESTION 1 (b)
istream& operator>> (istream& is, Province& P) {
	is >> P.code >> P.id >> P.name;
	return is;
}
//QUESTION 1 (c)
ostream& operator<< (ostream& os, Province P) {
	os << "Province ID    :" << P.id << endl;
	os << "Province code  :"  << P.code << endl;
	os << "Province name  :"  << P.name << endl;
	return os;
}

//QUESTION 2 (a)
struct District {
	string province_code;
	string id;
	string name;
	int females;
	int males;
};

//QUESTION 2 (b)
istream& operator>> (ifstream& is, District& D) {
	is >> D.province_code >> D.id >>  D.name >> D.females >> D.males;
	return is;
}

//QUESTION 2 (c)
ostream& operator<< (ostream& os, District D) {
	double gender_ratio = D.males * 1.0 / D.females;
	os << left << setw(ID_W) << D.id << setw(NAME_W)  << D.name <<
		setw(POPULATION_W) << D.males  << setw(POPULATION_W) <<  D.females 
		<< right << setw(RATIO_W) << setprecision(3) << gender_ratio << endl;
	return os;
}


//QUESTION 3
//UTILITY FUNCTION -- optional
void writeChar(char ch, int count)
{
	for (int i = 1; i < count; i++)
		cout << ch;
}

void generateProvinceReport(const char* provinceDataFileName, const char* districtDataFileName)
{
	//open province data file for reading
	ifstream ProvInF;
	ProvInF.open(provinceDataFileName, ios::in);

	
	//ignore header text in  province data file
	string headerStrRedundent;
	getline(ProvInF, headerStrRedundent);

	//begin loop to read from each province record from TEXT file
	Province P;
	while (ProvInF >> P)
	{
		
		cout << P;
		writeChar('*', SEP_LINE_W); cout << endl;
		cout << left << setw(ID_W) << "DID" << setw(NAME_W) << "DNAME" <<
			setw(POPULATION_W) << "#MALES" << setw(POPULATION_W) << "#FEMALES"
			<< right << setw(RATIO_W) << "GENDER_RATIO"<< endl;
		writeChar('*', SEP_LINE_W); cout << endl;

		/********************************************************************
		*        find matching records in district data file                *
		* ******************************************************************/
		//initialize summary variables =0
		double male_total = 0;
		double female_total = 0;
		int count = 0;

		//open district data file for reading
		ifstream DistrictInF;
		DistrictInF.open(districtDataFileName, ios::in);


		//ignore header text in  province data file
		getline(DistrictInF, headerStrRedundent);


		//begin loop to read and find matching pr0vince code from district  TEXT file
		District  D;
		while (DistrictInF >> D)
		{
			if (P.code == D.province_code) {
				cout << D;
				male_total += D.males; 
				female_total += D.females;
				count += 1;
			}
		}
		//write TOTALS AND AVERAGE
		writeChar('=', SEP_LINE_W); cout << endl; 
		cout << left << setw(ID_W + NAME_W) << "POPULATION TOTAL" 
			<< setw(POPULATION_W) << male_total << setw(POPULATION_W) << female_total << endl;
		cout << left << setw(ID_W + NAME_W) << "POPULATION AVERAGE" 
			<< setw(POPULATION_W) << male_total/count << setw(POPULATION_W) << female_total/count << endl;
		writeChar('=', SEP_LINE_W); cout << endl; cout << endl;
		DistrictInF.close();
	}
	
	ProvInF.close();
}



//QUESTION 4
int main()
{
	generateProvinceReport("province.txt", "district.txt");
	system("pause");
	return 0;
}
