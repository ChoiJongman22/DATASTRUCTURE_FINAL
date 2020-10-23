#include <iostream>
using namespace std;


class Node {
private:
	Node* link;
	int data;
public:
	Node(int val = 0):data(val),link(NULL){}
	Node* getlink() { return link; }
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
	Node org;
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

	}
};
int main() {

}