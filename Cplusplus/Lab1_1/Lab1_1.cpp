#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string str1,str2;
		cin >> str1 >> str2;
		int len1 = str1.length();

		int occur1[26] = { };
		for (int j = 0; j < len1; j++) {
			char ch = str1.at(j);
			occur1[(int) toupper(ch) - 65] += 1;
		}

		int len2 = str2.length();
		int occur2[26] = { };
		for (int j = 0; j < len2; j++) {
			char ch = str2.at(j);
			occur2[(int) toupper(ch) - 65] += 1;
		}

		bool match = true;
		for (int i = 0; i < 26; i++) {
			if (occur2[i] == occur1[i]) {
				continue;
			} else {
				match = false;
				break;
			}
		}
		if(match){
			cout << "MINI" << endl;
		} else {
			cout << "MADHUR" << endl;
		}
	}
	return 0;
}
