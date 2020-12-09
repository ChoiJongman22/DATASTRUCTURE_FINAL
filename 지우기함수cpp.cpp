#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX_VTXS   256

using namespace std;

//�迭�� ����
class AdjMatGraph
{
protected:
    int      size;                  // ������ ����
    char   vertices[MAX_VTXS];         // ������ �̸�
    int      adj[MAX_VTXS][MAX_VTXS];   // ���� ���

public:
    AdjMatGraph() { reset(); }
    ~AdjMatGraph() {  }

    char getVertex(int i) { return vertices[i]; }
    int    getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    void reset() {
        size = 0;
        for (int i = 0; i < MAX_VTXS; i++)
            for (int j = 0; j < MAX_VTXS; j++)
                setEdge(i, j, 0);
    }

    void insertVertex(char name) {
        if (!isFull()) vertices[size++] = name;
        else printf("Error: �׷��� ������ ���� �ʰ�\n");
    }

    void insertEdge(int u, int v) {
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    //**�߰�**
    void deleteVertex(int v) {
        //������ �����Ϸ���, ������ ������ ����Ǿ� �ִ� ���� ��� �����ؾ� ��.

        //1. ���� ����
        //adj �� �྿ ���� �ø���
        for (int i = v; i < size - 1; i++) {
            for (int j = 0; j < size; j++) {
                adj[i][j] = adj[i + 1][j];
            }
        }

        //adj �� ���� ������ ����
        for (int i = v; i < size - 1; i++) {
            for (int j = 0; j < size; j++) {
                adj[j][i] = adj[j][i + 1];
            }
        }

        //ad �ٱ��� �׵θ� 0
        for (int i = 0; i < size; i++) {
            adj[size - 1][i] = 0;
            adj[i][size - 1] = 0;
        }

        //2. ���� ����
        for (int i = v; i < size - 1; i++) {
            vertices[i] = vertices[i + 1];
        }

        //������ ���
        size--;

        //�˻�
        //for (int i = 0; i < size; i++) {
        //   for (int j = 0; j < size; j++) {
        //      cout << adj[i][j] << " ";
        //   }
        //   cout << "\n";
        //}
    }

    void deleteEdge(int u, int v) {
        setEdge(u, v, 0);
        setEdge(v, u, 0);
    }
};


//����Ʈ�� ����
class Node
{
protected:
    int      id;      // ������ id
    Node* link;   // ���� ����� ������
public:
    Node(int i, Node* l = NULL) : id(i), link(l) { }
    ~Node(void) {
        if (link != NULL)
            delete link;
    }
    int     getId() { return id; }
    Node* getLink() { return link; }
    void setLink(Node* l) { link = l; }
};

class AdjListGraph
{
    int      size;            // ������ ����
    char   vertices[MAX_VTXS];   // ���� ���� (���뿡 ���� Ȯ�� �ʿ�)
    Node* adj[MAX_VTXS];      // �� ������ ���� ����Ʈ

public:
    AdjListGraph(void) : size(0) { }
    ~AdjListGraph(void) { reset(); }

    void reset(void) {
        for (int i = 0; i < size; i++)
            if (adj != NULL) delete adj[i];
        size = 0;
    }
    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size >= MAX_VTXS); }
    char getVertex(int i) { return vertices[i]; }

    void insertVertex(char val) {
        if (!isFull()) {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else printf("Error: �׷��� ���� ���� �ʰ�\n");
    }

    void insertEdge(int u, int v) {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
    }

    void display() {
        printf("%d\n", size);
        for (int i = 0; i < size; i++) {
            printf("%c  :", getVertex(i));

            for (Node* v = adj[i]; v != NULL; v = v->getLink())
                printf("   %c", getVertex(v->getId()));
            printf("\n");
        }
    }

    //**�߰�**
    void deleteVertex(int v) {

        //�ش� ������ ����� ���� ����
        for (Node* n = adj[v]; n != NULL; n = n->getLink()) {
            deleteEdge(v, n->getId());
        }

        //adj, vertices �� ĭ�� ������ ����
        for (int i = v; i < size - 1; i++) {
            adj[i] = adj[i + 1];
            vertices[i] = vertices[i + 1];
        }

        //������ ���
        size--;
    }

    void deleteEdge(int u, int v) {

        if (adj[u] == NULL || adj[v] == NULL) {
            cout << "������ �������� �ʽ��ϴ�.\n";
            return;
        }

        //u�� ����� ��� �����
        Node* parent = NULL;
        Node* n = adj[u];
        Node* child = NULL;

        //�������� ��尡 �ٷ� �� �� ���
        if (n->getId() == v) {
            child = n->getLink();
            adj[u] = child;
        }
        else {
            while (n != NULL) {
                if (n->getId() == v) {
                    child = n->getLink();
                    parent->setLink(child);
                    break;
                }
                parent = n;
                n = n->getLink();
            }

            if (n == NULL) {
                cout << "������ �������� �ʽ��ϴ�.\n";
                return;
            }
        }

        //v�� ����� ���� �����
        parent = NULL;
        n = adj[v];
        child = n->getLink();
        if (n->getId() == u) {
            adj[v] = child;
        }
        else {
            while (n != NULL) {
                if (n->getId() == u) {
                    parent->setLink(child);
                    break;
                }
                parent = n;
                n = n->getLink();
                child = n->getLink();
            }

            if (n == NULL) {
                cout << "������ �������� �ʽ��ϴ�.\n";
                return;
            }
        }
    }
};



int main() {
    AdjListGraph g;
    g.reset();
    for (int i = 0; i < 7; i++) {
        g.insertVertex('A' + i);
    }
    g.insertEdge(1, 0);
    g.insertEdge(1, 3);
    g.insertEdge(1, 4);
    g.insertEdge(1, 6);
    g.insertEdge(3, 6);

    g.display();

    g.deleteVertex(1);

    g.display();
}