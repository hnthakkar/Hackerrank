#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long int N = 0, K = 0;
		cin >> N >> K;
		long long int inputs[N];
		for (int j = 0; j < N; j++){
			cin >> inputs[j];
		}
		int mid = 0;
		if(N%2 == 0){
			mid = N/2;
		} else {
			mid = N/2 -1;
		}

		if(K <= mid){
			for(int i = 0; i < K; i++){
				for (int j = 0; j < N-i-1; j++){
					if(inputs[j] > inputs[j+1]){
						long long int tmp = inputs[j];
						inputs[j] = inputs[j+1];
						inputs[j+1] = tmp;
					}
				}
			}
			cout << inputs[N-K] << endl;
		} else {
			for (int i = 0; i <= N-K; i++){
				for (int j = N-1; j >= i+1; j-- ){
					if(inputs[j] < inputs[j-1]){
						long long int tmp = inputs[j];
						inputs[j] = inputs[j-1];
						inputs[j-1] = tmp;
					}
				}
			}
			cout << inputs[N-K] << endl;
		}
	}
	return 0;
}
