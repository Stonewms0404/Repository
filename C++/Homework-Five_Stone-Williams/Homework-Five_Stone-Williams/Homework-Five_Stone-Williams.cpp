//This Assignment is incomplete. There is one line of code seperating me from completion.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Employee
{
protected:
	string mFirstName;
	string mLastName;
	int mSalary;
	string mTitle;
public:
	virtual void SetData() = 0;
	virtual void SaveToFile(ofstream& out) = 0;
};
class Manager : public Employee
{
private:
	int mMeetings;
	int mVacation;
public:
	Manager()
	{
		mMeetings = 0;
		mVacation = 0;
	}
	Manager(string fName, string lName, int salary, string title, int meetings, int vacation)
	{
		mFirstName = fName;
		mLastName = lName;
		mSalary = salary;
		mTitle = title;
		mMeetings = meetings;
		mVacation = vacation;
	}
	int getMeetings() const { return mMeetings; }
	int getVacation() const { return mVacation; }

	void SetData()	{}
	void SaveToFile(ofstream& out)
	{
		out << "Employee Name: " << mFirstName << " " << mLastName << endl
			<< "Employee Salary: " << mSalary << endl
			<< "Employee Title: " << mTitle << endl
			<< "Employee Meetings: " << mMeetings << endl
			<< "Employee Vacations: " << mVacation << endl;
	}
};
class Engineer : public Employee
{
private:
	bool mCPP;
	int mYears;
public:
	Engineer()
	{
		mCPP = false;
		mYears = 0;
	}
	Engineer(string fName, string lName, int salary, string title, bool cpp, int years)
	{
		mFirstName = fName;
		mLastName = lName;
		mSalary = salary;
		mTitle = title;
		mCPP = cpp;
		mYears = years;
	}
	bool getCPP() const { return mCPP; }
	int getYears() const { return mYears; }

	void SetData()	{}
	void SaveToFile(ofstream& out)
	{
		out << "Employee Name: " << mFirstName << " " << mLastName << endl
			<< "Employee Salary: " << mSalary << endl
			<< "Employee Title: " << mTitle << endl
			<< "Does Employee Know C++: " << mCPP << endl
			<< "Employee Years of Experience: " << mYears << endl;
	}
};
class Researcher : public Employee
{
private:
	string mPHDSchool;
	string mThesisTopic;
public:
	Researcher()
	{
		mPHDSchool = "Lawrence Tech";
		mThesisTopic = "Computer Science";
	}
	Researcher(string fName, string lName, int salary, string title, string school, string topic)
	{
		mFirstName = fName;
		mLastName = lName;
		mSalary = salary;
		mTitle = title;
		mPHDSchool = school;
		mThesisTopic = topic;
	}
	string getSchool() const { return mPHDSchool; }
	string getTopic() const { return mThesisTopic; }

	void SetData() {}
	void SaveToFile(ofstream& out)
	{
		out << "Employee Name: " << mFirstName << " " << mLastName << endl
			<< "Employee Salary: " << mSalary << endl
			<< "Employee Title: " << mTitle << endl
			<< "Employee School: " << mPHDSchool << endl
			<< "Employee Thesis Topic: " << mThesisTopic << endl;
	}
};

int choices()
{
	int choice;
	cout << "Choose:" << endl << "1: Manager" << endl << "2: Engineer" << endl << "3: Researcher" << endl << "4: Exit" << endl;
	cin >> choice;
	return choice;
}

Employee* selection(int sel)
{
	Employee* empl;
	switch (sel)
	{
	case 1:
	{
		string  name, fName, lName;
		int salary, meetings, vacation;

		cout << "Enter Full Name: ";
		cin >> fName;
		cin >> lName;

		cout << "Enter Salary: ";
		cin >> salary;

		cout << "Enter # of Meetings: ";
		cin >> meetings;

		cout << "Enter # of Vacations: ";
		cin >> vacation;

		Manager man(fName, lName, salary, "Manager", meetings, vacation);
		return &man;
	}
	case 2:
	{
		string  name, fName, lName;
		int salary, years;
		bool CPP;

		cout << "Enter Full Name: ";
		cin >> fName;
		cin >> lName;

		cout << "Enter Salary: ";
		cin >> salary;

		cout << "Enter C++ Knowledge (True or False): ";
		cin >> CPP;

		cout << "Enter Years of Experience: ";
		cin >> years;

		Engineer eng(fName, lName, salary, "Engineer", CPP, years);
		return &eng; }
	case 3:
	{
		string  name, fName, lName, school, thesis;
		int salary;

		cout << "Enter Full Name: ";
		cin >> fName;
		cin >> lName;

		cout << "Enter Salary: ";
		cin >> salary;

		cout << "Enter PHD School: ";
		cin >> school;

		cout << "Enter PHD Thesis Topic: ";
		cin >> thesis;

		Researcher rea(fName, lName, salary, "Researcher", school, thesis);
		return &rea;
	}
	case 4:
	{
		string a;
		cout << "Would you like to save to a file? (y/n): ";
		cin >> a;
		if (a == "y" || a == "Y")
		{
			break;
		}
		else if (a != "n" || a != "N")
		{
			cout << "Try again." << endl;
			selection(sel);
			break;
		}
		else
		{
			break;
		}
	}
	default: { cout << "Try again" << endl; choices(); };
	}
}

int main()
{
	ofstream out;
	out.open("text.txt");
	int sel = 0;
	vector<Employee*> emp;
	do
	{
		sel = choices();
		emp.push_back(selection(sel));
	} while (sel != 4);

	for (int i = 0; i < (int)emp.size(); i++)
	{
		//I could not figure out how to get the next line to work. Everything else in debugging worked.
		//For me, dereferencing this object is quite difficult.
		emp.at(i)->SaveToFile(out);
	}

	return 0;
}