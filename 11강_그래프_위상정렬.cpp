#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 256
using namespace std;

class Stack {
private:
	int top;
	int data[MAX];

public:
	Stack() { top = -1; }
	~Stack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX - 1; }
	void push(int a) {
		if (isFull()) {
			cout << "스택포화" << "\n";
		}
		data[++top] = a;
	}
	int pop() {
		if (isEmpty()) {
			cout << "스택공백에러" << "\n";
		}
		return data[top--];
	}

	int peek() {
		if (isEmpty()) {
			cout << "스택공백에러" << "\n";
		}
		return data[top];
	}

	void display() {
		cout << "스택의 항목 수" << top + 1 << endl;
		for (int i = top; i >= 0; i--) {
			cout << data[i] << endl;
		}
	}
};

class Node {
protected:
	int id;
	Node* link;

public:
	Node() {}
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


class AdjListGraph:public Node {
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
		adj[v] = new Node(u, adj[v]);
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

class TopoSortGraph :public AdjListGraph {
	int inDeg[MAX];
public:

	void insertDirEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);
	}

	void Toposort() {
		for (int i = 0; i < size; i++) {
			inDeg[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			Node* node = adj[i];
			while (node != NULL) {
				inDeg[node->getId()]++;
				node = node->getlink();
			}
		}

		Stack s;
		for (int i = 0; i < size; i++) {
			if (inDeg[i] == 0) {
				s.push(i);
			}
		}

		while (s.isEmpty() == false) {
			int w = s.pop();
			cout << " " << getVertex(w) << " ";
			Node* node = adj[w];
			while (node != NULL) {
				int u = node->getId();
				inDeg[u]--;
				if (inDeg[u] == 0) {
					s.push(u);
				}
				node = node->getlink();
			}
		}
		cout << endl;
	}
};

void main() {
	TopoSortGraph g;
	for (int i = 0; i < 6; i++) {
		g.insertVertex('A'+i);//책과 다른 점  저자 나쁜놈..ㅡㅡ
	}
	g.insertDirEdge(0, 2);
	g.insertDirEdge(0, 3);
	g.insertDirEdge(1, 3);
	g.insertDirEdge(1, 4);
	g.insertDirEdge(2, 3);
	g.insertDirEdge(2, 5);
	g.insertDirEdge(3, 5);
	g.insertDirEdge(4, 5);
	cout << "Topology Sort";
	g.Toposort();
}