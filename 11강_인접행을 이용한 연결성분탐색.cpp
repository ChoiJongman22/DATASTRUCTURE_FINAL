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

	int getSize() {
		return size;
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


class SrchAMGraph :public AdjMatGraph {
protected:
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

	void DFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << " ";

		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false) {
				DFS(w);
			}
		}
	}
};

class ConnectedComponentGraph :public SrchAMGraph {
	int label[MAX];
public:
	void labelDFS(int v, int color) {
		visited[v] = true;
		label[v] = color;
		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false) {
				labelDFS(w, color);
			}
		}
	}

	
	int findBridge(ConnectedComponentGraph g) {
		int i, j;
		int count = 0;
		g.resetVisited();

		for (i = 0; i < g.getSize(); i++) {
			for (j = 0; j < i; j++) {
				if (g.getEdge(i, j) != 0) {
					g.setEdge(i, j, 0);
					g.setEdge(j, i, 0);

					g.resetVisited();
					if (g.findConnectedComponent() > 1) {
						printf(" Bridge%d: %c-%c\n", count + 1, g.getVertex(i), g.getVertex(j));
						count++;
					}
					g.setEdge(i, j, 1);
					g.setEdge(j, i, 1);
				}
			}
		}
		return count;	
    }


	int findConnectedComponent() {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (visited[i] == false) {
				labelDFS(i, ++count);
			}
		}
		/*cout << "그래프의 연결성분 개수 == " << count << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << " = " << label[i]<<" ";
		}
		cout << endl;*/
		return count;
	}

};


void main() {
	ConnectedComponentGraph g;
	for (int i = 0; i < 5; i++) {
		g.insertVertex('A' + i);
	}
	g.insertEdge(1, 0);
	g.insertEdge(2, 0);
	g.insertEdge(3, 4);

	cout << "연결 성분 테스트 그래프" << endl;

	g.display();
	g.resetVisited();
	g.findConnectedComponent();
	g.findBridge(g);

}