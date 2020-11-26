#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 100
using namespace std;
#define MAXL 256

class AdjMatGraph {
protected:
	int size;
	char vertices[MAXL];
	int adj[MAXL][MAXL]; //정적할당

public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAXL; }

	void reset() {
		size = 0;
		for (int i = 0; i < MAXL; i++) {
			for (int j = 0; j < MAXL; j++) {
				setEdge(i, j, 0);
			}
		}
	}

	void insertVertex(char name) {
		if (!isFull())vertices[size++] = name;
		else cout << "Error: 그래프 점점 개수 초과" << endl;
	}

	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}
	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);
		for (int i = 0; i < size; i++) {
			fprintf(fp, "%c ", getVertex(i));
			for (int j = 0; j < size; j++) {
				fprintf(fp, "%3d", getEdge(i, j));
			}
			fprintf(fp, "\n");
		}
	}

	void load(char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n;
			fscanf(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[80];
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					int val;
					fscanf(fp, "%d", &val);
					if (val != 0) {
						insertEdge(i, j);
					}
				}
			}
			fclose(fp);

		}
	}

	void store(char* filename) {
		FILE* fp = fopen(filename, "w");
		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}
};

class CircularQueue {
protected://상속을 위한
	int front;
	int rear;
	int data[MAX];

public:
	CircularQueue() {
		front = rear = 0;
	}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX == front; }

	void enqueue(int val) {
		if (isFull()) {
			cout << "큐가 포화상태입니다." << "\n";
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "큐가 공백상태입니다." << "\n";
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}

	void display() {
		cout << "큐내용: ";
		int maxi = (front < rear) ? rear : rear + MAX;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX];

		}
		cout << "\n";
	}
};

class SrchAMGraph :public AdjMatGraph {
	bool visited[MAX];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}
	bool isLinked(int u, int v) {
		return getEdge(u, v) != 0;
	}

	void BFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << " ";

		CircularQueue que;
		que.enqueue(v);

		while (!que.isEmpty()) {
			int v = que.dequeue();
			for (int w = 0; w < size; w++) {
				if (isLinked(v, w) && visited[w] == false) {
					visited[w] = true;
					cout << getVertex(w) << " ";
					que.enqueue(w);
				}
			}
		}
	}
};


int main() {
	SrchAMGraph g;
	g.load("graph2.txt");
	cout << "그래프(graph2.txt)" << endl;
	g.display();

	cout << "DFS====> ";
	g.resetVisited();
	g.BFS(0);
	cout << endl;
}