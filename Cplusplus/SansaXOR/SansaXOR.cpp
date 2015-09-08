#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int inputs[N];
		for (int i = 0; i < N; i++) {
			cin >> inputs[i];
		}

		if (N % 2 == 0) {
			cout << 0 << endl;
		} else {
			int result = 0, repeat = N, mid = (N + 1) / 2 - 1;
			int repeatArray[mid];
			repeatArray[0] = N;
			int midIndex = 0;
			for (int i = 0; i < N; i++) {
				if (repeat % 2 != 0)
					result ^= inputs[i];
				if (i < mid) {
					repeat += (N - 2 * (i + 1));
					repeatArray[++midIndex] = repeat;
				} else {
					repeat = repeatArray[--midIndex];
				}
			}
			cout << result << endl;
		}
	}
	return 0;
}
