#include <bits/stdc++.h>
using namespace std;

int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		int input[N];
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
		sort(input, input+N);
		int count = 0;
		for (int i = 0; i < N-2; i++) {
			if(input[i] + input[i+1] < input[i+2]){
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
