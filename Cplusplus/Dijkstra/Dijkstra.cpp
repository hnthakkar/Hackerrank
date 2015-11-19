#include <bits/stdc++.h>
using namespace std;

struct Node {
	int dest;
	int weight;
	struct Node* next;
};

struct AdjList {
	struct Node *head;
};

struct Graph {
	int noOfVertices;
	struct AdjList* array;
};

struct Node* getNewNode(int dest, int weight) {
	struct Node* newNode = new Node();
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int noOfNodes) {
	struct Graph* graph = new Graph();
	graph->noOfVertices = noOfNodes;

	graph->array = new AdjList[noOfNodes];

	for (int i = 0; i < noOfNodes; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
	struct Node* newNode = getNewNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = getNewNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

struct MinHeapNode {
	int v;
	int dist;
};

struct MinHeap {
	int size;
	int capacity;
	int *pos;
	struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v, int dist) {
	struct MinHeapNode* minHeapNode = new MinHeapNode;
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity) {
	struct MinHeap* minHeap = new MinHeap();
	minHeap->pos = (int *) malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));;
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
		smallest = right;

	if (smallest != idx) {
		MinHeapNode *smallestNode = minHeap->array[smallest];
		MinHeapNode *idxNode = minHeap->array[idx];

		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap) {
	return minHeap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	if (isEmpty(minHeap))
		return NULL;

	struct MinHeapNode* root = minHeap->array[0];

	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
	int i = minHeap->pos[v];

	minHeap->array[i]->dist = dist;

	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}

bool isInMinHeap(struct MinHeap *minHeap, int v) {
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

void dijkstra(struct Graph* graph, int src) {
	int V = graph->noOfVertices;
	int dist[V];

	struct MinHeap* minHeap = createMinHeap(V);

	for (int v = 0; v < V; ++v) {
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	minHeap->size = V;

	while (!isEmpty(minHeap)) {
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v;

		struct Node* pCrawl = graph->array[u].head;
		while (pCrawl != NULL) {
			int v = pCrawl->dest;

			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]) {
				dist[v] = dist[u] + pCrawl->weight;

				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	for (int i = 0; i < graph->noOfVertices; i++){
		if (i == src)
			continue;
		if (dist[i] == INT_MAX){
			cout << "-1" << " ";
		} else {
			cout << dist[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		int V = 0;
		int E = 0;
		cin >> V >> E;
		struct Graph* graph = createGraph(V);
		int start = 0, end = 0, weight = 0;
		while (E--) {
			cin >> start >> end >> weight;
			addEdge(graph, start - 1, end - 1, weight);
		}
		int source;
		cin >> source;
		dijkstra(graph, source - 1);
	}
	return 0;
}
