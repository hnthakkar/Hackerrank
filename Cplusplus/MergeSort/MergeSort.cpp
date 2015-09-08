#include <iostream>
using namespace std;

void merge(int l, int m, int r, long long int input[]){
	int LSize = m - l + 1;
	int RSize = r - m;

	int LTmp[LSize];
	int RTmp[RSize];

	for(int i = 0; i < LSize; i++ ){
		LTmp[i] = input[l + i];
	}

	for (int i = 0; i < RSize; i++ ){
		RTmp[i] = input[m + 1 + i];
	}

	int lIndex = 0;
	int RIndex = 0;
	int index = l;
	while(lIndex < LSize && RIndex < RSize){
		if(LTmp[lIndex] <= RTmp[RIndex]){
			input[index++] = LTmp[lIndex++];
		} else {
			input[index++] = RTmp[RIndex++];
		}
	}

	while (lIndex < LSize){
		input[index++] = LTmp[lIndex++];
	}

	while (RIndex < RSize){
		input[index++] = RTmp[RIndex++];
	}
}

void mergeSort(int l, int r, long long int input[]){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(l,m,input);
		mergeSort(m+1, r, input);
		merge(l, m, r, input);
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int N = 0, K = 0;
		cin >> N >> K;
		long long int input[N];
		for (int i = 0; i < N; i++){
			cin >> input[i];
		}
		mergeSort(0, N-1,input);
		cout << input[N - K] << endl;
	}
	return 0;
}
