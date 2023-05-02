#include "AC.h"

using namespace std;


void AC(string s, fstream& out)
{
	map <char, double> table;
	for (int i = 0; i < s.length(); i++)
	{
		table[s[i]]++;
	}
	map <char, double> freq;
	for (int i = 0; i < s.length(); i++)
	{
		freq[s[i]] = table[s[i]] / s.length();
	}
	map <char, double> Tfreq;
	for (int i = 0; i < s.length(); i++)
	{
		Tfreq[s[i]] = table[s[i]] / s.length();
	}

	/*for (auto pair : freq)
	{
		cout << pair.first << "  " << pair.second << endl;
	}
	cout << endl;*/

	double left{ 0 }, right{ 0 };
	for (int i = 0; i < s.length(); i++)
	{
		for (auto pair : Tfreq)
		{
			left += pair.second;
			if (s[i] == pair.first)
			{
				right = left;
				left -= pair.second;
				break;
			}
		}
		for (auto pair : freq)
		{
			Tfreq[pair.first] = (right - left) * pair.second;
			//cout << pair.second << endl;
		}
		//cout << left << "  " << right << endl;
	}
	/*for (auto pair : Tfreq)
	{
		cout << pair.first << "  " << pair.second << endl;
	}*/
	cout << (left+(right-left)/2);
	out << (left + (right - left) / 2);
}