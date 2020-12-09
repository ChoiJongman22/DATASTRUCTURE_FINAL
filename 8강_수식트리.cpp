#include <iostream>
using namespace std;
#define MAX 100


class BinaryNode {
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r) {}
	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }


};

class CircularQueue {
private:
	int front;
	int rear;
	BinaryNode* data[MAX];
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX == front; }
	void enqueue(BinaryNode* n) {
		if (isFull()) {
			cout << "큐가 포화상태입니다." << endl;
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue() {
		if (isEmpty()) {
			cout << "큐가 비어있습니다." << endl;
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}
};



class BinaryTree {
private:
	BinaryNode* root;

public:
	BinaryTree() :root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }
	void inorder() {
		cout << endl << " inorder: ";
		inorder(root);
	}
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			inorder(node->getLeft());
			cout << " [ " << (char)node->getData() << " ] ";
			inorder(node->getRight());
		}
	}
	void preorder() {
		cout << endl << " preorder: ";
		preorder(root);
	}
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			cout << " [ " << (char)node->getData() << " ] ";
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}
	void postorder() {
		cout << endl << " postorder: ";
		postorder(root);
	}

	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			cout << " [ " << (char)node->getData() << " ] ";
		}
	}

	void levelorder() {
		cout << endl << " levelorder: ";
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					cout << " [ " << (char)n->getData() << " ] ";
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		cout << endl;
	}
	//노드 개수 구하는 함수
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) {
			return 0;
		}
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	//단말 노드 개수 구하는 함수
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) { return 0; }
		if (node->isLeaf()) { return 1; }
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	//높이 구하는 함수
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) { return 0; }
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode* node) {
		if (node == NULL) { return 0; }
		if (node->isLeaf())return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
			}
			return 0;
		}
	}
};

int main() {
	BinaryTree tree2;

	BinaryNode* n1 = new BinaryNode(3, NULL, NULL);
	BinaryNode* n2 = new BinaryNode(2, NULL, NULL);
	BinaryNode* n3 = new BinaryNode('*', n1, n2);
	BinaryNode* n4 = new BinaryNode(5, NULL, NULL);
	BinaryNode* n5 = new BinaryNode(6, NULL, NULL);
	BinaryNode* n6 = new BinaryNode('-', n4, n5);
	BinaryNode* n7 = new BinaryNode('+', n3, n6);
	tree2.setRoot(n7);
	cout << "계산결과 : " << tree2.evaluate() << endl;
}