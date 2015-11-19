#include <iostream>
#define arraySize  120
using namespace std;

bool arrayEquals(int a[], int b[]){
	bool ret = true;
	for (int i = 0; i < arraySize; i++){
		if(a[i] != b[i]){
			ret = false;
			break;
		}
	}
	return ret;
}

void copyArray(int from[], int to[]){
	for(int i = 0; i < arraySize; i++){
		to[i] = from[i];
	}
}

void min(int a[], int b[], int c[], int ret[]) {
	int i = arraySize -1;
	bool equal = true;
	while (i >= 0) {
		if(a[i] > b[i]){
			copyArray(b, ret);
			equal = false;
			break;
		} if(b[i] > a[i]){
			copyArray(a, ret);
			equal = false;
			break;
		}
		i--;
	}
	if(equal){
		copyArray(b, ret);
	}
	i = arraySize-1;
	while (i >= 0) {
		if(ret[i] > c[i]) {
			copyArray(c, ret);
			break;
		}if(c[i] > ret[i]) {
			break;
		}
		i--;
	}
}

void multiply(int nArray[], int num, int result[]){
	long long int carry = 0;
	int j = 0;
	for(; j < arraySize; j++){
		long long int val = nArray[j] * num + carry;
		carry = val/10;
		result[j] = (val%10);
	}
	while(j < arraySize && carry > 0){
		long long int tmp = carry % 10;
		carry = carry / 10;
		result[j++] = tmp;
	}
}


int main() {
	int T;
	cin >> T;

	int p, q, r;
	cin >> p >> q >> r;
	int kCases[T];
	int max = 0;
	for (int i = 0; i < T; i++) {
		cin >> kCases[i];
		if (max < kCases[i]) {
			max = kCases[i];
		}
	}

	long long int pIndex = 0, qIndex = 0, rIndex = 0;
	int tmp[arraySize]= {0};
	tmp[0] = 1;
	int pNext[arraySize] = {0};
	pNext[0] = 1;
	multiply(tmp, p, pNext);
	int qNext[arraySize] = {0};
	qNext[0] = 1;
	multiply(tmp, q, qNext);
	int rNext[arraySize] = {0};
	rNext[0] = 1;
	multiply(tmp, r, rNext);
	int nextNum[arraySize] = {0};

	int** num = new int*[max];
	for(int j = 0; j < max; j++){
		num[j] = new int[arraySize];
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < arraySize; j++){
			num[i][j] = 0;
		}
	}
	num[0][0] = 1;

	int i =  1;
	while(i < max) {
		min(pNext, qNext, rNext, nextNum);
		copyArray(nextNum, num[i]);
		i++;
		if (arrayEquals(nextNum,pNext)) {
			pIndex++;
			multiply(num[pIndex], p, pNext);
		}
		if (arrayEquals(nextNum,qNext)) {
			qIndex++;
			multiply(num[qIndex], q, qNext);
		}
		if (arrayEquals(nextNum,rNext)) {
			rIndex++;
			multiply(num[rIndex], r, rNext);
		}
	}
	for (int a = 0; a < T; a++) {
		if(kCases[a] == 0){
			cout << 0 << endl;
			continue;
		}
		bool leadZero = true;
		for(int b = 6; b >= 0; b--){
			if(leadZero && num[kCases[a]-1][b] == 0){
				continue;
			}
			leadZero = false;
			cout << (num[kCases[a]-1][b]);
		}
		cout << endl;
	}

	return 0;
}
