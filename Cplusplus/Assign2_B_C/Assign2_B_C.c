#include <stdio.h>

int checkNAdd(long long int factor[], long long int num){
	int ret = 0;
	int found = 0;
	int index = 0;
	while(factor[index] != 0 && factor[index] <= num){
		if(factor[index] == num){
			found = 1;
			break;
		}
		index++;
	}
	if(found == 0){
		ret = 1;
		long long int tmp = factor[index];
		factor[index++] = num;
		long long int tmp2 = 0;
		while(tmp != 0){
			tmp2 = factor[index];
			factor[index] = tmp;
			tmp = tmp2;
		}
	}
	return ret;
}

int main() {
	int primeCheck = 1001;
	int prime[999990] = { };

	prime[0] = 1;
	prime[1] = 1;
	int start = 0;
	int i = 2;
	while (i < primeCheck) {
		if (prime[i] == 0) {
			start = i + i;
			while (start < 999990) {
				prime[start] = 1;
				start += i;
			}
		}
		i++;
	}

	int T;
	scanf("%d", &T);

	int t = 1;
	for (; t <= T; t++) {
		int N;
		scanf("%d", &N);

		long long int input[N];
		long long int MAX = 0;
		int j = 0;
		for (; j < N; j++) {
			scanf("%Ld", &input[j]);
			if(MAX < input[j])
				MAX = input[j];
		}

		int MAXLoop = 1;
		if (MAX > 999990) {
			MAXLoop = 999989;
		} else {
			while (MAXLoop * MAXLoop <= MAX) {
				MAXLoop++;
			}
		}

		long long int primeFactor[25] = {};

		int M = 0;
		int i = 0;
		for(; i < N; i++){
			if (input[i] <= 1)
				continue;
			if (input[i] < 999990 && prime[input[i]] == 0) {
				if(checkNAdd(primeFactor, input[i]) == 1)
					M++;
				continue;
			}
			int curPrimeIndex = 2;
			int divisor = curPrimeIndex++;

			while(divisor <= MAXLoop){
				if ((input[i] % divisor == 0)) {
					if(checkNAdd(primeFactor, divisor) == 1)
						M++;
					while (input[i] % divisor == 0) {
						input[i] /= divisor;
					}
				}
				if(input[i] <= 1)
					break;
				if(input[i] < 999990 && prime[input[i]] == 0){
					if(checkNAdd(primeFactor, input[i]) == 1)
						M++;
					input[i] = 1;
					break;
				}
				while (curPrimeIndex - 1 <= MAXLoop) {
					if (prime[curPrimeIndex] == 1) {
						curPrimeIndex++;
						continue;
					}
					divisor = curPrimeIndex++;
					break;
				}
			}
			if(input[i] != 1){
				if(checkNAdd(primeFactor, input[i]) == 1)
					M++;
			}

		}
		printf("Case #%d: %d\n", t, M);
		int k = 0;
		for (; k < M; k++) {
			printf("%Ld\n", primeFactor[k]);
		}
		printf("\n");
	}
	return 0;
}
