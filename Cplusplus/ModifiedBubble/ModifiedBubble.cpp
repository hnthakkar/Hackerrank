#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		long long int size[N];
		for (int i = 0; i < N; i++) {
			cin >> size[i];
		}

		int value = 0;
		if (K > N / 2) {
			for (int i = 0; i < K; i++) {
				for (int j = N - 1; j > 0; j--) {
					if (size[j] < size[j - 1]) {
						int tmp = size[j - 1];
						size[j - 1] = size[j];
						size[j] = tmp;
					}

				}
			}
			value = size[N - K];
		} else {
			for (int i = 0; i < K; i++) {
				for (int j = 0; j < N - 1; j++) {
					if (size[j] > size[j + 1]) {
						int tmp = size[j + 1];
						size[j + 1] = size[j];
						size[j] = tmp;
					}
				}
			}
			value = size[N - K];
		}
		cout << value << endl;
	}
	return 0;
}
