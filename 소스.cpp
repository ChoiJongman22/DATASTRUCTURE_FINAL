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
            n->link = link;   // �׸� 6.15�� (1)
            link = n;// �׸� 6.15�� (2)
            size++;
        }
    }
    Node* removeNext() {
        Node* removed = link;
        if (removed != NULL) link = removed->link; // �׸� 6.16�� (1)
        return removed;
    }
};

class LinkedList {
    Node org; // ��� ��� (��� �����Ͱ� �ƴ�)
public:
    LinkedList() : org(0) { }       // ������
    ~LinkedList() { clear(); }     // �Ҹ���

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
    // pos��° �׸��� ��ȯ��
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
    // ȭ�鿡 ���� ���� ���
    void display(string str) {
        cout << str;
        printf("[��ü �׸� �� = %2d] : ", size());
        for (Node* p = getHead(); p != NULL; p = p->getLink())
            p->display();
        printf("\n");
    }
    // ����Ʈ�� � ��ġ�� �׸� ����
    void insert(int pos, Node* n) {
        Node* prev = getEntry(pos - 1);
        if (prev != NULL)
            prev->insertNext(n);
    }

    // ����Ʈ�� � ��ġ�� �׸� ����
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
    LinkedList list, list2;         // ����Ʈ ��ü ����
    list.insert(0, new Node(10));     // ����Ʈ �� �տ� 10 ����
    list.insert(0, new Node(20));     // ����Ʈ �� �տ� 20 ����
    list.insert(1, new Node(30));     // ����Ʈ 1��ġ�� 30 ����
    list.insert(list.size(), new Node(40)); // ����Ʈ �������� 40 ����
    list.insert(2, new Node(50));     // ����Ʈ 1��ġ�� 50 ����
    list.display("List(��)");             // ����Ʈ���� ȭ�����
    list.reverse();
    list.display("List(��)");

    list2.insert(0, new  Node(70));
    list2.insert(1, new  Node(80));
    list2.insert(2, new  Node(90));
    list2.display("List(that)");

    list.merge(&list2);
    list.display("List(Reverse+that");
    list2.display("List(that)");

    list.clear();
    list2.clear();
    list.display("��");
    return 0;
}
