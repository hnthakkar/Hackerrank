#include <iostream>
using namespace std;

static int preIndex = 0;
int buildTree(string input) {
	char ch = input.at(preIndex);
	if(ch == 'l')
		return 0;

	int height = 0;
	preIndex++;
	int lHeight = buildTree(input) + 1;
	preIndex++;
	int rHeight = buildTree(input) + 1;
	if(lHeight > rHeight){
		height = lHeight;
	} else {
		height = rHeight ;
	}
	return height;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		preIndex = 0;
		string input;
		cin >> input;
		cout << buildTree(input) << endl;
	}
	return 0;
}
