#include <iostream>
using namespace std;

int main(){
	char ref[16][4];
	ref[0] = {0,0,0,0};
	ref[1] = {0,0,0,1};
	ref[2] = {0,0,1,0};
	ref[3] = {0,0,1,1};
	ref[4] = {0,1,0,0};
	ref[5] = {0,1,0,1};
	ref[6] = {0,1,1,0};
	ref[7] = {0,1,1,1};
	ref[8] = {1,0,0,0};
	ref[9] = {1,0,0,1};
	ref[10] = {1,0,1,0};
	ref[11] = {1,0,1,1};
	ref[12] = {1,1,0,0};
	ref[13] = {1,1,0,1};
	ref[14] = {1,1,1,0};
	ref[15] = {1,1,1,1};
	while(true){
		int row = 0, column = 0;
		cin >> row >> column;
		if (row == 0 && column == 0)
			break;
		char input[row][column];
		char tmp;
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0, direction = -1;
		bool entryFound = false;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				cin >> tmp;
				if (i == 0 && (tmp == '0' || tmp == '1' || tmp == '2' || tmp == '3' || tmp == '4' || tmp == '5' || tmp == '6' || tmp == '7')){
					if (!entryFound) {
						x1 = i; y1 = j;
						entryFound = false;
					} else {
						x2 = i; y2 = j;
					}
					direction = 1; //down;
				} else if (j == 0 && (tmp == '0' || tmp == '2' || tmp == '4' || tmp == '6' || tmp == '8' || tmp == 'A' || tmp == 'C' || tmp == 'E')){
					if (!entryFound) {
						x1 = i;
						y1 = j;
						entryFound = false;
					} else {
						x2 = i;
						y2 = j;
					}
					direction = 2; //right;
				} else if (j == (column - 1) && (tmp == '0' || tmp == '1' || tmp == '2' || tmp == '3' || tmp == '8' || tmp == '9' || tmp == 'A' || tmp == 'B')){
					if (!entryFound) {
						x1 = i;
						y1 = j;
						entryFound = false;
					} else {
						x2 = i;
						y2 = j;
					}
					direction = 3; //left;
				} else if (i == (row-1) && (tmp == '0' || tmp == '1' || tmp == '4' || tmp == '5' || tmp == '8' || tmp == '9' || tmp == 'C' || tmp == 'D')){
					if (!entryFound) {
						x1 = i;
						y1 = j;
						entryFound = false;
					} else {
						x2 = i;
						y2 = j;
					}
					direction = 4; //up;
				}
				input[i][j] = tmp;
			}
		}

		cout << x1 << "," << y1 << "::" << x2 << "," << y2 << endl;

	}
	return 0;
}
