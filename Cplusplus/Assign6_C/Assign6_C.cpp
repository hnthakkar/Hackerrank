#include <iostream>
using namespace std;

long int fib(int N) {
	if (N == 0 || N == 1)
		return 1;
	if (N == 2)
		return 2;
	if (N == 3)
		return 4;

	long int ways[N];
	ways[0] = 1;
	ways[1] = 1;
	ways[2] = 2;
	ways[3] = 4;
	for (int i = 4; i <= N; i++) {
		ways[i] = (ways[i-1] + ways[i-2] + ways[i-3])%1000000007;
	}
	return ways[N];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N = 0;
		cin >> N;
		long int result = fib(N);
		cout << result << endl;
	}
	return 0;
}
