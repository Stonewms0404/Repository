#include <iostream>
#include <string>

using namespace std;

class StudentClass
{
private:
	string mName;
public:
	//Constructor is nothing is an argument.
	StudentClass()
	{
		mName = "";
	}

	//Overloaded constructor if a string is an argument.
	StudentClass(string name)
	{
		mName = name;
	}
	
	//Overloading the operator of = to make "mName" equal the StudentClass object's mName.
	void operator = (string name)
	{
		mName = name;
	}

	//Overloading the operator of + to add a space after what is already in mName.
	void operator + (string name)
	{
		mName += " " + name;
	}

	//Overloading the operator of [] to get the char at the index of the input.
	char operator [] (const int x)
	{
		return mName[x];
	}

	//Overloading the operator of << to output to
	//the console the mName of the StudentClass object.
	void operator << (const StudentClass Student)
	{
		cout << Student.mName << endl;
	}

	//Overloading the operator of >> to grab an input string from
	//console user input to assign to the StudentClass's mName.
	void operator >> (StudentClass Student)
	{
		string name;
		cin >> name;
		Student.mName = name;
	}

	//
	int oCount(const StudentClass Student)
	{
		return Student.mName.length();
	}

	//Function to reverse the mName of the StudentClass object by
	//taking the length of the mName and finding each character of the mName
	//and adding it to a string variable backwards and returning it back to the user.
	string oReverse(const StudentClass Student)
	{
		string name;
		for (int i = Student.mName.length()-1; i >= 0; i--)
		{
			name += Student.mName[i];
		}
		return name;
	}
};

int main()
{
	//Declaring Variables.
	StudentClass student("Stone");
	string name1 = "Henry";
	

	//Testing operator =.
	student = name1;
	student << student;

	//Testing operator +.
	student + "Emily";
	student << student;

	//Testing operator >>.
	student >> student;
	student << student;

	//Testing operator [].
	char stu = student[5];
	cout << stu << endl;

	//Testing oCount().
	cout << student.oCount(student);

	//Testing oReverse().
	cout << student.oReverse(student);


	return 0;
}