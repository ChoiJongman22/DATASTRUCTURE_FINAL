#include <iostream>
using namespace std;
class Node {
    Node* link;
    int data;
public:
    int size = 0;
    Node(int val = 0) : data(val), link(NULL) { }
    Node* getLink() { return link; }
    void setLink(Node* next) { link = next; }
    void display() { printf(" <%2d>", data); }
    bool hasData(int val) { return data == val; }
    void insertNext(Node* n) {
        if (n != NULL) {
            n->link = link;   // 그림 6.15의 (1)
            link = n;// 그림 6.15의 (2)
            size++;
        }
    }
    Node* removeNext() {
        Node* removed = link;
        if (removed != NULL) link = removed->link; // 그림 6.16의 (1)
        return removed;
    }
};

class LinkedList {
    Node org; // 헤드 노드 (헤드 포인터가 아님)
public:
    LinkedList() : org(0) { }       // 생성자
    ~LinkedList() { clear(); }     // 소멸자

    Node* getHead() { return org.getLink(); }
    bool isEmpty() { return getHead() == NULL; }
    Node* find(int val) {
        for (Node* p = getHead(); p != NULL; p = p->getLink()) {
            if (p->hasData(val))return p;
        }
        return NULL;
    }
    void clear() {
        while (!isEmpty())
            delete remove(0);
    }
    // pos번째 항목을 반환함
    Node* getEntry(int pos) {
        Node* n = &org;
        for (int i = -1; i < pos; i++, n = n->getLink()) {
            if (n == NULL) break;
        }
        return n;
    }
    int size() {
        int count = 0;
        for (Node* c = getHead(); c != NULL; c = c->getLink()) {
            count++;
        }
        return count;
    }
    // 화면에 보기 좋게 출력
    void display(string str) {
        cout << str;
        printf("[전체 항목 수 = %2d] : ", size());
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            p->display();
        printf("\n");
    }
    // 리스트의 어떤 위치에 항목 삽입
    void insert(int pos, Node* n) {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL)
            prev->insertNext(n);
    }

    // 리스트의 어떤 위치의 항목 삭제
    Node* remove(int pos) {
        Node* prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    void reverse()
    {
        /*Node* current = getHead();
        Node* next = NULL;
        Node* prev = NULL;

        while (current != NULL) {

            next = current->getLink();

            current->setLink(prev);

            prev = current;
            current = next;

        }
        org.setLink(prev);*/
        int count=0, i = 0;
        for (i; i < size(); i++) {
            Node* p = remove(size() - 1);
            insert(count++, p);
        }
    }

    void merge(LinkedList* that) {
        /*Node *This = getHead();
        while(1){
            if(This==NULL){
                This->setLink(that->getHead());
                break;
            }
            This = This->getLink();
        }*/

        while (that->isEmpty() == false) {
            Node* p = that->remove(0);
            insert(size(), p);
        }
    }
};


int main()
{
    LinkedList list, list2;         // 리스트 객체 생성
    list.insert(0, new Node(10));     // 리스트 맨 앞에 10 삽입
    list.insert(0, new Node(20));     // 리스트 맨 앞에 20 삽입
    list.insert(1, new Node(30));     // 리스트 1위치에 30 삽입
    list.insert(list.size(), new Node(40)); // 리스트 마지막에 40 삽입
    list.insert(2, new Node(50));     // 리스트 1위치에 50 삽입
    list.display("List(전)");             // 리스트내용 화면출력
    list.reverse();
    list.display("List(후)");

    list2.insert(0, new  Node(70));
    list2.insert(1, new  Node(80));
    list2.insert(2, new  Node(90));
    list2.display("List(that)");

    list.merge(&list2);
    list.display("List(Reverse+that");
    list2.display("List(that)");

    list.clear();
    list2.clear();
    list.display("끝");
    return 0;
}
