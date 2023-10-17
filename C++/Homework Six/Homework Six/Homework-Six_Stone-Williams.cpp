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
	//Exception class for an invalid Employee Number
	//Number below 0 or above 9999.
	class InvalidEmployeeNumber
	{
	private:
		int iEmpNum;
	public:
		InvalidEmployeeNumber(int number)
		{
			iEmpNum = number;
		}
		int getNumber()
		{
			return iEmpNum;
		}
	};

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
	void setNumber(int number)
	{
		if (number > 0 && number < 9999)
		{
			eNumber = number;
		}
		else
		{
			throw InvalidEmployeeNumber(number);
		}
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
	string pShift;
	double pPayRate;
public:
	//Exception class for an invalid shift.
	//Shift that isn't 1 or 2.
	class InvalidShift
	{
	private:
		string iEmpShift;
	public:
		InvalidShift(string shift)
		{ iEmpShift = shift; }

		string getIShift() const
		{ return iEmpShift; }
	};
	//Exception class for an invalid pay rate.
	//Pay rate is less than 0.
	class InvalidPayRate
	{
	private:
		int iEmpPayRate;
	public:

		InvalidPayRate(int pay)
		{
			iEmpPayRate = pay;
		}

		int getIPayRate() const
		{
			return iEmpPayRate;
		}
	};

	ProductionWorker()
	{
		pShift = "Day";
		pPayRate = 10.0;
	}
	ProductionWorker(string name, int num, string date, string shift, double rate)
	{
		setName(name);
		setNumber(num);
		setDate(date);
		setShift(shift);
		setRate(rate);
	}
	void setShift(string shift)
	{
		if (shift == "1" || shift == "day")
		{
			pShift = "Day";
		}
		else if (shift == "2" || shift == "night")
		{
			pShift = "Night";
		}
		else
		{
			throw InvalidShift(shift);
		}
	}
	void setRate(double rate)
	{
		if (rate >= 0)
		{
			pPayRate = rate;
		}
		else
		{
			throw InvalidPayRate(rate);
		}
	}
	string getShift() const
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
	string lName, lHireDate, lShift;
	int lNumber;
	double lRate;
	
	cout << "What is the Employee's name?   ";
	getline(cin, lName);

	cout << "What is the Employee's Number?   ";
	cin >> lNumber;

	cout << "When did the Employee get Hired?   ";
	cin >> lHireDate;

	cout << "What shift is the Employee on?   ";
	cin >> lShift;

	cout << "How much does the Employee get paid?   ";
	cin >> lRate;

	try
	{
		ProductionWorker emp1(lName, lNumber, lHireDate, lShift, lRate);

		cout << endl << "Employee's name is: " << emp1.getName() << endl;
		cout << "The number of " << emp1.getName() << " is: " << emp1.getNumber() << endl;
		cout << "The date " << emp1.getName() << " was Hired : " << emp1.getDate() << endl;
		cout << emp1.getName() << " is on Shift : " << emp1.getShift() << endl;
		cout << emp1.getName() << " is getting paid: $" << emp1.getPayRate() << endl;
	}
	catch (Employee::InvalidEmployeeNumber e)
	{
		cout << "Employee Number of " << e.getNumber() << " is invalid. Try again later." << endl;
		return 0;
	}
	catch (ProductionWorker::InvalidShift e)
	{
		cout << "Employee shift of " << e.getIShift() << " is invalid. Try again later." << endl;
		return 0;
	}
	catch (ProductionWorker::InvalidPayRate e)
	{
		cout << "Pay Rate of " << e.getIPayRate() << " is invalid. Try again later." << endl;
		return 0;
	}

	return 0;
}