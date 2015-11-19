#include <iostream>
using namespace std;

long long int fact(int N){
	long long int ret = 1;
	for (int i = 2; i <= N; i++){
		ret = (ret*i);
	}
	return ret;
}

int main(){
	int N, C;
	cin >> N >> C;
	if (N == 0){
		cout << 0 << endl;
		return 0;
	}

	if (C == 0){
		cout << 1 << endl;
		return 0;
	}

	int set[N];
	for (int i = 0; i < N; i++){
		set[i] = -1;
	}
	int setIndex = 0;
	while(C--){
		int pt1, pt2;
		cin >> pt1 >> pt2;
		if (set[pt1] != -1){
			set[pt2] = set[pt1];
		} else if (set[pt2] != -1){
			set[pt1] = set[pt2];
		} else {
			set[pt1] = set[pt2] = setIndex++;
		}
	}
	long long int num = 1;
	/*if (setIndex == 1){
		num = (num*fact(N))%1000000007;
	} else {*/
		int count[setIndex -1];
		for (int i = 0; i < setIndex; i++){
			count[i] = 0;
		}

		for (int i = 0; i < N; i++){
			if (set[i] == -1)
				continue;
			count[set[i]] += 1;
		}

		for (int i = 0; i < setIndex; i++){
			num = (num*fact(count[i]))%1000000007;
		}
	//}
	cout << num;
	return 0;
}
