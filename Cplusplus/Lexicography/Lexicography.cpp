#include <bits/stdc++.h>
using namespace std;

long long int fact (int num){
	long long ret = 1;
	for (int i = 2; i <= num; i++){
		ret *= i;
	}
	return ret;
}

int main() {
	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			cin >> s;
			if (s == "0") {
				break;
			}
		}
		long long int k;
		cin >> k;

		int len = s.length();
		int stringInt[len];
		int occur[26] = {};
		for (int j = 0; j < len; j++) {
			char ch = s.at(j);
			stringInt[j] = (int) ch;
			occur[(int)ch - 65] += 1;
		}
		sort(stringInt, stringInt + len);

		//int finalOrder[len];

		float tmpLen = len;
		for (int i = 0; i < len; i++){
			float denom = 1;
			for (int j = 0; j < 26; j++){
				if (occur[j] > 1){
					denom *= fact(occur[j]);
				}
			}
			float division = fact(tmpLen-1)/denom;
			int pos = ceil(k/division);
			/*if (pos <= 0)
				pos = 1;*/
			int count = -1;
			int elem = -1;
			for (int j = 0; j < len; j++){
				if (stringInt[j] == -1){
					continue;
				}
				count++;
				if (count == pos -1){
					elem = stringInt[j];
					if (occur[stringInt[j] - 65] > 1) {
						occur[stringInt[j] - 65] -= 1;
					}
					stringInt[j] = -1;
					break;
				}
			}
			cout << (char)elem;
			//finalOrder[i] = elem;
			//cout << "i=" << i << "value: " << finalOrder[i] << endl;

			tmpLen--;
			k -= division * (pos -1);
		}

		/*for (int a = 0; a < len; a++) {
			int item = finalOrder[0];
			cout << finalOrder[0];
			cout << (char)finalOrder[a];
		}*/

		/*for (int x = 0; x < len; x++){

		}*/
		cout << endl << flush;
	}
	return 0;
}
