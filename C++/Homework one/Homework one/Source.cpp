#include <iostream>
#include <array>

using namespace std;

int* ShiftByOne(int[], int);
int* GetMax(int[], int);
unsigned int GetSize(char[]);

int main()
{
	//Initializing the Arrays and Array Lengths.
	int const lArrayLength = 5;
	int lArray[lArrayLength] = { 1, 8, 30, 4, 5 };
	char lcArray[7] = { 'a', 'i', 'b', 'c', 'd', 'r', NULL};


	//Problem one for "ShiftByOne".
	cout << "Problem one \"ShiftByOne\"." << endl;
	int* lShiftPtr = ShiftByOne(lArray, lArrayLength);

	for (int i = 0; i < lArrayLength; i++)
	{
		cout << lArray[i] << endl;
	}


	//Problem two for "GetMax".
	cout << "\nProblem two \"GetMax\"." << endl;
	int* lMaxPtr = GetMax(lArray, lArrayLength);

	cout << "The max value of the Array is: " << endl;
	cout << *lMaxPtr << endl;


	//Problem three for "".
	cout << "\nProblem three \"GetSize\"." << endl;

	unsigned int lSize;
	lSize = (sizeof(lcArray) / sizeof(lcArray[0]));
	cout << "The size of the array is: " << endl;
	cout << lSize << endl;

	return 0;
}


int* ShiftByOne(int aArray[], int aArrayLength)
{
	int aTemp = aArray[aArrayLength-1];

	for (int i = aArrayLength-1; i > 0; i--)
	{
		aArray[i] = aArray[i-1];
	}
	aArray[0] = aTemp;
	return aArray;
}

int* GetMax(int aArray[], int aArrayLength)
{
	int* pMax = &aArray[0];
	for (int i = 0; i < aArrayLength; i++)
	{
		if (aArray[i] > *pMax)
		{
			pMax = &aArray[i];
		}
	}
	return pMax;
}


unsigned int GetSize(char aArray[])
{
	unsigned int aSize = 0;
	while (aArray[aSize] != NULL)
	{
		aSize++;
	}
	return aSize;
}