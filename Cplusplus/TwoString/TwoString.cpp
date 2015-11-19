#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int len1 = s1.length();
		int len2 = s2.length();
		int occurLen1[26] = { };
		for (int j = 0; j < len1; j++) {
			char ch = s1.at(j);
			occurLen1[(int) toupper(ch) - 65] += 1;
		}

		int occurLen2[26] = { };
		for (int j = 0; j < len2; j++) {
			char ch = s2.at(j);
			occurLen2[(int) toupper(ch) - 65] += 1;
		}

		bool match = false;
		for (int i = 0; i < 26; i++) {
			if (occurLen1[i] > 0 && occurLen2[i] > 0) {
				match = true;
				break;
			}
		}

		if(match){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
