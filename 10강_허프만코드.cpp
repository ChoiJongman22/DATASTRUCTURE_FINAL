#include <iostream>
#define MAX 100
using namespace std;


class HeapNode {
private:
	int key;
public:
	HeapNode(int k = 0) :key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { cout << " " << key; }
};

class MinHeap {
private:
	HeapNode node[MAX];
	int size;

public:
	MinHeap():size(0){}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX - 1; }
	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull())return;
		int i = ++size;
		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty())return NULL;
		HeapNode root = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child<size && getLeft(parent).getKey()>getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey())break;
			node[parent] = node[child];
			parent = child;
			child *= 2;

		}
		node[parent] = last;
		return root;
	}
};

void MakeTree(int freq[], int n) {
	MinHeap heap;
	for (int i = 0; i < n; i++) {
		heap.insert(freq[i]);
	}
	for (int i = 1; i < n; i++) {
		HeapNode e1 = heap.remove();
		HeapNode e2 = heap.remove();
		heap.insert(e1.getKey() + e2.getKey());
		cout << e1.getKey() << " + " << e2.getKey() << endl;
	}
}

void main() {
	MinHeap heap;
	int freq[] = { 15,12,8,6,4 };
	
	MakeTree(freq, 5);
}