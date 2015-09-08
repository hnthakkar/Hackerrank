#include<iostream>
using namespace std;

int main() {
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;

	int shiftCount = num2 / 2;
	int result = 0;
	while (shiftCount--) {
		result += num1 << 1;
	}

	if (num2 % 2 == 1) {
		result += num1;
	}

	cout << result << endl;
	return 0;
}
