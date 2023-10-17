#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string eName;
	int eNumber;
	string eHireDate;
public:
	Employee()
	{
		eName = "John Smith";
		eNumber = 1111;
		eHireDate = "01-01-2020";
	}
	Employee(string name, int num, string date)
	{
		setName(name);
		setNumber(num);
		setDate(date);
	}
	void setName(string name)
	{
		eName = name;
	}
	void setNumber(int num)
	{
		eNumber = num;
	}
	void setDate(string date)
	{
		eHireDate = date;
	}
	string getName() const
	{
		return eName;
	}
	int getNumber() const
	{
		return eNumber;
	}
	string getDate() const
	{
		return eHireDate;
	}
};

class ProductionWorker : public Employee
{
private:
	int pShift;
	double pPayRate;
public:
	ProductionWorker()
	{
		pShift = 1;
		pPayRate = 10.0;
	}
	ProductionWorker(string name, int num, string date, int shift, double rate)
	{
		setName(name);
		setNumber(num);
		setDate(date);
		setShift(shift);
		setRate(rate);
	}
	void setShift(int shift)
	{
		pShift = shift;
	}
	void setRate(double rate)
	{
		pPayRate = rate;
	}
	int getShift() const
	{
		return pShift;
	}
	double getPayRate() const
	{
		return pPayRate;
	}
};

int main()
{
	string lName, lHireDate, shift;
	int lNumber, lShift;
	double lRate;
	
	cout << "What is the Employee's name?   ";
	getline(cin, lName);

	cout << "What is the Employee's Number?   ";
	cin >> lNumber;

	cout << "When did the Employee get Hired?   ";
	cin >> lHireDate;

	cout << "What shift is the Employee on?   ";
	cin >> shift;
	if (shift == "day" || shift == "1")
		lShift = 1;
	else
		lShift = 2;

	cout << "How much does the Employee get paid?   ";
	cin >> lRate;



	ProductionWorker emp1(lName, lNumber, lHireDate, lShift, lRate);

	cout << endl << "Employee's name is: " << emp1.getName() << endl;
	cout << "The number of " << emp1.getName() << " is: " << emp1.getNumber() << endl;
	cout << "The date " << emp1.getName() << " was Hired : " << emp1.getDate() << endl;
	cout << emp1.getName() << " is on Shift : " << emp1.getShift() << endl;
	cout << emp1.getName() << " is getting paid: $" << emp1.getPayRate() << endl;

	return 0;
}