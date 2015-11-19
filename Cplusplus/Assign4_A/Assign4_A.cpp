#include <iostream>
using namespace std;

struct customer {
	long int arrival;
	long int timeToCook;
	struct customer *next;
};

struct customer * addToLine(struct customer *cusHead, struct customer *newCus) {
	if (cusHead == NULL)
		return newCus;
	struct customer * curNode = cusHead;
	struct customer * lastNode = cusHead;
	while (curNode && curNode->timeToCook < newCus->timeToCook) {
		lastNode = curNode;
		curNode = curNode->next;
		continue;
	}
	if (curNode == NULL) {
		curNode = lastNode;
		curNode->next = newCus;
	} else{
		struct customer * next = lastNode->next;
		lastNode->next = newCus;
		newCus->next = next;
	}
	return cusHead;
}

int main() {
	int C;
	cin >> C;
	struct customer * cusArray[C];
	for (int i = 0; i < C; i++) {
		struct customer *cus = new customer();
		cin >> cus->arrival;
		cin >> cus->timeToCook;
		cus->next = NULL;
		cusArray[i] = cus;
	}

	long long int time = cusArray[0]->arrival;
	struct customer *cusOrder;
	cusOrder = cusArray[0];
	int index = 1;
	struct customer *next = cusArray[index];
	long int waitTime = 0;
	while (true) {
		while (index < C && next->arrival <= time) {
			cusOrder = addToLine(cusOrder, next);
			index++;
			if (index >= C)
				break;
			next = cusArray[index];
		}
		if(cusOrder == NULL)
			break;
		time += cusOrder->timeToCook;
		waitTime += time - cusOrder->arrival;
		cusOrder = cusOrder->next;
	}
	int meanWaitTime = waitTime / C;
	cout << meanWaitTime << endl;
	return 0;
}
