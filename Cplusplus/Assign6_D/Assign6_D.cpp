#include <iostream>
using namespace std;

int getMin(int a, int b){
	if (a < b)
		return a;
	return b;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N = 0;
		cin >> N;
		int input[N][N];
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				input[i][j] = 0;
			}
		}

		int index = 0;
		while(index < N){
			for (int j = 0; j <= index; j++){
				cin >> input[index][j];
			}
			index++;
		}

		for (int i = N-2; i >= 0; i--){
			for (int j = 0; j <= i; j++){
				if (j == 0){
					input[i][j] += getMin( input[i+1][j], input[i+1][j+1]);
				} else {
					input[i][j] += getMin(getMin( input[i+1][j], input[i+1][j+1]),input[i+1][j-1]);
				}
			}
		}
		cout << input[0][0] << endl;
	}
	return 0;
}
