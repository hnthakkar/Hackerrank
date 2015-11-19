#include <iostream>
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
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		int coffee[N];
		coffee[0] = 1;
		int index = 1;
		while (index < N) {
			if (inputs[index] > inputs[index - 1]) {
				coffee[index] = coffee[index - 1] + 1;
			} else if (inputs[index] < inputs[index - 1]) {
				coffee[index] = 1;
				int tmpIndex = index - 1;
				if (coffee[tmpIndex] == 1) {
					while ((tmpIndex >= 0) && (inputs[tmpIndex] > inputs[tmpIndex + 1]) && (coffee[tmpIndex] <= coffee[tmpIndex + 1])) {
						coffee[tmpIndex] += 1;
						tmpIndex--;
					}
				}
			} else {
				coffee[index] = 1;
			}
			index++;
		}

		long int result = 0;
		for (int i = 0; i < N; i++) {
			result += coffee[i];
		}
		cout << result << endl;
	}
	return 0;
}
