#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#define MAX_VTXS 256
using namespace std;
#define MAX 256

class AdjMatGraph {
protected:
	int size;
	char vertices[MAX];
	int adj[MAX][MAX]; //�����Ҵ�

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
		else cout << "Error: �׷��� ���� ���� �ʰ�" << endl;
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
	void randomGraph(int numVtx, int numEdge)
	{
		int i = 0;
		for (int j = 0; j < numVtx; j++)
			insertVertex('A' + j);
		while (i < numEdge)
		{
			int count = 0;
			do
			{
				int first = rand() % numVtx;
				int second;
				do
				{
					second = rand() % numVtx;
				} while (first == second);
				if (!adj[first][second])
				{
					insertEdge(first, second);
					count++;
				}
			} while (!count);
			i++;
		}
	}
	//��� ������ ����� "���� �׷���"�� �������� �߻���Ű�� �Լ�
	void randomConnectedGraph(int numVtx)
	{
		for (int j = 0; j < numVtx; j++)
			insertVertex('A' + j);
		for (int i = 0; i < numVtx; i++)
			for (int j = 0; j < numVtx; j++)
				if (i != j)
					insertEdge(i, j);
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
protected://����� ����
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
			cout << "ť�� ��ȭ�����Դϴ�." << "\n";
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "ť�� ��������Դϴ�." << "\n";
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}

	void display() {
		cout << "ť����: ";
		int maxi = (front < rear) ? rear : rear + MAX;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX];

		}
		cout << "\n";
	}
};

class SrchAMGraph :public AdjMatGraph

{

protected:

	bool visited[MAX_VTXS]; //������ �湮 ����

public:

	void resetVisited() //��� ������ �湮���� �ʾҴٰ� ����

	{

		for (int i = 0; i < size; i++)

			visited[i] = false;

	}

	bool isLinked(int u, int v)

	{

		return getEdge(u, v) != 0;

	}

	void ConnectedGraph(int numVtx)

	{

		int cnt = rand() % ((numVtx * 2) - 1) + 1;

		cout << "���� ���� �׷��� ����" << endl;

		cout << "���� ��: " << cnt << endl;

		for (int j = 0; j < numVtx; j++)

			insertVertex('A' + j);

		int first = rand() % numVtx;

		int second;

		do

		{

			second = rand() % numVtx;

		} while (first == second);

		insertEdge(first, second);

		for (int i = 1; i < cnt; i++)

		{

			int linked = 0;

			do

			{

				first = rand() % numVtx;

				do

				{

					second = rand() % numVtx;

				} while (first == second);

				for (int j = 0; j < numVtx; j++)

					if (isLinked(first, j) || isLinked(second, j))

						linked++;

			} while (getEdge(first, second) || linked == 0);

			insertEdge(first, second);

		}

	}


	//���� �켱 Ž�� �Լ�

	void DFS(int v)

	{

		visited[v] = true;

		cout << getVertex(v) << " ";

		for (int w = 0; w < size; w++)

			if (isLinked(v, w) && visited[w] == false)

				DFS(w); //����+�湮X=> ��ȯ ȣ��� �湮

	}

	//������ķ� ǥ���� �׷����� ���� �ʺ�켱Ž�� ����

	void BFS(int v)

	{

		visited[v] = true;

		cout << getVertex(v) << " "; //������ �̸� ���



		CircularQueue que;

		que.enqueue(v); //���� ������ ť�� ����



		while (!que.isEmpty())

		{

			int v = que.dequeue(); //ť�� ���� ����

			for (int w = 0; w < size; w++)

				if (isLinked(v, w) && visited[w] == false)

				{

					visited[w] = true; //�湮 ǥ��

					cout << getVertex(w) << " ";

					que.enqueue(w);

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
		/*cout << "�׷����� ���Ἲ�� ���� == " << count << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << " = " << label[i]<<" ";
		}
		cout << endl;*/
		return count;
	}

};




//void main() {
//	ConnectedComponentGraph g;
//	for (int i = 0; i < 5; i++) {
//		g.insertVertex('A' + i);
//	}
//	g.insertEdge(1, 0);
//	g.insertEdge(2, 0);
//	g.insertEdge(3, 4);
//
//	cout << "���� ���� �׽�Ʈ �׷���" << endl;
//
//	g.display();
//	g.resetVisited();
//	g.findConnectedComponent();
//	g.findBridge(g);
//
//}

int main(void)

{

	ConnectedComponentGraph g, g2;

	int numVtx, numEdge;

	srand((unsigned)time(NULL));

	cout << "������ ���� �Է�: ";

	cin >> numVtx;

	do

	{

		cout << "������ ���� �Է�:(������ ���� �ι踦 �Ѿ�� �ȵȴ�) ";

		cin >> numEdge;

	} while (numEdge > 2 * numVtx);
	g.randomGraph(numVtx, numEdge);
	cout << "�׷��� ���" << endl;
	g.display();
	g.store("graph.txt");
	cout << endl << "���� ���� �׽�Ʈ �׷���" << endl;
	g.resetVisited();
	g.findConnectedComponent();
	cout << endl << endl << "���� �׷��� ����" << endl;
	g2.randomConnectedGraph(numVtx);
	cout << endl << "���� ���� �׽�Ʈ �׷���" << endl;
	g2.resetVisited();
	g2.findConnectedComponent();
	g.DFS(0);
	return 0;
}


