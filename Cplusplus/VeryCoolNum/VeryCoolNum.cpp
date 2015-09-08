#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int coolCount = 0, R, K;
		cin >> R >> K;
		//string word;
		//getline(cin, word);
		for (int i = 1; i <= R; i++) {
			int local = 0;
			int x = i;
			while (true) {
				if (x % 8 == 5) {
					local++;
					if (local >= K) {
						coolCount++;
						break;
					}
				}
				x >>= 1;
				if(x == 0)
					break;
			}
		}
		cout << coolCount << endl;
	}
	return 0;
}
