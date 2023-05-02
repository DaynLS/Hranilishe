#include "BWT.h"

using namespace std;


string BWT(string s, fstream& out)
{
	string code;
	string* parasha;
	int key{ 0 };
	parasha = new string[s.length()];
	parasha[0] = s;
	for (int i = 1; i < s.length(); i++)
	{
		parasha[i].clear();
	}


	for (int i = 1; i < s.length(); i++)
	{
		for (int j = 0; j < s.length(); j++)
		{
			if (j != 0)
			{
				parasha[i] += parasha[i - 1][j - 1];
				//	cout << parasha[i];
			}
			else
			{
				parasha[i] += parasha[i - 1][s.length() - 1];
				//cout << parasha[i][j];
			}
		}
	}


	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s.length() - i - 1; j++)
		{
			if (parasha[j] > parasha[j + 1])
			{
				string tmp = "";
				tmp += parasha[j];
				parasha[j] = parasha[j + 1];
				parasha[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s == parasha[i])
		{
			key = i;
			break;
		}
	}
	//cout << key << endl;
	//out << key << endl;


	for (int i = 0; i < s.length(); i++)
	{
		code += parasha[i][s.length()-1];
	}

	cout << code << endl << endl;
	out << code << endl << endl;

	return code;
}