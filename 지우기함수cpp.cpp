#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX_VTXS   256

using namespace std;

//배열로 구현
class AdjMatGraph
{
protected:
    int      size;                  // 정점의 개수
    char   vertices[MAX_VTXS];         // 정점의 이름
    int      adj[MAX_VTXS][MAX_VTXS];   // 인접 행렬

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
        else printf("Error: 그래프 정점의 개수 초과\n");
    }

    void insertEdge(int u, int v) {
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    //**추가**
    void deleteVertex(int v) {
        //정점을 삭제하려면, 정점과 정점에 연결되어 있던 간선 모두 삭제해야 함.

        //1. 간선 삭제
        //adj 한 행씩 위로 올리기
        for (int i = v; i < size - 1; i++) {
            for (int j = 0; j < size; j++) {
                adj[i][j] = adj[i + 1][j];
            }
        }

        //adj 한 열씩 앞으로 당기기
        for (int i = v; i < size - 1; i++) {
            for (int j = 0; j < size; j++) {
                adj[j][i] = adj[j][i + 1];
            }
        }

        //ad 바깥쪽 테두리 0
        for (int i = 0; i < size; i++) {
            adj[size - 1][i] = 0;
            adj[i][size - 1] = 0;
        }

        //2. 정점 삭제
        for (int i = v; i < size - 1; i++) {
            vertices[i] = vertices[i + 1];
        }

        //사이즈 축소
        size--;

        //검사
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


//리스트로 구현
class Node
{
protected:
    int      id;      // 정점의 id
    Node* link;   // 다음 노드의 포인터
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
    int      size;            // 정점의 개수
    char   vertices[MAX_VTXS];   // 정점 정보 (응용에 따라 확장 필요)
    Node* adj[MAX_VTXS];      // 각 정점의 인접 리스트

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
        else printf("Error: 그래프 정점 개수 초과\n");
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

    //**추가**
    void deleteVertex(int v) {

        //해당 정점과 연결된 간선 삭제
        for (Node* n = adj[v]; n != NULL; n = n->getLink()) {
            deleteEdge(v, n->getId());
        }

        //adj, vertices 한 칸씩 앞으로 당기기
        for (int i = v; i < size - 1; i++) {
            adj[i] = adj[i + 1];
            vertices[i] = vertices[i + 1];
        }

        //사이즈 축소
        size--;
    }

    void deleteEdge(int u, int v) {

        if (adj[u] == NULL || adj[v] == NULL) {
            cout << "간선이 존재하지 않습니다.\n";
            return;
        }

        //u에 연결된 노드 지우기
        Node* parent = NULL;
        Node* n = adj[u];
        Node* child = NULL;

        //지워야할 노드가 바로 앞 인 경우
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
                cout << "간선이 존재하지 않습니다.\n";
                return;
            }
        }

        //v에 연결된 간선 지우기
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
                cout << "간선이 존재하지 않습니다.\n";
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