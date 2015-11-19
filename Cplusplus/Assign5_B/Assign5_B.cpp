#include <iostream>
using namespace std;

int longestPath(char **input, int HStart, int WStart, int prevValue, int H, int W, int **mem) {
	if (HStart < 0 || WStart < 0 || HStart >= H || WStart >= W)
		return 0;
	if ((int)input[HStart][WStart] - prevValue != 1)
		return 0;

	if (mem[HStart][WStart] != -1)
		return mem[HStart][WStart];

	int retValue = 0;

	retValue = max(retValue, longestPath(input,HStart - 1, WStart -1 , prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart - 1, WStart, prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart - 1, WStart + 1 , prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart, WStart + 1 , prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart + 1, WStart + 1, prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart + 1, WStart, prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart + 1, WStart -1 , prevValue + 1, H, W, mem) + 1);
	retValue = max(retValue, longestPath(input, HStart, WStart -1 , prevValue + 1, H, W, mem) + 1);

	mem[HStart][WStart] = retValue;
	return retValue;
}

int main(){
	int **mem;
	char **input;

	input = new char *[1000];
	for (int i = 0; i < 1000; i++){
		input[i] = new char[1000];
	}

	mem = new int *[1000];
	for (int i = 0; i < 1000; i++){
		mem[i] = new int[1000];
		for (int j = 0; j < 1000; j++){
			mem[i][j] = -1;
		}
	}


	while(true){
		int H, W;
		cin >> H >> W;
		if (H == 0 && W == 0){
			break;
		}

		for (int i = 0; i < H; i++){
			cin >> input[i];
		}

		int globalMax = 0;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++) {
				if ((int)input[i][j] == 65){
					globalMax = max(globalMax, longestPath(input, i - 1, j -1 , 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i - 1, j, 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i - 1, j + 1 , 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i, j + 1 , 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i + 1, j + 1, 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i + 1, j, 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i + 1, j -1 , 65, H, W, mem) + 1);
					globalMax = max(globalMax, longestPath(input, i, j -1 , 65, H, W, mem) + 1);
				}
			}
		}

		cout << globalMax << endl;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				mem[i][j] = -1;
			}
		}
	}
	return 0;
}
