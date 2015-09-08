#include<iostream>
using namespace std;

int main() {
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	int count = 0;
	if(num2 == 0){
		cout << "Infinity" << endl;
	} else if (num1 >= num2) {
		while ((num1 = num1 - num2) > -1) {
			count++;
		}
		cout << count << endl;
	}

	return 0;
}
