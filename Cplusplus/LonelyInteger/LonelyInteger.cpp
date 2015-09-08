#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long int input[N];
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int result = input[0];
	for (int i = 1; i < N; i++) {
		result ^= input[i];
	}
	cout << result << endl;
	return 0;
}
