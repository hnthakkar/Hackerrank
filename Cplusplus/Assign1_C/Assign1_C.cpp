#include <iostream>
using namespace std;

bool checkIfPan(long long int num) {
	bool isPan = true;
	int digits[10] = { };
	int unit = 0;
	while (num) {
		unit = num % 10;
		digits[unit] = 1;
		num /= 10;
	}

	for (int i = 1; i < 10; i++) {
		if (digits[i] == 1) {
			continue;
		} else {
			isPan = false;
			break;
		}
	}
	return isPan;
}

int getNextPan(long long int *num1, long long int *num2, int *lastIndex) {
	long long int result = 0l;
	long long int modRange = 1000000000l;
	while (true) {
		result = (*num1 + *num2) % modRange;
		*num1 = *num2;
		*num2 = result;
		*lastIndex += 1;
		if (checkIfPan(result)) {
			break;
		}
	}
	return *lastIndex;
}

int main() {
	int T;
	cin >> T;
	long long int pan[1000] = { };
	long long int num1 = 102334155l;
	long long int num2 = 165580141l;
	int lastFibIndex = 41;

	while (T--) {
		int N = 0;
		long long int sum = 0l, tmp = 0l;
		cin >> N;
		int fibIndex = 0;
		while (N--) {
			if (pan[fibIndex] != 0) {
				sum += pan[fibIndex++];
				continue;
			}
			tmp = getNextPan(&num1, &num2, &lastFibIndex);
			sum += tmp;
			pan[fibIndex++] = tmp;
		}
		cout << sum << endl;
	}
	return 0;
}
