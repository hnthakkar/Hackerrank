#include <bits/stdc++.h>
using namespace std;

int main(){
	char ch;
	while(cin >> ch){
		cin.unget();
		int oriRot;
		cin >> oriRot;
		string input;
		cin >> input;
		int len = input.length();
		int item, rot;
		for (int i = len-1; i >= 0; i--){
			rot = oriRot;
			item = input.at(i);
			if ((char)item == '_'){
				if (rot == 1){
					cout << ".";
					continue;
				} else {
					item = 65;
					rot -= 2;
				}
			}

			if ((char) item == '.') {
				if (rot == 1) {
					cout << 'A';
					continue;
				} else {
					item = 65;
					rot -= 1;
				}
			}
			item += rot;
			if (item <= 90){
				cout << (char)item;
			} else {
				int diff = (int)item - 90;
				if (diff == 1){
					cout << '_';
				} else if (diff == 2){
					cout << '.';
				} else {
					item = 64 + (diff - 2);
					cout << (char) item;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
