#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
 * e^x = 1 + x + x^2/2! .....
 */

float factorial(float n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	int x = 0, d = 0;
	cin >> x >> d;
	float result = 0.0f;
	for (int i = 0; i <= d; i++) {
		result += powf(x, i) / factorial(i);
	}
	cout << result << endl;
	return 0;
}
