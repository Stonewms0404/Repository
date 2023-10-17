#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cook
{
protected:
	string name, hireDate;
public:
	Cook()
	{
		name = "John Smith";
		hireDate = "MM-DD-YYYY";
	}
	Cook(string aName, string aHireDate)
	{
		setName(aName);
		setHireDate(aHireDate);
	}
	void setName(string aName)
	{
		name = aName;
	}
	string getName()
	{
		return name;
	}
	void setHireDate(string aHireDate)
	{
		hireDate = aHireDate;
	}
	string getHireDate()
	{
		return hireDate;
	}
};

class FastFoodCook : public Cook
{
private:
	int shift;
public:
	FastFoodCook()
	{
		shift = 1;
	}
	FastFoodCook(string aName, string aHireDate, int aShift)
	{
		setShift(aShift);
		setName(aName);
		setHireDate(aHireDate);
	}
	void setShift(int aShift)
	{
		shift = aShift;
	}
	int getShift()
	{
		return shift;
	}
};

//Exceptions for incorrect inputs before they get put into the classes.
class NotAnInteger
{
private:
	string data;
public:
	NotAnInteger(string input)
	{
		data = input;
	}
	string getData()
	{
		return data;
	}
};
class NotAName
{
private:
	string data;
public:
	NotAName(string input)
	{
		data = input;
	}
	string getData()
	{
		return data;
	}
};
class NotADate
{
private:
	string data;
public:
	NotADate(string input)
	{
		data = input;
	}
	string getData()
	{
		return data;
	}
};
class NotAShift
{
private:
	string data;
public:
	NotAShift(string input)
	{
		data = input;
	}
	string getData()
	{
		return data;
	}
};

bool isInt(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			continue;
		}
		else
		{
			throw NotAnInteger(input);
			return false;
		}
	}
	return true;
}
bool isName(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			continue;
		}
		else
		{
			throw NotAName(input);
			return false;
		}
	}
	return true;
}
bool isDate(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) || input[i] == '-')
		{
			continue;
		}
		else
		{
			throw NotADate(input);
			return false;
		}
	}
	return true;
}
int isShift(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) && input[i] == '1')
		{
			return 1;
		}
		else if (isdigit(input[i]) && input[i] == '2')
		{
			return 2;
		}
		else
		{
			throw NotADate(input);
			return false;
		}
	}
	return true;
}


int main()
{
	vector <FastFoodCook*> ffc;
	string name, hireDate, input;
	int empNum, count = -1, shift;
	bool TorF = false, conti = false;
	//Asks how many workers that are going to be entered.
	do
	{
		cout << "How many Workers are to be entered: ";
		cin >> input;
		try
		{
			TorF = isInt(input);
			empNum = stoi(input);
		}
		catch (NotAnInteger i)
		{
			cout << endl << "Not a number. Input of \"" << i.getData() << "\" is not a valid number. Try again." << endl;
			TorF = false;
		}
	} while (!TorF);

	//Gathers information.
	do
	{
		cout << "For Employee " << count + 1 << endl;
		//Asks the name of the employee.
		do
		{
			cout << endl << "Employee's Name: ";
			cin >> input;
			try
			{
				TorF = isName(input);
				name = input;
			}
			catch (NotAnInteger i)
			{
				cout << endl << "Not a name. Input of \"" << i.getData() << "\" is not a valid name. Try again." << endl;
				TorF = false;
			}

		} while (TorF);

		//Asks the Hire Date of the Employee.
		do
		{
			cout << "Employee's Hire Date (MM-DD-YYYY): ";
			cin >> input;
			try
			{
				TorF = isDate(input);
				hireDate = input;
			}
			catch (NotADate i)
			{
				cout << endl << "Not a date. Input of \"" << i.getData() << "\" is not a valid date. Try again." << endl;
				TorF = false;
			}

		} while (TorF);

		//Asks the Shift of the Employee.
		do
		{
			cout << "Employee's Shift (1 is Day, 2 is Night): ";
			cin >> input;
			try
			{
				shift = isShift(input);
				name = input;
				TorF = false;
			}
			catch (NotAShift i)
			{
				cout << endl << "Not a date. Input of \"" << i.getData() << "\" is not a valid date. Try again." << endl;
				TorF = false;
			}

		} while (TorF);


		FastFoodCook emp(name, hireDate, shift);

		ffc[count] = &emp;
		count++;
	} while(count < empNum);

	for (int i = 0; i < empNum; i++)
	{
			cout << "Employee " << i + 1 << "information:" << endl;
			cout << "Employee's Name: " << ffc[i]->getName() << endl;
			cout << "Employee's Hire Date: " << ffc[i]->getHireDate() << endl;
			cout << "Employee's Shift: " << ffc[i]->getShift() << endl << endl;
	}

	return 0;
}