#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.length();
		int stringInt[len];
		for (int j = 0; j < len; j++){
			char ch = s.at(j);
			stringInt[j] = (int)ch;
		}

		bool match = false;
		int matchIndex = 0;
		for (int i = len -2; i >= 0; i--){
			if(stringInt[i] < stringInt[i+1]){
				int tmpIndex = i+1;
				while (tmpIndex < len){
					if(stringInt[i] < stringInt[tmpIndex]){
						tmpIndex++;
						continue;
					}
					break;
				}
				tmpIndex--;
				int tmp = stringInt[tmpIndex];
				stringInt[tmpIndex] = stringInt[i];
				stringInt[i] = tmp;
				matchIndex = i;
				match = true;
				break;
			}
		}

		if(match){
			for ( int i = 0; i < matchIndex+1; i++){
				char ch = stringInt[i];
				cout << ch;
			}

			int occur[26] = { };
			for (int j = matchIndex+1; j < len; j++) {
				char ch = stringInt[j];
				occur[(int) toupper(ch) - 65] += 1;
			}

			for (int i = 0; i < 26; i++) {
				int count = occur[i];
				while(count--){
					cout << (char)(i+97);
				}
			}
			cout << endl << flush;
		} else {
			for (int j = len-1; j >= 0; j--) {
				char ch = s.at(j);
				cout << ch;
			}
			cout << endl << flush;
		}
	}
	return 0;
}
