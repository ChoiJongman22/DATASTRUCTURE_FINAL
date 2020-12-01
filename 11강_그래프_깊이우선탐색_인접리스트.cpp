#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 256
using namespace std;

class Node {
protected:
	int id;
	Node* link;

public:
	Node(int i, Node* l = NULL) :id(i), link(l) { }
	~Node() {
		if (link != NULL) {
			delete link;
		}
	}

	int getId() { return id; }
	Node* getlink() { return link; }
	void setlink(Node* l) { link = l; }
};


class AdjListGraph {
protected:
	int size;
	char vertices[MAX];
	Node* adj[MAX];

public:
	AdjListGraph() :size(0) {}
	~AdjListGraph() { reset(); }
	void reset() {
		for (int i = 0; i < size; i++) {
			if (adj[i] != NULL) {
				delete adj[i];
			}
		}
		size = 0;
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX; }
	char getVertex(int i) { return vertices[i]; }
	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: 그래프 정점 개수" << endl;
	}

	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);
		//adj[v] = new Node(u, adj[v]); //방향그래프... 아진짜책거지같네ㅡㅡ
	}

	void display() {
		cout << size << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << "  ";
			for (Node* v = adj[i]; v != NULL; v = v->getlink()) {
				cout << "  " << getVertex(v->getId());
			}
			cout << endl;
		}
	}
	Node* adjacent(int v) { return adj[v]; }

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
};

class SrchALGraph :public AdjListGraph {
	bool visited[MAX];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}

	bool isLinked(int u, int v) {
		for (Node* p = adj[u]; p != NULL; p = p->getlink()) {
			if (p->getId() == v)return true;
		}
		return false;
	}

	void DFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << " ";

		for (Node* p = adj[v]; p != NULL; p = p->getlink()) {
			if (visited[p->getId()] == false) {
				DFS(p->getId());
			}
		}
	}
	
};


int main() {
	SrchALGraph g;
	g.load("graph2.txt");
	cout << "그래프(graph2.txt)" << endl;
	g.display();

	cout << "DFS====> ";
	g.resetVisited();
	g.DFS(0);
	cout << endl;
}
