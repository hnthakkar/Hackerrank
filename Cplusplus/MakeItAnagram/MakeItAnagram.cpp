#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	int occurLen1[26] = {};
	for (int j = 0; j < len1; j++) {
		char ch = s1.at(j);
		occurLen1[(int) toupper(ch) - 65] += 1;
	}

	int occurLen2[26] = {};
	for (int j = 0; j < len2; j++) {
		char ch = s2.at(j);
		occurLen2[(int) toupper(ch) - 65] += 1;
	}

	int diff = 0;
	for (int i = 0; i < 26; i++){
		if(occurLen1[i] > occurLen2[i]) {
			diff += (occurLen1[i] - occurLen2[i]);
		} else {
			diff += (occurLen2[i] - occurLen1[i]);
		}
	}

	cout << diff << endl;

	return 0;
}
