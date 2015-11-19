#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int start = 0, NMax = 0;
		cin >> start >> NMax;
		int sum = 0, N = 0;
		if(NMax%2 == 1){
			N = 1;
			sum += start;
			N += 2;
			start += 2;
		}else {
			N = 2;
		}

		while(N <= NMax){
			int diaCount = 0;
			while(diaCount < 4 ){
				sum += start;
				diaCount++;
				if(diaCount < 4)
					start += N-1;
			}
			start += N+1;
			N += 2;
		}
		cout << sum << endl;
	}
	return 0;
}
