#include <iostream>
using namespace std;

bool checkIfPalin(string input, int lptr, int rptr){
	bool retIndex = true;
	while(lptr < rptr){
		if (input[lptr] == input[rptr]) {
			lptr++;
			rptr--;
			continue;
		}
		retIndex = false;
		break;
	}
	return retIndex;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		string input;
		cin >> input;
		int size = input.size();
		int lptr = 0;
		int rptr = size - 1;
		int index = -1;
		while (lptr < rptr){
			if (input[lptr] == input[rptr]){
				lptr++; rptr--;
				continue;
			}

			if (input[lptr] == input[rptr-1] && checkIfPalin(input, lptr, rptr - 1)){
				index = rptr;
			} else {
				index = lptr;
			}
			break;
		}
		cout << index << endl;
	}
	return 0;
}
