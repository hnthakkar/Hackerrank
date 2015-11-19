#include <bits/stdc++.h>
using namespace std;

struct order {
	int value;
	int before;
};

bool ordercompare(order *lhs, order *rhs){
	return lhs->value > rhs->value;
}

void printArray(order *a[], int len){
	for (int i = 0; i < len; i++){
		order *item = a[i];
		cout << endl;
		cout << "Value : " << item->value << " | before : " << item->before << " | Now : " << i;
	}
	cout << endl;
}

int main() {
	int T = 1;
	char ch = 0;
	while (cin >> ch) {
		cin.unget();
		int N;
		cin >> N;
		struct order *judge1[N];
		for (int i = 0; i < N; i++){
			struct order *tmp = new order();
			cin >> tmp->value;
			tmp->before = i;
			judge1[i] = tmp;
		}
		sort(judge1, judge1+N, ordercompare);
		printArray(judge1, N);
		struct order *judge2[N];
		for (int i = 0; i < N; i++) {
			struct order *tmp = new order();
			cin >> tmp->value;
			tmp->before = i;
			judge2[i] = tmp;
		}
		sort(judge2, judge2+N, ordercompare);
		printArray(judge2, N);
		int conflictIndex = -1;
		for (int i = 0; i < N; i++){
			if (judge1[i]->before != judge2[i]->before){
				conflictIndex = i+1;
				break;
			}
		}
		if (conflictIndex == -1){
			cout << "Case " << T << ": agree" << endl;
		} else {
			cout << "Case " << T << ": " << conflictIndex << endl;
		}
		T++;
	}
	return 0;
}

