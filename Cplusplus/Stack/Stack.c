#include <stdio.h>
#define size 10

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

void displayAll(){
	int index = 0;
	while((stack.top - index) != -1){
		printf("%d\n", stack.s[stack.top - index]);
		index++;
	}
}

int main(){
	stack.top = -1;
	displayAll();
	push(3);
	push(4);
	push(10);
	displayAll();
	pop();
	displayAll();
	pop();
	displayAll();
	pop();
	displayAll();
	return 0;
}
