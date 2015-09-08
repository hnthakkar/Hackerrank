#include <bits/stdc++.h>
using namespace std;

void getInBinary(int num, int binArray[]){
	int index = 0;
	while(num){
		binArray[index++] = num%2;
		num /= 2;
	}
}

int main() {
	int L = 0, R = 0;
	cin >> L >> R;
	int lBits = 0;
	int result = 1;
	while(result < L){
		result *= 2;
		lBits++;
	}

	int rBits = lBits;
	if(result <= R){
		while(result <= R){
			result *= 2;
			rBits++;
		}
	}

	if(lBits == rBits){
		int lowBin[lBits];
		getInBinary(L, lowBin);
		int highBin[lBits];
		getInBinary(R, highBin);
		int i = lBits-1;
		for(; i >= 0; i--){
			if(lowBin[i] == highBin[i]){
				continue;
			}
			break;
		}
		cout << pow(2, i+1) - 1 << endl;
	} else {
		cout << pow(2, rBits) - 1 << endl;
	}
	return 0;
}
