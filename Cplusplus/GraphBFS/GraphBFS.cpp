#include <bits/stdc++.h>
using namespace std;

struct AdjNode {
	int value;
	struct AdjNode * next;
};

struct AdjList {
	struct AdjNode * head;
};

struct Graph {
	int noOfNodes;
	struct AdjList * adjList;
};

struct AdjNode * newAdjNode(int value){
	struct AdjNode * retNode = new AdjNode();
	retNode->value = value;
	retNode->next = NULL;
	return retNode;
}

struct Graph * getGraph(int noOfNodes){
	struct Graph * retGraph = new Graph();
	retGraph->noOfNodes = noOfNodes;
	retGraph->adjList = new AdjList[noOfNodes];
	return retGraph;
}

void addEdge(struct Graph * graph, int src, int dest){
	struct AdjNode * newNode = newAdjNode(dest);
	newNode->next = graph->adjList[src].head;
	graph->adjList[src].head = newNode;

	newNode = newAdjNode(src);
	newNode->next = graph->adjList[dest].head;
	graph->adjList[dest].head = newNode;
}

void BFS(int N, int src, Graph * graph, bool * visited, int * dist) {
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	visited[src] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		AdjNode * cur = graph->adjList[front].head;
		while(cur != NULL && !visited[cur->value]){
			dist[cur->value] = dist[front] + 6;
			visited[cur->value] = true;
			q.push(cur->value);
			cur = cur->next;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		struct Graph * graph = getGraph(N);

		bool visited[N];
		for (int i = 0; i < N; i++){
			visited[i] = false;
		}
		int start, end;
		while (M--) {
			cin >> start >> end;
			addEdge(graph, start-1, end-1);
		}

		int src;
		cin >> src;

		int * dist = new int[N];
		for (int i = 0; i < N; i++){
			dist[i] = -1;
		}

		BFS(N, src-1, graph, visited, dist);

		for (int i = 0; i < N; i++){
			if (i == src-1)
				continue;
			cout << dist[i] << " ";
		}
		cout << endl;
	}
	return 0;
}