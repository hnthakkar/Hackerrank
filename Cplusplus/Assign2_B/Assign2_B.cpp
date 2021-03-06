#include <iostream>
using namespace std;

long long int getLCM(long long int a, long long int b){
	long long int retValue = 0;
	if (a < b) {
		long long int tmp = a;
		a = b;
		b = tmp;
	}
	retValue = a;
	while (retValue % b != 0) {
		retValue += a;
	}
	return retValue;
}

int main() {
	int T;
	cin >> T;
	int primeCheck = 1001;
	int prime[999990] = {};

	prime[0] = 1;
	prime[1] = 1;
	int start = 0;
	int i = 2;
	while( i < primeCheck) {
		if (prime[i] == 0) {
			start = i + i;
			while (start < 999990) {
				prime[start] = 1;
				start += i;
			}
			i++;
		}
		while(prime[i] == 1){
			i++;
		}
	}

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		long long int input[N];
		for (int j = 0; j < N; j++) {
			cin >> input[j];
		}

		long long int LCM = 0;
		LCM = input[0];
		int index = 1;
		while (index < N) {
			LCM = getLCM(LCM, input[index]);
			index++;
		}

		int M = 0;
		int primeFactor[100] = {};
		int primeIndex = 0;
		int curPrimeIndex = 2;
		int divisor = curPrimeIndex++;

		while (LCM >= divisor) {
			if ((LCM % divisor == 0)) {
				M++;
				primeFactor[primeIndex++] = divisor;
				while (LCM % divisor == 0) {
					LCM /= divisor;
				}
			}
			if (LCM == 1)
				break;

			if (LCM < 1000000 && prime[LCM] == 0) {
				M++;
				primeFactor[primeIndex] = LCM;
				break;
			}
			while(curPrimeIndex < 1000000){
				if(prime[curPrimeIndex] == 1){
					curPrimeIndex++;
					continue;
				}
				divisor = curPrimeIndex++;
				break;
			}
		}

		cout << "Case #" << t << ": " << M << endl;
		for (int j = 0; j < M; j++) {
			cout << primeFactor[j] << endl;
		}
		cout << endl;
	}
	return 0;
}
