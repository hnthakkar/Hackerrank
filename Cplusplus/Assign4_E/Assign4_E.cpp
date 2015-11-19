#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

int max(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

static int preIndex = 0;
struct node * buildTree(int pre[], int in[], int inStrt, int inEnd) {
	struct node * ret;
	if (inStrt > inEnd)
		return NULL;
	ret = new node();
	ret->value = pre[preIndex++];
	ret->left = NULL;
	ret->right = NULL;
	if (inStrt == inEnd)
		return ret;
	int i = inStrt;
	for (; i <= inEnd; i++) {
		if (in[i] == pre[preIndex - 1]) {
			break;
		}
	}
	ret->left = buildTree(pre, in, inStrt, i - 1);
	ret->right = buildTree(pre, in, i + 1, inEnd);
	return ret;
}

int height(struct node * root){
	if(root == NULL)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}

int diameter(struct node * root){
	if(root == NULL)
		return 0;
	int dia = 0;
	int lheight = height(root->left);
	int rheight = height(root->right);
	int ldia = diameter(root->left);
	int rdia = diameter(root->right);
	dia = max(max(ldia, rdia), (lheight+rheight+1));
	return dia;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int in[N];
		for (int i = 0; i < N; i++) {
			cin >> in[i];
		}
		int pre[N];
		for (int i = 0; i < N; i++) {
			cin >> pre[i];
		}
		preIndex = 0;
		struct node *root = buildTree(pre, in, 0, N - 1);
		int dia = diameter(root);
		cout << (dia-1) << endl;
	}
	return 0;
}
