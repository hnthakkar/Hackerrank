#include <iostream>
using namespace std;

void merge(int l, int m, int r, long int input[]){
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

void mergeSort(int l, int r, long int input[]){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(l,m,input);
		mergeSort(m+1, r, input);
		merge(l, m, r, input);
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		long int M, N;
		cin >> M >> N;
		long int x[M-1];
		for (int i = 0; i < M-1; i++){
			cin >> x[i];
		}
		long int y[N-1];
		for (int i = 0; i < N-1; i++){
			cin >> y[i];
		}
		mergeSort(0,M-2,x);
		mergeSort(0,N-2,y);
		bool xPriority = true;
		if (M < N) {
			xPriority = false;
		}
		unsigned long long int cost = 0;
		long int MIndex = M-2, NIndex = N-2, Xcut = 1, Ycut = 1;
		while(true){
			if(x[MIndex] > y[NIndex]){
				cost += x[MIndex--] * Xcut;
				Ycut++;
			} else if(x[MIndex] < y[NIndex]){
				cost += y[NIndex--] * Ycut;
				Xcut++;
			} else {
				if (xPriority) {
					cost += x[MIndex--] * Xcut;
					Ycut++;
				} else {
					cost += y[NIndex--] * Ycut;
					Xcut++;
				}
			}
			if(MIndex < 0 && NIndex >= 0){
				while(NIndex >= 0){
					cost += y[NIndex--] * Ycut;
				}
			}

			if(NIndex < 0 && MIndex >= 0){
				while(MIndex >= 0){
					cost += x[MIndex--] * Xcut;
				}
			}
			if(MIndex < 0 && NIndex < 0){
				break;
			}
		}
		cout << (cost%1000000007) << endl;
	}
	return 0;
}
