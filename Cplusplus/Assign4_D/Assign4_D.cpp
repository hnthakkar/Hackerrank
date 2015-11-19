#include <iostream>
#define size 100000
using namespace std;

struct stack {
	int s[size];
	int top;
} stack;

int isFull(){
	if(stack.top > size -1){
		return 1;
	} else {
		return 0;
	}
}

int isEmpty(){
	if(stack.top > -1){
		return 0;
	} else {
		return 1;
	}
}

void push(int item){
	if(isFull() == 0){
		stack.top++;
		stack.s[stack.top] = item;
	}
}

int pop(){
	int ret = -1;
	if(isEmpty() == 0){
		ret = stack.s[stack.top];
		stack.top--;
	}
	return ret;
}

int top(){
	int ret = -1;
	if(isEmpty() == 0){
		ret = stack.s[stack.top];
	}
	return ret;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		stack.top = -1;
		int N;
		cin >> N;
		int output[N];
		for (int i = 0; i < N; i++){
			cin >> output[i];
		}
		bool possible = true;
		int outputIndex = 0;
		for (int i = 1; i <= N; i++){
			push(i);
			int topElem = top();
			bool allDone = false;
			while(topElem == output[outputIndex]){
				pop();
				outputIndex++;
				if(outputIndex >= N){
					allDone = true;
					break;
				}
				topElem = top();
			}
			if(allDone){
				break;
			}
			if(topElem == -1)
				continue;
			if(topElem > output[outputIndex]){
				possible = false;
				break;
			}
		}
		if(possible){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
