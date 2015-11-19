#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int score = 0l, tmp = 0l;
		cin >> score;
		int binArrray[32];
		fill_n(binArrray, 32, 0);
		tmp = score;
		int index = 0;
		while(tmp){
			binArrray[index] = tmp%2;
			tmp /= 2;
			index++;
		}

		bool match = false;
		int oneCountBefore = 0;
		for(int i = 0; i < 31; i++){
			if(binArrray[i] == 1 && binArrray[i+1] == 0){
				binArrray[i] = 0;
				binArrray[i+1] = 1;
				for(int j = 0; j < i; j ++){
					if(j < oneCountBefore){
						binArrray[j] = 1;
					} else {
						binArrray[j] = 0;
					}
				}
				match = true;
				break;
			} else if (binArrray[i] == 1){
				oneCountBefore++;
			}
		}

		if(!match){
			cout << score << endl;
		} else {
			long long result = 0l;
			long long base = 1l;
			for (int  j = 0; j < 32; j++){
				result += (base * binArrray[j]);
				base *= 2;
			}
			cout << result << endl;
		}
	}
	return 0;
}
