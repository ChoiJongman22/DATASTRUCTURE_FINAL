#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 256

class AdjMatGraph {
protected:
	int size;
	char vertices[MAX];
	int adj[MAX][MAX]; //정적할당

public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX; }

	void reset() {
		size = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
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

void main() {
	AdjMatGraph g;
	for (int i = 0; i < 4; i++) {
		g.insertVertex('A' + i);
	}
	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);
	cout << "인접 행렬로 표현한 그래프" << endl;
	g.display();

	g.store("graph.txt");
	g.reset();
	g.load("graph.txt");
	cout << "인접행렬로 표현한 그래프 (파일: graph.txt)" << endl;
	g.display();
}