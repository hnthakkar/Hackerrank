#include <bits/stdc++.h>
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
			sort(stringInt+matchIndex+1, stringInt+len);
			for ( int i = 0; i < len; i++){
				char ch = stringInt[i];
				cout << ch;
			}
			cout << endl << flush;
		} else {
			cout << "no answer" << endl;
		}
	}
	return 0;
}
