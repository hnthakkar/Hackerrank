#include <iostream>
using namespace std;

int main(){
	int T = 1;
	char ch;
	while(cin >> ch){
		cin.unget();
		int w, l;
		cin >> w >> l;
		if (w == 0 && l == 0){
			break;
		}
		char room[l][w];
		int xEntry, yEntry;
		char tmp;
		int direction;
		for (int i = 0; i < l; i++){ //row
			for (int j = 0; j < w; j++) { //column
				cin >> tmp;
				if (tmp == '*') {
					xEntry = i;
					yEntry = j;
					if (i == 0){
						direction = 1; //down
					} else if (j == 0) {
						direction = 2; //right
					} else if (i == l-1){
						direction = 3; //up
					} else {
						direction = 4; //left
					}
				}
				room[i][j] = tmp;
			}
		}

		bool found = false;
		while (true){
			if (found){
				break;
			}
			while (direction == 1){ // down
				xEntry++;
				if (room[xEntry][yEntry] == 'x'){
					room[xEntry][yEntry] = '&';
					found = true;
					break;
				} else if (room[xEntry][yEntry] == '/'){
					direction = 4;
					break;
				} else if (room[xEntry][yEntry] == '\\') {
					direction = 2;
				}
			}

			while (direction == 2) { // right
				yEntry++;
				if (room[xEntry][yEntry] == 'x') {
					room[xEntry][yEntry] = '&';
					found = true;
					break;
				} else if (room[xEntry][yEntry] == '/') {
					direction = 3;
					break;
				} else if (room[xEntry][yEntry] == '\\') {
					direction = 1;
				}
			}

			while (direction == 3) { // UP
				xEntry--;
				if (room[xEntry][yEntry] == 'x') {
					room[xEntry][yEntry] = '&';
					found = true;
					break;
				} else if (room[xEntry][yEntry] == '/') {
					direction = 2;
					break;
				} else if (room[xEntry][yEntry] == '\\') {
					direction = 4;
				}
			}

			while (direction == 4) { // Left
				yEntry--;
				if (room[xEntry][yEntry] == 'x') {
					room[xEntry][yEntry] = '&';
					found = true;
					break;
				} else if (room[xEntry][yEntry] == '/') {
					direction = 1;
					break;
				} else if (room[xEntry][yEntry] == '\\') {
					direction = 3;
				}
			}
		}

		cout << "HOUSE " << T << endl;
		for (int i = 0; i < l; i++) { //row
			for (int j = 0; j < w; j++) { //column
				cout << room[i][j];
			}
			cout << endl;
		}
		T++;
	}
	return 0;
}
