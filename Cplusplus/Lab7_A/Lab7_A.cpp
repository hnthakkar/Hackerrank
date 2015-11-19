#include <bits/stdc++.h>
using namespace std;

int getMinIndex(long int arr[], int N) {
	int minInd = 0;
	for (int i = 1; i < N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

int getMaxIndex(long int arr[], int N) {
	int maxInd = 0;
	for (int i = 1; i < N; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

int min(long int a, long int b) {
	if (a < b) {
		return a;
	}
	return b;
}

void startTransactions(long int amount[], int N) {
	int mxCredit = getMaxIndex(amount, N);
	int mxDebit = getMinIndex(amount, N);

	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	int low = min(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= low;
	amount[mxDebit] += low;

	cout << mxDebit << " " << mxCredit << " " << low << endl;
	startTransactions(amount, N);
}

bool getTransactions(long int **transactions, int N) {
	bool hasTransactions = false;
	long int balance[N];
	for (int i = 0; i < N; i++){
		balance[i] = 0;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			balance[i] += (transactions[j][i] - transactions[i][j]);
			if (balance[i] != 0)
				hasTransactions = true;
		}
	}
	if (hasTransactions)
		startTransactions(balance, N);
	return hasTransactions;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N = 0;
		cin >> N;
		long int ** transactions;
		transactions = new long int *[N];
		for (int i = 0; i < N; i++)
			transactions[i] = new long int[N];

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				transactions[i][j] = 0;
			}
		}

		long int input = 0, x = 0, y = 0;
		string tmpStr;
		while (getline(cin, tmpStr)) {
			istringstream iss(tmpStr);
			if (tmpStr.length() == 1)
				break;
			iss >> x;
			iss >> y;
			iss >> input;
			transactions[x][y] = input;
		}

		cout << "Case " << t << ":" << endl;
		if (!getTransactions(transactions, N))
			cout << "-1" << endl;

		for (int i = 0; i < N; i++){
			delete[] transactions[i];
		}
		delete[] transactions;
	}
	return 0;
}
