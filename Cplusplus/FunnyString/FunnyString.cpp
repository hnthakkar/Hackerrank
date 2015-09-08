#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		bool match = true;
		int len = s.length();
		if (len > 2) {
			for (int i = 1; i < len; i++) {
				int ldiff = (int)s.at(i) - (int)s.at(i - 1);
				int rdiff = (int)s.at(len - i - 1) - (int)s.at(len - i);
				if(ldiff < 0)
					ldiff *= -1;
				if(rdiff < 0)
					rdiff *= -1;

				if (ldiff == rdiff)
					continue;
				match = false;
				break;
			}
		}

		if(match){
			cout << "Funny" << endl;
		} else {
			cout << "Not Funny" << endl;
		}
	}
	return 0;
}
