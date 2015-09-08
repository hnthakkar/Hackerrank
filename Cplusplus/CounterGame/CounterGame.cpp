#include <bits/stdc++.h>
using namespace std;

void getInBinary(unsigned long long int num, int binArray[]) {
	int index = 0;
	while (num) {
		binArray[index++] = num % 2;
		num /= 2;
	}
}

bool isPowerOftwo(int binArray[], int digits) {
	bool retValue = true;;
	int count = 0;
	for (int i = 0; i <= digits; i++){
		if(binArray[i] == 1){
			count++;
			if(count > 1){
				retValue = false;
				break;
			}
		}
	}
	return retValue;
}

int getMSB(int binArray[], int digits) {
	int i = digits;
	for (; i >= 0; i--) {
		if (binArray[i] == 1) {
			break;
		}
	}
	return i;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		unsigned long long int N;
		cin >> N;
		int digits = 0;
		while (pow(2, digits) < N) {
			digits++;
		}
		int counts = 0;
		int bin[digits];
		getInBinary(N, bin);
		while (getMSB(bin, digits) > 0) {
			if (isPowerOftwo(bin, digits)) {
				counts++;
				int index = digits;
				while (bin[index] == 0) {
					index--;
					continue;
				}
				bin[index] = 0;
				bin[index - 1] = 1;
			} else {
				for (int i = digits; i >= 0; i--) {
					if (bin[i] == 1) {
						bin[i] = 0;
						break;
					}
				}
				counts++;
			}
		}

		if (counts % 2 == 0) {
			cout << "Richard" << endl;
		} else {
			cout << "Louise" << endl;
		}
	}
	return 0;
}
