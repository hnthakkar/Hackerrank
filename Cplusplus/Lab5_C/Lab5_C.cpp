#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

struct node * buildBinaryTree(struct node * head, int num){
	struct node * tmp = new node();
	tmp->value = num;
	tmp->left = NULL;
	tmp->right = NULL;
	struct node * pointer = head;
	struct node * lastpointer = head;
	while(true){
		if(tmp->value > pointer->value){
			lastpointer = pointer;
			pointer = pointer->right;
		} else {
			lastpointer = pointer;
			pointer = pointer->left;
		}
		if(pointer == NULL){
			break;
		}
	}
	if (num > lastpointer->value) {
		lastpointer->right = tmp;
	} else {
		lastpointer->left = tmp;
	}
	return head;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		int input[N];
		for (int i = 0; i < N; i++){
			cin >> input[i];
		}
		int P[K];
		int Q[K];
		for (int i = 0; i < K; i++){
			cin >> P[i] >> Q[i];
		}
		struct node * head = new node();
		head->value = input[0];
		head->left = NULL;
		head->right = NULL;
		for(int i = 1; i < N; i++){
			head = buildBinaryTree(head,input[i]);
		}

		for (int i = 0; i < K; i++){
			struct node * pointer = head;
			while(true){
				if (P[i] < pointer->value && Q[i] < pointer->value){
					pointer = pointer->left;
				} else if(P[i] > pointer->value && Q[i] > pointer->value) {
					pointer = pointer->right;
				} else {
					break;
				}
			}
			cout << pointer->value << endl;
		}
	}
	return 0;
}
