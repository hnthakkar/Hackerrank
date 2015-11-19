#include <iostream>
using namespace std;

int main() {
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	int tmp = 0;
	while (num2 != 0) {
		tmp = num1 % num2;
		num1 = num2;
		num2 = tmp;
	}
	cout << num1 << endl;
	return 0;
}
