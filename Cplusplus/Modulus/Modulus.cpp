#include <iostream>
using namespace std;

int main() {
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	int tmp = 0;
	if (num1 > num2) {
		while (1) {
			tmp = num1 - num2;
			if (tmp < num2)
				break;
			num1 = tmp;
		}
		cout << tmp << endl;
	} else {
		cout << num1 << endl;
	}
	return 0;
}
