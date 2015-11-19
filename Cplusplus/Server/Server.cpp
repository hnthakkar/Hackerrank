#include <iostream>
using namespace std;

int main(){
	int t = 1;
	char ch = 0;
	while (cin >> ch) {
		cin.unget();
		int N = 0, T = 0;
		cin >> N >> T;
		int inputs[N];
		for (int i = 0; i < N; i++){
			cin >> inputs[i];
		}
		int sum = 0;
		int index = 0;
		bool alldone = true;
		for (; index < N; index++){
			sum += inputs[index];
			if(sum > T){
				alldone = false;
				break;
			}
		}
		if (alldone){
			cout << "Case " << t << ": " << N << endl;
		} else {
			cout << "Case " << t << ": " << index << endl;
		}
		t++;
	}
	return 0;
}
