#include <bits/stdc++.h>
using namespace std;

void getInBinary(unsigned long long int num, int binArray[]) {
	int index = 0;
	while (num) {
		binArray[index++] = num % 2;
		num /= 2;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		unsigned long long int A = 0, B = 0;
		cin >> A >> B;

		int aBits = 0, bBits = 0;
		unsigned long long int tmp = 1;
		while (tmp <= A) {
			tmp *= 2;
			aBits++;
		}

		tmp = 1;
		while (tmp <= B) {
			tmp *= 2;
			bBits++;
		}

		int aBin[aBits];
		getInBinary(A, aBin);

		int bBin[bBits];
		getInBinary(B, bBin);

		unsigned long long int result = 0;
		if (aBits == bBits) {
			for (int i = aBits - 1; i >= 0; i--) {
				if (aBin[i] != bBin[i])
					break;
				result += (aBin[i] * pow(2, i));
			}
		} else {
			int lesser = 0;
			if (aBits < bBits) {
				lesser = aBits;
			} else {
				lesser = bBits;
			}
			for (int i = 0; i < lesser; i++) {
				if (aBin[i] != bBin[i])
					break;
				result += (aBin[i] * pow(2, i));
			}
		}
		cout << result << endl;
	}
	return 0;
}
