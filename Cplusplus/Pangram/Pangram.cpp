#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	//cin >> s;
	getline(cin, s);
	bool match = true;
	int len = s.length();
	if (len < 26) {
		match = false;
	} else {
		int occurence[26];
		for(int i = 0; i < len; i++){
			char ch = s.at(i);
			if(isalpha(ch)){
				occurence[(int)toupper(ch)-65] = 1;
			}
		}
		for(int j = 0; j < 26; j++){
			if(occurence[j] != 1){
				match = false;
				break;
			}
		}
	}

	if(match){
		cout << "pangram" << endl;
	} else {
		cout << "not pangram" << endl;
	}

	return 0;
}
