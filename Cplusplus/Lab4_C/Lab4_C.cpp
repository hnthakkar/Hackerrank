#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int elem;
	struct node *next;

};

struct node * insert(struct node *head, int elem) {
	if (head == NULL) {
		head = new node();
		head->next = NULL;
		head->elem = elem;
	} else {
		struct node *lastNode;
		lastNode = head;
		while (lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = new node();
		lastNode = lastNode->next;
		lastNode->elem = elem;
		lastNode->next = NULL;
	}
	return head;
}

struct node * insertNode(struct node *head, struct node *Node){
	struct node *l1_lastNode;
	l1_lastNode = head;
	while (l1_lastNode->next != NULL) {
		l1_lastNode = l1_lastNode->next;
	}
	l1_lastNode->next = Node;
	l1_lastNode = l1_lastNode->next;
	l1_lastNode->next = NULL;
	return head;
}

void printLL(struct node *head) {
	if (head == NULL) {
		return;
	} else {
		cout << head->elem << endl;
		printLL(head->next);
	}
}


struct node * mergepoint(struct node *l1, struct node *l2) {
	struct node *tl1 = l1, *tl2 = l2;
	int flag = 0;
	while (tl1 != NULL) {
		tl2 = l2;
		while (tl2 != NULL) {
			cout << tl2->elem << "==" << tl1->elem << endl;
			if (tl2 == tl1) {
				flag = 1;
				break;
			}
			if(tl2->next == NULL)
				break;
			tl2 = tl2->next;
		}
		if (flag == 1)
			break;
		tl1 = tl1->next;
	}
	return tl1;
}

int main() {
	struct node *l1_ret, *l2_ret;
	struct node *l1_head = NULL;
	struct node *l2_head = NULL;
	l1_ret = insert(l1_head, 1);
	l1_ret = insert(l1_ret, 4);
	l1_ret = insert(l1_ret, 6);
	//printLL(l1_ret);
	l2_ret = insert(l2_head, 2);
	l2_ret = insert(l2_ret, 3);
	l2_ret = insert(l2_ret, 5);
	//printLL(l2_ret);
	struct node *tmp = new node();
	tmp->elem = 7;
	tmp->next = NULL;
	l1_ret = insertNode(l1_ret, tmp);
	l2_ret = insertNode(l2_ret, tmp);
	struct node *tmp2 = new node();
	tmp2->elem = 8;
	tmp2->next = NULL;
	l1_ret = insertNode(l1_ret, tmp2);
	l2_ret = insertNode(l2_ret, tmp2);
	printLL(l1_ret);
	printLL(l2_ret);
	struct node *point = mergepoint(l1_ret, l2_ret);
	cout << point->elem << endl;
	return 0;
}
