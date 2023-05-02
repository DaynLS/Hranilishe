#include "RKE.h"

using namespace std;


string RKE(string s, fstream &out)
{
	int counter = 0;
	char buff;
	string tech;

	for (int i = 0; i < s.length();)
	{
		buff = s[i];
		while (s[i] == buff)
		{
			counter++;
			i++;
		}
		tech += buff;
		cout << counter << buff;
		out << counter << buff;
		counter = 0;
	}
	
	cout << endl << endl;
	out << endl << endl;

	return tech;
}