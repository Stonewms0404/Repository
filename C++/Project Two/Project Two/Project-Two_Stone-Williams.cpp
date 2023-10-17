#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

class PersonData
{
protected:
	string lastName, firstName, address, city, state, phone;
	int zip;
public:
	PersonData()
	{
		lastName = "Smith";
		firstName = "John";
		address = "123 Oak Street";
		city = "Oakland";
		state = "MI";
		zip = 12345;
		phone = 1234567890;
	}
	PersonData(string aLastName, string aFirstName, string aAddress, string aCity, string aState, int aZip, string aPhone)
	{
		setLName(aLastName);
		setFName(aFirstName);
		setAddress(aAddress);
		setCity(aCity);
		setState(aState);
		setZip(aZip);
		setPhone(aPhone);
	}
	~PersonData()
	{

	}
	void setLName(string aLastName)
	{
		lastName = aLastName;
	}
	string getLName() const 
	{
		return lastName;
	}
	void setFName(string aFirstName)
	{
		firstName = aFirstName;
	}
	string getFName() const
	{
		return firstName;
	}
	void setAddress(string aAddress)
	{
		address = aAddress;
	}
	string getAddress()const
	{
		return address;
	}
	void setCity(string aCity)
	{
		city = aCity;
	}
	string getCity()const
	{
		return city;
	}
	void setState(string aState)
	{
		state = aState;
	}
	string getState()const
	{
		return state;
	}
	void setPhone(string aPhone)
	{
		phone = aPhone;
	}
	string getPhone()const
	{
		return phone;
	}
	void setZip(int aZip)
	{
		zip = aZip;
	}
	int getZip()const
	{
		return zip;
	}
};
class CustomerData : public PersonData
{
private:
	int customerNumber;
	int custNumbers[10];
	bool mailingList;
public:
	//Incorrect format for the Customer Number.
	class IncorrectCustNumber
	{
	private:
		string number;
	public:
		IncorrectCustNumber(string num)
		{
			number = num;
		}
		string getNumber()
		{
			return number;
		}
	};
	class IncorrectLength
	{
	private:
		string data;
	public:
		IncorrectLength(string dat)
		{
			data = dat;
		}
		string getData()
		{
			return data;
		}
	};
	//Customer Number is not unique.
	class IsNotUnique
	{
	private:
		string number;
	public:
		IsNotUnique(string numb)
		{
			number = numb;
		}
		string getNumber()
		{
			return number;
		}
	};
	CustomerData()
	{
		customerNumber = 0;
		mailingList = true;
	}
	CustomerData(string aLastName, string aFirstName, string aAddress, string aCity, string aState, int aZip, string aPhone, int aCustomerNumber, bool aMailingList)
	{
		setLName(aLastName);
		setFName(aFirstName);
		setAddress(aAddress);
		setCity(aCity);
		setState(aState);
		setZip(aZip);
		setPhone(aPhone);
		setCustNumber(aCustomerNumber);
		setMailingList(aMailingList);
	}
	~CustomerData()
	{

	}
	void setCustNumber(int aCustomerNumber)
	{
		customerNumber = aCustomerNumber;
	}
	int getCustNumber() const
	{
		return customerNumber;
	}
	void setMailingList(bool aMailingList)
	{
		mailingList = aMailingList;
	}
	bool getMailingList() const
	{
		return mailingList;
	}
};

//Checks if a customer number is a number and if it is unique.
bool isUnique(string input, CustomerData* customers[], int count)
{
	if (input.length() != 6)
	{
		throw CustomerData::IncorrectLength(input);
	}

	//For-loop to find out if the input is an integer.
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			continue;
		}
		else
		{
			throw CustomerData::IncorrectCustNumber(input);
		}
	}

	//For-loop to loop through the CustomerData objects
	//to see if any number has been used before.
	for (int i = 0; i < count; i++)
	{
		if (stoi(input) == (customers[i]->getCustNumber()))
		{
			throw CustomerData::IsNotUnique(input);
		}
		else
		{
			continue;
		}
	}
	return false;
}

int main()
{
	//An array of CustomerData objects called customers.
	CustomerData** customers = new CustomerData*[5];
	int count, zip;
	string input, lName, fName, address, city, state, phone;
	bool mailingList;

	//File creator/writer variable.
	ifstream file;
	file.open("CustomerInfo.txt");

	//Starts at the point of the iterator times ten lines.
	

	//Calling a method within a for-loop to gather all objects form a file.
	for (int i = 0; i < 5; i++)
	{
		count = 0;
		bool conti = false;
		string input = "";

		for (int f = 0; f < 9; f++)
		{
			getline(file, input);
			switch (count)
			{
			case 0:
				lName = (input);
				break;
			case 1:
				fName = (input);
				break;
			case 2:
				address = (input);
				break;
			case 3:
				city = (input);
				break;
			case 4:
				state = (input);
				break;
			case 5:
				zip = stoi(input);
				break;
			case 6:
				phone = (input);
				break;
			case 7:
				mailingList = (input == "true");
				break;
			case 8:
				customers[i] = new CustomerData(lName, fName, address, city, state, zip, phone, 0, mailingList);
				break;
			}
			count++;
		}

		do
		{
			try
			{
				cout << "What is " << customers[i]->getFName() << " " << customers[i]->getLName() << "'s unique six digit customer number?" << endl;
				cin >> input; cout << endl;
				conti = isUnique(input, customers, i);
				customers[i]->setCustNumber(stoi(input));
				conti = false;
			}
			catch (CustomerData::IncorrectCustNumber e)
			{
				cout << "Input of \"" << e.getNumber() << "\" is in the incorrect format. Try Again." << endl << endl;
				conti = true;
			}
			catch (CustomerData::IsNotUnique e)
			{
				cout << "Input of \"" << e.getNumber() << "\" is not unique. Try Again." << endl << endl;
				conti = true;
			}
			catch (CustomerData::IncorrectLength e)
			{
				cout << "Input of \"" << e.getData() << "\" is not six digits. Try Again." << endl << endl;
				conti = true;
			}
		} while (conti);
	}

	//A for-loop that loops through the customers
	//and finds all customers that are on the mailing list.
	cout << endl << "The customers on the mailing list are: " << endl;
	for (int i = 0; i < 5; i++)
	{
		if (customers[i]->getMailingList())
		{
			cout << customers[i]->getLName() << "\n" <<
					customers[i]->getFName() << "\n" <<
					customers[i]->getAddress() << "\n" <<
					customers[i]->getCity() << "\n" <<
					customers[i]->getState() << "\n" <<
					customers[i]->getZip() << "\n" <<
					customers[i]->getPhone() << "\n" << "\n";
		}
		delete customers[i];
	}

	cout << endl << "Completed. Closing..." << endl;
	file.close();
	return 0;
}