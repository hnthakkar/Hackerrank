#include <bits/stdc++.h>
using namespace std;

int main() {
	long int size;
	int T = 1;
	while (scanf("%ld", &size) != EOF) {
		long long int count = 1;
		int degree = 1, number = 2, elemCount = 1;
		while (elemCount < size) {
			count += number * pow(2, degree);
			elemCount += pow(2, degree);
			degree++;
			number++;
		}
		if (elemCount - size > 0) {
			count -= (elemCount - size) * (number - 1);
		}
		cout << "Case " << T << ": " << count << endl;
		T++;
	}
	return 0;
}
