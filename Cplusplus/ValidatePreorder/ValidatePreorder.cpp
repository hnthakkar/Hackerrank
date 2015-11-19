#include <bits/stdc++.h>
#define size 1001
using namespace std;

struct myStack {
	int s[size];
	int top;
} myStack;

bool isFull(){
	if(myStack.top > size -1){
		return true;
	} else {
		return false;
	}
}

bool isEmpty(){
	if(myStack.top > -1){
		return false;
	}
	return true;
}

void push(int item){
	if(!isFull()){
		myStack.top++;
		myStack.s[myStack.top] = item;
	}
}

int pop(){
	int ret = -1;
	if(!isEmpty()){
		ret = myStack.s[myStack.top];
		myStack.top--;
	}
	return ret;
}

int top(){
	int ret = -1;
	if(!isEmpty()){
		ret = myStack.s[myStack.top];
	}
	return ret;
}

bool validatePreorder(int a[], int length) {
	push(a[0]);
	int lastPopValue = -1;
	for (int i = 1; i < length; i++) {
		int curValue = a[i];
		int topValue = top();
		if (curValue < topValue) {
			if(curValue <= lastPopValue)
				return false;
		} else if(curValue > topValue){
			while (!isEmpty() && curValue >= top()) {
				if(curValue == top())
					return false;
				lastPopValue = pop();

			}
		}
		push(curValue);
	}
	return true;
}

int main() {
	int T = 1;
	char ch = 0;
	while (cin >> ch) {
		cin.unget();
		myStack.top = -1;
		int inputs[1000] = {};
		int num = 0;
		cin >> num;
		int index = 0;
		while(num > 0){
			inputs[index++] = num;
			cin >> num;
		}
		if(validatePreorder(inputs, index)){
			cout << "Case " << T << ": yes" << endl;
		} else {
			cout << "Case " << T << ": no" << endl;
		}
		T++;
	}
	return 0;
}

