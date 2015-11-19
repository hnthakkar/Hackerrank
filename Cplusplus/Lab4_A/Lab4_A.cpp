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

void printLL(struct node *head) {
	if (head == NULL) {
		return;
	} else {
		cout << head->elem << endl;
		printLL(head->next);
	}
}

struct node * deleteNode(struct node *head, int elem) {
	if (head == NULL)
		return head;
	struct node *cur, *prev;
	cur = head;
	prev = head;
	while (cur->elem != elem) {
		if (cur->next == NULL)
			break;
		prev = cur;
		cur = cur->next;

	}
	if (cur->elem == elem) {
		struct node *tmp;
		tmp = cur;
		if (prev == cur) {
			head = head->next;
		} else {
			prev->next = cur->next;
		}
		free(tmp);
	}
	return head;
}

//assuming head position is zero
struct node * insertAtPosition(struct node * head, int elem, int loc) {
	struct node *prev, *cur;
	int position = 0;
	prev = head;
	cur = head;
	while (position < loc) {
		prev = cur;
		cur = cur->next;
		position++;
		if (cur == NULL)
			break;
	}

	if (position == loc) {
		if (prev == cur) { //adding at head
			struct node *tmp;
			tmp = new node();
			tmp->elem = elem;
			tmp->next = head;
			head = tmp;
		} else {
			struct node *tmp;
			tmp = new node();
			tmp->elem = elem;
			tmp->next = prev->next;
			prev->next = tmp;
		}
	}
	return head;
}

struct node * reverseLL(struct node * head) {
	struct node *prev = NULL, *next;
	while (head) {
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}

//slow and fast pointer
int checkCycle(struct node * head) {
	struct node *slow, *fast;
	slow = head;
	fast = head;
	while (true) {
		slow = slow->next;
		if (!fast->next) {
			fast = fast->next->next;
		} else {
			break;
		}
		if (slow == fast)
			return 1;

	}
	return 0;
}

int main() {
	struct node *head = NULL;
	head = insert(head, 1);
	printLL(head);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	printLL(head);
	head = deleteNode(head, 1);
	head = reverseLL(head);
	printLL(head);
	if(checkCycle(head) == 0){
		cout << "No Cycle" << endl;
	} else {
		cout << "Has a cycle" << endl;
	}
	return 0;
}
