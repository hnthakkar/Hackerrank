#include <stdio.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long double num, zero = 0.0, neg = -1.0;
		scanf("%Lf",&num);
		if (num == 0) {
			printf("%Lf\n", zero);
		} else if (num < 0) {
			printf("%Lf\n", neg);
		} else if (num > 0 && num < 1) {
			long double tmp = num;
			long double mulFac = 1.0;
			while (tmp < 1) {
				mulFac *= 10;
				tmp *= 10;
			}
			long double x = num * mulFac;
			long double y = 0;
			long double e = 0.000000001;
			while (x - y >= e) {
				x = (x + y) / 2;
				y = num / x;
			}
			printf("%Lf\n", x);
		} else {
			long double x = num;
			long double y = 1;
			long double e = 0.000000001;
			while (x - y >= e) {
				x = (x + y) / 2;
				y = num / x;
			}
			printf("%Lf\n", x);
		}
	}
	return 0;
}
