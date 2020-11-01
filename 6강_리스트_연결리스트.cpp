#include <iostream>
using namespace std;


class Node {
private:
	Node* link;
	int data;
public:
	Node(int val = 0):data(val),link(NULL){}
	Node* getlink() { return link; }
	int getData() {
		return data;
	}
	void setlink(Node* next) { link = next; }
	void display() { cout << "<" << data << ">"; }
	bool hasData(int val) { return data == val; }

	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) {
			link = removed->link;
		}
		return removed;
	}
};

class LinkedList {
private:
	Node org;//헤드노드
public:
	LinkedList() :org(0) {}
	~LinkedList() { clear(); }
	void clear() { while (!isEmpty())delete remove(0); }
	Node* getHead() { return org.getlink(); }
	bool isEmpty() {
		return getHead() == NULL;
	}
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getlink()) {
			if (n == NULL)break;
		}
		return n;
	}
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getlink()) {
			count++;
		}
		return count;
	}
	void display() {
		cout << "전체항목수: " << size();
		for (Node* p = getHead(); p != NULL; p = p->getlink()) {
			p->display();
		}
		cout << endl;
	}

	void sum() {
		int Add = 0;
		cout << " [모든 항목 합 = ";
		for (Node* p = getHead(); p != NULL; p = p->getlink()) {
			Add += p->getData();
		}
		cout << Add << "]" << endl;
	}

	int count(int val) {
		int cnt = 0;
		for (Node* p = getHead(); p != NULL; p = p->getlink()) {
			if (p->hasData(val)) {
				cnt++;
			}
		}
		return cnt;
	}
	void reverse() {
		int count = 0;
		for (int i = 0; i < size(); i++) {
			Node* p = remove(size() - 1);
			insert(count++, p);
		}
	}
	void merge(LinkedList* that) {
		while (!that->isEmpty()) {
			Node* p = that->remove(0);
			insert(size(), p);
		}
	}
};
int main() {
	LinkedList list;
	list.insert(0, new Node(10));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node(90));
	list.display();
	list.clear();
	list.display();
}