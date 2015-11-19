#include <iostream>
using namespace std;

int long long gcd(long long int a, long long int b) {
	long long int r = 0l;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int a = 0l, b = 0l, c = 0l;
		cin >> a >> b >> c;
		if (c == 0) {
			cout << "Andy" << endl;
		} else if ((a == 0 && c != b) || (b == 0 && a != c)) {
			cout << "Bob" << endl;
		} else if ((a == 1 && b >= c) || (b == 1 && a > c) || (a == c) || (b == c)) {
			cout << "Andy" << endl;
		} else if (a > c || b > c) {
			if ((a > b && a % b == 0 && c % b == 0)	|| (b > a && b % a == 0 && c % a == 0)) {
				cout << "Andy" << endl;
			} else if ((a > b && a % b != 0 && (c % (gcd(a, b))) == 0) || (b > a && b % a != 0 && (c % (gcd(b, a))) == 0)) {
				cout << "Andy" << endl;
			} else {
				cout << "Bob" << endl;
			}
		} else {
			cout << "Bob" << endl;
		}
	}
	return 0;
}
