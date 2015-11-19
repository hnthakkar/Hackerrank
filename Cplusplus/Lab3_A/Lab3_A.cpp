#include <iostream>
using namespace std;

struct Queue {
	int front, rear, size;
	int capacity;
	int* array;
};

struct Queue* createQueue(int capacity) {
	struct Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = new int[capacity];
	return queue;
}

int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
	if (isEmpty(queue))
		return -1;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int front(struct Queue* queue) {
	if (isEmpty(queue))
		return -1;
	return queue->array[queue->front];
}

int rear(struct Queue* queue) {
	if (isEmpty(queue))
		return -1;
	return queue->array[queue->rear];
}

bool checkIfInQ(struct Queue* queue, int elem) {
	bool match = false;
	for(int i = queue->front; i <= queue->rear; i++){
		if(queue->array[i%queue->capacity] == elem){
			match = true;
			break;
		}
	}
	return match;
}



int main() {
	int T;
	cin >> T;
	int t = 1;
	for(; t <=T; t++) {
		int N, M;
		cin >> N >> M;
		struct Queue* main = createQueue(N);
		for (int i = 0; i < N; i++) {
			enqueue(main, i);
		}

		int** visited = new int*[N];
		for (int j = 0; j < N; j++) {
			visited[j] = new int[M];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}

		int FW[M];
		for (int i = 0; i < M; i++){
			FW[i] = -1;
		}

		int counter = 0;
		int bottomSeat = 0;
		int rideCount = N*M;
		while (true) {
			if (FW[bottomSeat] != -1){
				enqueue(main, FW[bottomSeat]);
				FW[bottomSeat] = -1;
				rideCount--;
				if(rideCount == 0){
					break;
				}
			}
			int rotateCount = main->size;
			int item = -1;
			bool done = false;
			while (rotateCount--) {
				item = dequeue(main);
				if(!done && visited[item][bottomSeat] == 0){
					FW[bottomSeat] = item;
					visited[item][bottomSeat] = 1;
					done = true;
					continue;
				}
				enqueue(main, item);
			}
			bottomSeat = (bottomSeat+1) % M;
			counter += 5;
		}
		cout << "Case " << t << ": " << (counter+5) << endl;
	}
	return 0;
}
