#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	int occurence[26] = {};
	bool match = true;
	for(int i = 0; i < len; i++){
		char ch = s.at(i);
		if(isalpha(ch)){
			occurence[(int)toupper(ch)-65] += 1;
		}
	}

	bool oneDone = false;
	for (int j = 0; j < 26; j++) {
		if (occurence[j] % 2 == 0) {
			continue;
		} else {
			if(!oneDone){
				oneDone = true;
			} else {
				match = false;
				break;
			}
		}

	}

	if(match){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
