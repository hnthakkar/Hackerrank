#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		/**
		 * 1 -- IM
		 2 -- CA

		 1 & 1 || 2 & 2 ==> 2
		 1 & 2 ==> 1
		 */

		int N = 0;
		cin >> N;
		int input[N];
		string tmp;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			if (tmp == "CA"){
				input[i] = 2;
			} else {
				input[i] = 1;
			}
		}

		int chance = 1;
		for (int j = 1; j < N; j++){
			if (chance == 1){
				if((input[j-1] == 1 && input[j] == 2) || (input[j-1] == 2 && input[j] == 1)){
					input[j] = 1;
				} else {
					int tmp = input[j];
					input[j] = input[j-1];
					input[j-1] = tmp;
					j--;
				}
				chance = 0;
			} else {
				if ((input[j-1] == 1 && input[j] == 1) || (input[j-1] == 2 && input[j] == 2)){
					input[j] = 2;
				} else {
					int tmp = input[j];
					input[j] = input[j - 1];
					input[j - 1] = tmp;
					j--;
				}
				chance = 1;
			}
		}

		if(input[N] == 1){
			cout << "IronMan" << endl;
		} else {
			cout << "Capt.America" << endl;
		}

	}
	return 0;
}
