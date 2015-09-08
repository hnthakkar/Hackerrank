#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.length();
		if(len % 2 != 0){
			cout << "-1" << endl;
		} else {
			int occur1[26] = {};
			for (int j = 0; j < len/2; j++) {
				char ch = s.at(j);
				occur1[(int) toupper(ch) - 65] += 1;
			}

			int occur2[26] = { };
			for (int j = len/2; j < len; j++) {
				char ch = s.at(j);
				occur2[(int) toupper(ch) - 65] += 1;
			}

			int diff = 0;
			for (int i = 0; i < 26; i++) {
				if (occur2[i] > occur1[i]) {
					diff += (occur2[i] - occur1[i]);
				}
			}
			cout << diff << endl;
		}
	}
	return 0;
}
