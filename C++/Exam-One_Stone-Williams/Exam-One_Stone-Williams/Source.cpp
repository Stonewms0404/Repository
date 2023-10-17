#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int aday, int amonth, int ayear);
	string StandardFormat(); //YYY-MM-DD
	string StringFormat(); //Month Day, Year
};

Date::Date()
{
	day = 1;
	month = 1;
	year = 2019;
}

Date::Date(int aday, int amonth, int ayear)
{
	if (aday <= 0) { day = 1; } 
	else { day = aday; }
	
	if (amonth <= 0) { month = 1; } 
	else { month = amonth; }

	if (ayear <= 0) { year = 1; } 
	else { year = ayear; }
}

string Date::StandardFormat()
{
	string sDate;


	if (year < 10)
	{
		sDate += "000" + to_string(year);
	}
	else if (year < 100)
	{
		sDate += "00" + to_string(year);
	}
	else if (year < 1000)
	{
		sDate += "0" + to_string(year);
	}
	else
	{
		sDate += to_string(year);
	}

	if (month < 10)
	{
		sDate += "-0" + to_string(month);
	}
	else
	{
		sDate += "-" + to_string(month);
	}

	if (day < 10)
		{ sDate += "-0" + to_string(day); }
	else
		{ sDate += "-" + to_string(day); }


	return sDate;
}

string Date::StringFormat()
{
	string sDate;
	switch (month)
	{
	case 1: sDate = "Jan "; break;
	case 2: sDate = "Feb "; break;
	case 3: sDate = "Mar "; break;
	case 4: sDate = "Apr "; break;
	case 5: sDate = "May "; break;
	case 6: sDate = "Jun "; break;
	case 7: sDate = "Jul "; break;
	case 8: sDate = "Aug "; break;
	case 9: sDate = "Sep "; break;
	case 10: sDate = "Oct "; break;
	case 11: sDate = "Nov "; break;
	case 12: sDate = "Dec "; break;
	}

	sDate += to_string(day) + ", " + to_string(year);
	return sDate;
}


int main()
{
	Date date(7, 2, 2019);

	cout << date.StandardFormat() << endl;
	cout << date.StringFormat() << endl;

	return 0;
}