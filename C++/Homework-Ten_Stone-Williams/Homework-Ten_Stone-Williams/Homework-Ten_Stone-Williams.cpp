#include <iostream>
#include <string>

using namespace std;

//Cleans the string of any capitals by making them lowercase,
//And gets rid of every punctuation and space.
string clean(string a)
{
	string cl;
	for (int i = 0; i < a.length(); i++)
	{
		if (isalnum(a[i]) && !isupper(a[i]))
		{
			cl += a[i];
		}
		else if (isupper(a[i]))
		{
			cl += tolower(a[i]);
		}
	}
	return cl;
}

//Reverses the string and outputs it.
string reverse(string a)
{
	string b;
	for (int i = 0; i < a.length(); i++)
	{
		b = a[i] + b;
	}
	return b;
}

//Recursive method to check if something is a palindrome.
//Checks by iterating through using the integer "times".
//If it matches, it calls the method again and adds one to the times variable.
//Ends if the string length is reached by the iterator.
bool palin(string a, string b, int times)
{
	bool condi = false;
	if (times == a.length())
	{
		condi = true;
	}
	else if (a[times] != b[times])
	{
		condi = false;
	}
	else
	{
		condi = palin(a, b, times + 1);
	}
	return condi;
}

int main()
{
	string input;
	cout << "Enter a phrase and I will tell you" <<
		" if it is a Palindrome: ";
	getline(cin, input);

	string in = clean(input);
	string rev = reverse(in);

	//"palin" returns a boolean if the phrase is a palindrome or not.
	if (palin(in, rev, 0))
	{
		cout << endl << "The phrase \"" << input << "\" is a Palindrome!" << endl;
	}
	else
	{
		cout << endl << "The phrase is not a Palindrome." << endl;
	}

	return 0;
}