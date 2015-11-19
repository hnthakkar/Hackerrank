#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
};

static int preIndex = 0;
struct node * buildTree(int pre[], int inStrt, int inEnd) {
	if (inStrt > inEnd)
		return NULL;

	struct node *ret = (struct node *)malloc(sizeof(struct node));
	ret->value = pre[preIndex++];
	ret->left = NULL;
	ret->right = NULL;

	if (inStrt == inEnd)
		return ret;
	int i = ret->value -1;

	ret->left = buildTree(pre, inStrt, i - 1);
	ret->right = buildTree(pre, i + 1, inEnd);
	return ret;
}

void printPostorder(struct node* node) {
	if (node == NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d\n", node->value);
}

static int inOrderRef = 0;
static int isCorrect = 1;
void checkInorder(struct node* node) {
	if (node == NULL)
		return;

	checkInorder(node->left);
	if (!isCorrect || node->value != inOrderRef + 1) {
		isCorrect = 0;
		return;
	}
	inOrderRef++;
	checkInorder(node->right);
}

int main() {
	int T;
	scanf("%d", &T);
	int t = 1;
	for (; t <= T; t++) {
		int N;
		scanf("%d", &N);
		int pre[N];
		int j = 0;
		for (; j < N; j++) {
			scanf("%d", &pre[j]);
		}
		inOrderRef = 0;
		preIndex = 0;
		isCorrect = 1;
		struct node * root = buildTree(pre, 0, N - 1);
		checkInorder(root);
		if (isCorrect == 0) {
			printf("Case %d:\n", t);
			printf("%d\n", -1);
		} else {
			printf("Case %d:\n", t);
			printPostorder(root);
		}
	}
	return 0;
}

