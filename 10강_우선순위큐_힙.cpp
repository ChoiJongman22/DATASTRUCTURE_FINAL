#include <iostream>
#define MAX 200
using namespace std;


class HeapNode {
private:
	int key;
public:
	HeapNode(int k=0):key(k){}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { cout <<" "<<key; }
};

class MaxHeap {
private:
	HeapNode node[MAX];
	int size;

public:
	MaxHeap() :size(0) {} //�ϴ� size�� 0���� �ʱ�ȭ ���ְ� �ε��� 0��°�� ���� �� �ְڴٴ� ������ ����!
	bool isEmpty(){return size == 0;}
	bool isFull() { return size == MAX - 1; }
	HeapNode& getParent(int i) { return node[i / 2]; } //��Ģ1: �θ���
	HeapNode& getLeft(int i) { return node[i * 2]; } //��Ģ2:  2��
	HeapNode& getRight(int i) { return node[i * 2 + 1]; } // ��Ģ3: 2�� +1

	void insert(int key){
		if (isFull())return;
		int i = ++size; //���������� �������!
		while (i != 1 && key > getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	
	}
	HeapNode remove(){
		if (isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) {
				child++;
			}
			if (last.getKey() >= node[child].getKey()) break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}
	HeapNode find() { return node[1]; }//�ֻ�� ���� ã���� �Ǵµ� �ְ� ���� �ε����� 0�� �ƴ϶� 1�̾�

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				cout << endl;
				level *= 2;
			}
			node[i].display();//�Լ� �������̵�!
		}
		cout << endl << "--------------------------";
	}

};

int main(){
	MaxHeap heap;

	/*heap.insert(10);
	heap.insert( 5); 
	heap.insert(30); 
	heap.insert( 8);
	heap.insert( 9);
	heap.insert( 3);
	heap.insert( 7);*/
	//heap.display();
	////���⼭ ������ �ٲ㺸�� �ٸ��� ��µȴٴ� �� �� �� �ִ�.
	//heap.insert(10);
	//heap.insert(5);
	//heap.insert(30);
	//heap.insert(3);
	//heap.insert(7);
	//heap.insert(9);
	//heap.insert(8);
	//heap.display();
	//
	////��ġ?
	//heap.remove();
	//heap.display();
	//heap.remove();
	//heap.display();

	heap.insert(2);
	heap.insert( 5);
	heap.insert(6);
	heap.insert( 8);
	heap.insert( 9);
	heap.insert( 10);
	heap.display();
	cout << endl;
}