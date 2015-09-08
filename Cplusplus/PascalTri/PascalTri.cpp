#include <iostream>
using namespace std;

int main() {
	int row;
	cin >> row;
	int elems[row][row];
	int space = row/2;
	for (int line = 0; line < row; line++){
		for (int lineElem = 0; lineElem <= line; lineElem++){
			if(lineElem == 0){
				for (int s = 0; s < space; s++){
					cout << " ";
				}
				space--;
			}
			if(lineElem == 0 || lineElem == line){
				elems[line][lineElem] = 1;
				cout << 1;
			} else {
				elems [line][lineElem] = elems[line - 1][lineElem] + elems[line - 1][lineElem -1];
				cout << elems [line][lineElem];
			}
		}
		cout << endl;
	}
	return 0;
}
