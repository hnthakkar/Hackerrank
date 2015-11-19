#include <bits/stdc++.h>
using namespace std;

struct Node {
	struct Node *child[10];
	int is_end_of_string;
};

struct Trie {
	struct Node *root;
	int count;
};

struct Node *createarray() {
	struct Node *temp = NULL;
	temp = new Node();
	temp->child[0] = NULL;
	temp->is_end_of_string = 0;
	for (int i = 1; i < 10; i++) {
		temp->child[i] = NULL;
	}
	return temp;
}

int insert(struct Trie *temp, char key[]) {
	if (!temp)
		return -1;
	int level, index, length, count = 0, i, flag = 0;
	struct Node *temp2;
	temp2 = temp->root;
	temp->count++;

	length = strlen(key);

	for (level = 0; level < length; level++) {
		index = key[level] - 48;
		if (temp2->child[index]) {
			if (temp2->is_end_of_string == 1)
				count++;
		} else if (!temp2->child[index]) {
			temp2->child[index] = createarray();
			if (temp2->is_end_of_string == 1)
				count++;
			flag = 1;
		}
		temp2 = temp2->child[index];
	}
	for (i = 0; i < 10; i++) {
		if ((temp2->child[i]) != NULL)
			return 2;
	}
	if (flag == 0)
		return 2;
	temp2->is_end_of_string = 1;
	count++;
	return count;
}

void deleteTrie (struct Node *temp2){
	int i;
	for(i=0; i<10; i++)
	{
		if((temp2->child[i])!=NULL)
		delete(temp2->child[i]);
	}
	free(temp2);
}

int main() {
	int i, x, t, count, flag = 0;
	char matrix[11];
	long long int n;
	scanf("%d", &t);
	struct Trie trie;
	for (x = 0; x < t; x++) {
		trie.root = createarray();
		trie.count = 0;
		flag = 0;
		scanf("%Ld", &n);
		if (n == 0) {
			continue;
		}
		for (i = 0; i < n; i++) {
			scanf("%s", matrix);
			count = insert(&trie, matrix);
			if (count > 1) {
				flag = 1;
			}
		}
		if (flag == 0)
			printf("YES\n");
		else if (flag == 1)
			printf("NO\n");
		struct Node *temp2;
		temp2 = trie.root;
		deleteTrie (temp2);
		trie.root = NULL;
	}

	return 0;
}
