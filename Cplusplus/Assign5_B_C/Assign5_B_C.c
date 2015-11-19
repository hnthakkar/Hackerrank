#include <stdio.h>

int getMax(int a, int b){
	if(a > b)
		return a;
	return b;
}

int longestPath(int HStart, int WStart, int prevValue, int H, int W, int (*mem)[W], char (*input)[W]) {
	if (HStart < 0 || WStart < 0 || HStart >= H || WStart >= W)
		return 0;
	if ((int)input[HStart][WStart] - prevValue != 1)
		return 0;

	if (mem[HStart][WStart] != -1)
		return mem[HStart][WStart];

	int retValue = 0;

	retValue = getMax(retValue, longestPath(HStart - 1, WStart -1 , prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart - 1, WStart, prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart - 1, WStart + 1 , prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart, WStart + 1 , prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart + 1, WStart + 1, prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart + 1, WStart, prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart + 1, WStart -1 , prevValue + 1, H, W, mem, input) + 1);
	retValue = getMax(retValue, longestPath(HStart, WStart -1 , prevValue + 1, H, W, mem, input) + 1);

	mem[HStart][WStart] = retValue;
	return retValue;
}

int main(){
	while(1){
		int H, W;
		scanf("%d", &H);
		scanf("%d", &W);
		if (H == 0 && W == 0){
			break;
		}
		int mem[H][W];
		char input[H][W];

		getchar();
		int i = 0, j = 0;
		for (; i < H; i++){
			j = 0;
			for (; j < W; j++) {
				scanf("%c", &input[i][j]);
			}
		}

		int x = 0, y = 0;
		for (; x < H; x++){
			y = 0;
			for (; y < W; y++){
				mem[x][y] = -1;
			}
		}

		int globalMax = 0;
		i =0, j = 0;
		for (; i < H; i++){
			j = 0;
			for (; j < W; j++) {
				if ((int)input[i][j] == 65){
					globalMax = getMax(globalMax, longestPath(i - 1, j -1 , 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i - 1, j, 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i - 1, j + 1 , 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i, j + 1 , 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i + 1, j + 1, 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i + 1, j, 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i + 1, j -1 , 65, H, W, mem, input) + 1);
					globalMax = getMax(globalMax, longestPath(i, j -1 , 65, H, W, mem, input) + 1);
				}
			}
		}
		printf("%d\n", globalMax);
	}
	return 0;
}
