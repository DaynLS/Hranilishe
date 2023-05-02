#include "MTF.h"

using namespace std;


string MTF(string s, fstream& out)
{
	string result = "";
	map <char, int> tempAlph;

	for (int i = 0; i < s.size(); i++)
	{
		tempAlph[s[i]];
	}

	string alph;
	for (auto pair : tempAlph)
	{
		alph += pair.first;
	}


	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < alph.size(); j++)
		{
			if (s[i] == alph[j])
			{
				result += to_string(j);
				alph.insert(alph.begin(), alph[j]);
				alph.erase(j + 1, 1);
				break;
			}
		}
		result += " ";
	}
	result.pop_back();

	cout << result << endl << endl;
	out << result << endl << endl;

	
	return result;
}