#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int A = 0l, B = 0l;
		cin >> A >> B;
		if (A==B){
			cout << A << endl;
			continue;
		}
		long long int tmp = 0l;
		int AbinArrray[32];
		fill_n(AbinArrray, 32, 0);
		tmp = A;
		int Aindex = 0;
		int AlastOneIndex = 0;
		while (tmp) {
			AbinArrray[Aindex] = tmp % 2;
			if (AbinArrray[Aindex] == 1)
				AlastOneIndex = Aindex;
			tmp /= 2;
			Aindex++;
		}

		int BbinArrray[32];
		fill_n(BbinArrray, 32, 0);
		tmp = B;
		int Bindex = 0;
		int BlastOneIndex = 0;
		while (tmp) {
			BbinArrray[Bindex] = tmp % 2;
			if (BbinArrray[Bindex] == 1)
				BlastOneIndex = Bindex;
			tmp /= 2;
			Bindex++;
		}

		if (AlastOneIndex == BlastOneIndex) {
			bool leadMacth = true;
			while (AlastOneIndex--) {
				if (leadMacth && AbinArrray[AlastOneIndex] == BbinArrray[AlastOneIndex]) {
					continue;
				} else {
					leadMacth = false;
					AbinArrray[AlastOneIndex] = 0;
				}
			}
			long long result = 0l;
			long long base = 1l;
			for (int j = 0; j < 32; j++) {
				result += (base * AbinArrray[j]);
				base *= 2;
			}
			cout << result << endl;
		} else {
			cout << 0 << endl;
		}

	}

	return 0;
}
