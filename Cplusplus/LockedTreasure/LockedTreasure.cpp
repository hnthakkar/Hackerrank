#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int t = 1;
	while (T--) {
		int n = 0, k = 0;
		cin >> n >> k;
		if (n == k){
			cout << "Case " << t << ": " << n << endl;
			t++;
			continue;
		}

		if (k == 1) {
			cout << "Case " << t << ": " << 1 << endl;
			t++;
			continue;
		}
		k = k - 1;
		int numerator[30];
		for (int i = 0; i < n; i++){
			numerator[i] = 0;
		}
		int lower = k > (n - k) ? k : (n - k);
		for (int i = n; i > lower; i--) {
			numerator[i] = i;
			//cout << i << endl;
		}
		int otherLower = 0;
		if ( k == lower ){
			otherLower = n-k;
		} else {
			otherLower = k;
		}
		int denom[otherLower];
		for (int i = 0; i < otherLower; i++) {
			denom[i] = 0;
		}
		for (int i = otherLower; i > 1; i--) {
			denom[i] = i;
		}
		for (int i = otherLower; i > 1; i--) {
			for (int j = n; j > lower; j--) {
				if (numerator[j] != 0 && numerator[j] % i == 0) {
					//cout << numerator[j] << "%" << denom[i] << "=" << numerator[j]/denom[i] << endl;
					numerator[j] /= denom[i];
					denom[i] = 1;
					break;
				}
			}
		}
		long long int bottom = 1;
		for (int i = otherLower; i > 1; i--) {
			if (denom[i] > 1) {
				//cout << denom[i] << "*";
				bottom *= denom[i];
			}
		}

		long long top = 1;
		for (int i = n; i > 1; i--) {
			if (numerator[i] > 1) {
				//cout << numerator[i] << "*";
				top *= numerator[i];
			}
		}

		cout << "Case " << t << ": " << (top/bottom) << endl;
		t++;
	}
	return 0;
}
