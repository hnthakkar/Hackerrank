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
		int occur[26] = {};
		int matchCount = 0;
		for (int j = 0; j < len; j++) {
			char ch = s.at(j);
			occur[(int) toupper(ch) - 65] += 1;
		}

		for (int j = 0; j < 26; j++ ){
			if(occur[j] > 1){
				matchCount = occur[j] * (occur[j] - 1)/2;
			}
		}

		int window = 2;
		bool repeat = false;

		if(repeat){
			while(window < len){
				int refWinSIndex = 0;
				while (refWinSIndex < len) {
					if (occur[toupper(s.at(refWinSIndex)) - 65] > 1) {
						repeat = true;
						break;
					} else {
						refWinSIndex++;
					}
				}
				int fRefOccur[26] = {};
				char refStartChar;
				if((refWinSIndex + window) < len){
					string fRefString = s.substr(refWinSIndex, window);
					refStartChar = fRefString.at(0);
					for (int j = 0; j < window; j++) {
						char ch = fRefString.at(j);
						fRefOccur[(int) toupper(ch) - 65] += 1;
					}
				}
				int bRefOccur[26] = {};
				if(refWinSIndex-window >= 0){
					string bRefString = s.substr(refWinSIndex-window, window);
					refStartChar = bRefString.at(window-1);
					for (int j = 0; j < window; j++) {
						char ch = bRefString.at(j);
						bRefOccur[(int) toupper(ch) - 65] += 1;
					}
				}
				int checkWinSIndex = refWinSIndex + 1;
				while(checkWinSIndex < len){
					while (checkWinSIndex < len) {
						if (s.at(checkWinSIndex) == refStartChar) {
							break;
						} else {
							checkWinSIndex++;
						}
					}

					string checkString = s.substr(checkWinSIndex, window);
					int fCheckOccur[26] = {};
					for (int j = 0; j < window; j++) {
						char ch = checkString.at(j);
						fCheckOccur[(int) toupper(ch) - 65] += 1;
					}

					string checkString = s.substr(checkWinSIndex, window);
					int fCheckOccur[26] = { };
					for (int j = 0; j < window; j++) {
						char ch = checkString.at(j);
						fCheckOccur[(int) toupper(ch) - 65] += 1;
					}

					checkWinSIndex++;
				}
				window++;
			}
		}
	}
	return 0;
}
