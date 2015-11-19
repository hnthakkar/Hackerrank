#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
	int height;
};

struct node * newNode(int value) {
	struct node * retNode = new node();
	retNode->height = 1;
	retNode->value = value;
	retNode->left = NULL;
	retNode->right = NULL;
	return retNode;
}

int max(int num1, int num2) {
	if (num1 > num2)
		return num1;
	return num2;
}

int height(struct node * node){
	if (node == NULL)
		return 0;
	return node->height;
}

struct node * rightRotate(struct node *item) {
	struct node *itemLeft = item->left;
	struct node *itemLeftRight = itemLeft->right;

	itemLeft->right = item;
	item->left = itemLeftRight;

	item->height = max(height(item->left), height(item->right)) + 1;
	itemLeft->height = max(height(itemLeft->left), height(itemLeft->right)) + 1;

	return itemLeft;
}

struct node *leftRotate(struct node *item) {
	struct node *itemRight = item->right;
	struct node *itemRightLeft = itemRight->left;

	itemRight->left = item;
	item->right = itemRightLeft;

	item->height = max(height(item->left), height(item->right)) + 1;
	itemRight->height = max(height(itemRight->left), height(itemRight->right)) + 1;

	return itemRight;
}

struct node * minValueNode(struct node* node) {
	struct node* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

bool wasDeleted = true;
struct node * deleteItem(struct node * root, int item) {
	if (root == NULL){
		wasDeleted = false;
		return root;
	}
	if (root->value < item) {
		root->right = deleteItem(root->right, item);
	} else if (root->value > item) {
		root->left = deleteItem(root->left, item);
	} else {
		struct node * tmp = NULL;
		if (root->left == NULL && root->right == NULL) {
			tmp = root;
			root = NULL;
			free(tmp);
			return root;
		} else if (root->left == NULL || root->right == NULL) {
			tmp = root;
			if (root->left) {
				root = root->left;
			} else {
				root = root->right;
			}
			free(tmp);
		} else {
			tmp = minValueNode(root->right);
			root->value = tmp->value;
			root->right = deleteItem(root->right, tmp->value);
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	int balanceFactor = height(root->left) - height(root->right);

	//Single Right Rotation (LL)
	if (balanceFactor > 1 && root->left->value > item) {
		return rightRotate(root);
	}

	//Single Left Rotation (RR)
	if (balanceFactor < -1 && root->right->value < item) {
		return leftRotate(root);
	}

	//Double Rotation (LR)
	if (balanceFactor > 1 && root->left->value < item) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//Double Rotation (RL)
	if (balanceFactor < -1 && root->right->value > item) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

bool wasInserted = false;
struct node * insert(struct node * root, int item) {
	if (root == NULL){
		wasInserted = true;
		return newNode(item);
	}
	if (root->value > item) {
		root->left = insert(root->left, item);
	} else if (root->value < item) {
		root->right = insert(root->right, item);
	} else {
		return root;
	}

	root->height = max(height(root->left), height(root->right)) + 1;

	int balanceFactor = height(root->left) - height(root->right);

	//Single Right Rotation (LL)
	if (balanceFactor > 1 && root->left->value > item) {
		return rightRotate(root);
	}

	//Single Left Rotation (RR)
	if (balanceFactor < -1 && root->right->value < item) {
		return leftRotate(root);
	}

	//Double Rotation (LR)
	if (balanceFactor > 1 && root->left->value < item) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//Double Rotation (RL)
	if (balanceFactor < -1 && root->right->value > item) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

int findAndPrintHeight(struct node * root, int item){
	if (root == NULL){
		//cout << "Node Not Found" << endl;
		//cout << -1 << endl;
		return -1;
	}
	if (root->value > item) {
		return findAndPrintHeight(root->left, item);
	} else if (root->value < item) {
		return findAndPrintHeight(root->right, item);
	}
		//cout << height(root) <<  endl;
	return height(root);
}

/*void preOrder(struct node *root) {
	if (root == NULL)
		return;
	cout << root->value << endl;
	preOrder(root->left);
	preOrder(root->right);
}*/

int main() {
	int N;
	cin >> N;
	struct node * root = NULL;
	while (N--) {
		char operation;
		cin >> operation;
		int item;
		cin >> item;
		if (operation == 'I') {
			wasInserted = false;
			root = insert(root, item);
			if (wasInserted){
				cout << "true" << endl;
			} else {
				cout << "false" << endl;
			}
			/*cout << "======" << endl;
			preOrder(root);
			cout << "======" << endl;*/
		} else if (operation == 'D'){
			wasDeleted = false;
			root = deleteItem(root, item);
			if (wasDeleted) {
				cout << "true" << endl;
			} else {
				cout << "false" << endl;
			}
		} else if(operation == 'H'){
			cout << height(root) - findAndPrintHeight(root, item) << endl;
		}
	}
	//preOrder(root);
	return 0;
}
