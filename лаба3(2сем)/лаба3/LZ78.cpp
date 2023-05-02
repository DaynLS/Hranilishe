#include "LZ78.h"

using namespace std;


void LZ78(string s, fstream& out)
{
	map <string, int> table;
	map <string, int>::iterator j;
	int counter{1};
	int buff{ 0 };
	string tech, code;

	for (int i = 0; i < s.length();i++)
	{				
		tech += s[i];
		if (table[tech])
		{
			buff = table[tech];
			if (i == s.length() - 1)
			{
				cout << '(' << buff << ',' << '*' << ')';
				out << '(' << buff << ',' << '*' << ')';
			}
		}
		else
		{
			table[tech] = counter;
			counter++;
			cout << '(' << buff << ',' << s[i] << ')';
			out << '(' << buff << ',' << s[i] << ')';
			buff = 0;
			tech.clear();
		}
	}

	cout << endl;
	for (j = table.begin(); j != table.end(); j++)
	{
		cout << j->first << "---" << j->second << endl;
		out << j->first << "---" << j->second << endl;
	}
}