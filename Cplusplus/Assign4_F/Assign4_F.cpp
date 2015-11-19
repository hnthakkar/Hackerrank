#include <iostream>
#include <climits>
using namespace std;

long kadane(int column[], int size){
	long int overall_max = INT_MIN;
	long int cur_max = INT_MIN;
	for (int i = 0; i < size; i++) {
		cur_max = column[i] > cur_max + column[i] ?	column[i] : cur_max + column[i];
		overall_max = overall_max > cur_max ? overall_max : cur_max;
	}
	return overall_max;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int row = 0, col = 0;
		cin >> row >> col;
		int mat[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> mat[i][j];
			}
		}

		long int max_sum = INT_MIN, cur_sum = INT_MIN;
		int LIndex = 0, RIndex = 0;
		int aux[row];
		while (LIndex < col) {
			for(int i = 0; i < row; i++){
				aux[i] = 0;
			}
			RIndex = LIndex;
			while (RIndex < col) {
				for (int i = 0; i < row; i++){
					aux[i] += mat[i][RIndex];
				}
				cur_sum = kadane(aux, row);
				if(cur_sum > max_sum)
					max_sum = cur_sum;
				RIndex++;
			}
			LIndex++;
		}
		cout << max_sum << endl;
	}
	return 0;
}
