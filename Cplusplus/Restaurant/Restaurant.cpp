#include <iostream>
using namespace std;

int main() {
	long long int sum = 0;
	int index = 1;
	for (int i = 15; i > 0; i--) {
		int tmp = index * (i * (i + 1) / 2);
		cout << tmp << endl;
		sum += tmp;
		index++;
	}
	cout << sum << endl;
	return 0;
}
