#include <iostream>
#include<map>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* p = new int[n];
		map<int, int> a;
		for (int i = 0; i < n; i++)
			cin >> p[i];
		for (int i = 0; i < n; i++) {
			string k;
			cin >> k;
			for (int j = 0; j < n; j++)
				if (k[j] == '1' && j > i)
					a[i] = j;
		}
		bool flag = false;
		map<int, int>::iterator it;
		while (!flag) {
			flag = true;
			for (it = a.begin(); it != a.end(); it++) {
				int i = it->first;
				int j = it->second;
				if (p[i] > p[j]) {
					int temp = p[i];
					p[i] = p[j];
					p[j] = temp;
					flag = false;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
