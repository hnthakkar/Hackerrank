#include <iostream>
#define size 100001
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

struct stack {
	struct node * s[size];
	int top;
} stack;

bool isFull(){
	if(stack.top > size -1){
		return true;
	} else {
		return false;
	}
}

bool isEmpty(){
	if(stack.top > -1){
		return false;
	}
	return true;
}

void push(struct node *item){
	if(!isFull()){
		stack.top++;
		stack.s[stack.top] = item;
	}
}

struct node * pop(){
	struct node *ret = NULL;
	if(!isEmpty()){
		ret = stack.s[stack.top];
		stack.top--;
	}
	return ret;
}

struct node * top(){
	struct node *ret = NULL;
	if(!isEmpty()){
		ret = stack.s[stack.top];
	}
	return ret;
}

node* preorderToTree(int a[], int length) {
	if (length == 0)
		return NULL;
	node* root = new node();
	root->value = a[0];
	push(root);
	int lastPopValue = -1;
	for (int i = 1; i < length; i++) {
		node* tmp = new node();
		tmp->value = a[i];
		node* topNode = top();
		if (tmp->value < topNode->value) {
			if(tmp->value < lastPopValue)
				return NULL;
			topNode->left = tmp;
		} else {
			node* popped = NULL;
			while (!isEmpty() && tmp->value > top()->value) {
				popped = top();
				pop();
			}
			popped->right = tmp;
			lastPopValue = popped->value;
		}
		push(tmp);
	}
	return root;
}

void printPostorder(struct node* node) {
	if (node == NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->value << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		int pre[N];
		for (int i = 0; i < N; i++) {
			cin >> pre[i];
		}
		stack.top = -1;
		struct node * root = preorderToTree(pre, N);
		if (root == NULL) {
			cout << "Case " << t << ":" << endl;
			cout << -1 << endl;
		} else {
			cout << "Case " << t << ":" << endl;
			printPostorder(root);
		}
	}
	return 0;
}

