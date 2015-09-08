#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		long long int inputs[N];
		for (int i = 0; i < N; i++) {
			cin >> inputs[i];
		}

		long long int OR = 0;
		for (int i = 0; i < N; i++) {
			OR |= inputs[i];
		}

		long long int power = 1;
		int count = 0;
		while(count < N-1){
			power *= 2;
			power %= 1000000007;
			count++;
		}
		long long int result = (OR * power) % 1000000007;
		cout << result << endl;
	}
	return 0;
}


/*
#define MOD 1000000007

long long int power(long long int n, long long int k) {
	long long int result, pow;
	if (k == 0)
		return 1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	result = n % MOD;
	pow = 1;
	while (pow * 2 <= k) {
		pow = pow * 2;
		result = (result * result);
		result = result % MOD;
	}

	if (k - pow != 0)
		result = result * power(n, k - pow);
	result = result % MOD;

	return result;
}*/
