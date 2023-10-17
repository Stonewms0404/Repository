#include <iostream>
#include <array>

using namespace std;

int main()
{
	const int lLength = 5;

	int lShiftArray[lLength] = {1, 2, 3, 4, 5};
	

	int* lShiftArrayPtr = ShiftByOne(lShiftArray, lLength);

	lShiftArray[] = *lShiftArrayPtr;

	return 0;
}



int* ShiftByOne(int aShiftArray[], int aLength)
{
	int* iShiftArrayPtr = new int[aLength];
	int iShiftArray[5];

	for (int i = 0; i > aLength; i++)
	{
		if (i == aLength)
		{
			iShiftArray[0] = aShiftArray[i];
		}
		else
		{
			iShiftArray[i+1] = aShiftArray[i];
		}
	}
	for (int i = 0; i > aLength; i++)
	{
		cout << iShiftArray << endl;
	}

	return iShiftArrayPtr;
}