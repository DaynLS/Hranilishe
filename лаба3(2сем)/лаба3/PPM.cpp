#include "PPM.h"

using namespace std;


void PPM(string s, fstream& out)
{
	map<string, int> freq;
	string result = "";
	for (int i = 0; i < s.length(); i++) {
		string context = "";
		int max_order = min(i, 5);
		for (int j = 1; j <= max_order; j++) {
			context = s.substr(i - j, j);
			if (freq.count(context)) {
				break;
			}
		}
		if (freq.count(context)) {
			char new_ch = 0;
			int new_freq = 0;
			for (char c = 0; c < 128 && c > 0; c = c +1) {
				string str = context + c;
				if (freq.count(str) && freq[str] >
					new_freq) {
					new_ch = c;
					new_freq = freq[str];
				}
			}
			result += new_ch;
			freq[context + new_ch]++;
		}
		else {
			result += s[i];
			freq[string(1, s[i])]++;
		}
	}
	cout << result << endl;
}