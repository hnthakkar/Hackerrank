#include <iostream>
#include <string.h>
#define size 100000
using namespace std;

struct stack {
	char s[size];
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

void push(char item){
	if(isFull() == 0){
		stack.top++;
		stack.s[stack.top] = item;
	}
}

char pop(){
	char ret = '0';
	if(isEmpty() == 0){
		ret = stack.s[stack.top];
		stack.top--;
	}
	return ret;
}


int main(){
	int T;
	cin >> T;
	while(T--){
		bool match = true;
		string input;
		cin >> input;
		stack.top = -1;
		int len = input.length();
		for (int i = 0; i < len; i++){
			char ch = input.at(i);
			if(ch == '[' || ch == '{' || ch == '('){
				if(isFull() == 1){
					match = false;
					break;
				}
				push(ch);
			} else {
				char expected;
				if(ch == ')'){
					expected = '(';
				} else if (ch == '}'){
					expected = '{';
				} else {
					expected = '[';
				}

				if(isEmpty() == 1){
					match = false;
					break;
				}
				char popElem = pop();
				if(popElem != expected){
					match = false;
					break;
				}
			}

		}
		if(isEmpty() == 0)
			match = false;

		if(match){
			cout << "True" << endl;
		} else {
			cout << "False" << endl;
		}
	}
	return 0;
}
