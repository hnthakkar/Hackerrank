#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.length();
		int count = 0;
		char ch, chance = s.at(0);
		for(int i = 0; i < len; i++){
			ch = s.at(i);
			if( ch == 'A' && chance == 'A'){
				count++;
				chance = 'B';
			} else if (ch == 'B' && chance == 'B'){
				count++;
				chance = 'A';
			}
		}
		cout << (len - count) << endl;
	}
	return 0;
}
