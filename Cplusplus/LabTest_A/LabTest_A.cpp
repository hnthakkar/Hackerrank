#include <bits/stdc++.h>
using namespace std;

int main(){
	int K;
	cin >> K;
	K = K%26;
	cin.ignore();
	string s;
	while (getline(cin, s)) {
		bool isPalan = true;
		int len = s.length();
		int occur[26] = {};
		for (int i = 0; i < len; i++) {
			char ch = s.at(i);
			if (isalpha(ch)) {
				occur[(int) toupper(ch) - 65] = 1;
			}
		}
		for (int i = 0; i < 26; i++){
			if(occur[i] >= 1){
				continue;
			}
			isPalan = false;
			break;
		}
		if(!isPalan){
			cout << "-1";
		} else {
			char ch;
			for (int i = 0; i < len; i++){
				ch = s.at(i);
				if(isalpha(ch)){
					int c = ch;
					if(c > 96){
						c = c + K;
						if (c > 122){
							c = 96 + ( c - 122);
						}
					} else {
						c = c + K;
						if (c > 90){
							c = 64 + (c - 90);
						}
					}
					cout << (char)c;
				} else {
					cout << ch;
				}
			}
		}
		cout << endl << flush;
	}
	return 0;
}
