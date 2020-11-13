#include <iostream>
#define MAX 100
using namespace std;


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
	
	/*BinaryNode* search(int key) {
		if (key == data) {
			return this;
		}
		else if (key < data && left != NULL) {
			return left->search(key);
		}
		else if (key > data && right != NULL) {
			return right->search(key);
		}
		else {
			return NULL;
		}
	}*/
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
			cout << "ť�� ��ȭ�����Դϴ�." << endl;
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue() {
		if (isEmpty()) {
			cout << "ť�� ����ֽ��ϴ�." << endl;
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}
};
class BinaryTree:public BinaryNode {

protected:
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
			cout << " [ " << node->getData() << " ] ";
			inorder(node->getRight());
		}
	}

	void preorder() {
		cout << endl << " preorder: ";
		preorder(root);
	}
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			cout << " [ " << node->getData() << " ] ";
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
			cout << " [ " << node->getData() << " ] ";
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
					cout << " [ " << n->getData() << " ] ";
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		cout << endl;
	}

	//��� ���� ���ϴ� �Լ�
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) {
			return 0;
		}
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	//�ܸ� ��� ���� ���ϴ� �Լ�
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) { return 0; }
		if (node->isLeaf()) { return 1; }
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	//���� ���ϴ� �Լ�
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) { return 0; }
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}

};

class BinSrchTree :public BinaryTree {

public:
	BinSrchTree(void){}
	~BinSrchTree(void){}


	BinaryNode* search(int key) {
		BinaryNode* node = searchIter(root, key);
		if (node != NULL) {
			cout << "Ž������: Ű���� " << node->getData() << "�� ��� = " << node << endl;
		}
		else {
			cout << "Ž������: Ű���� " << key << "�� ������ " << endl;
		}
		return node;

	}
	
	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL)return NULL;
		if (key == n->getData()) {
			return n;
		}
		else if (key < n->getData()) {
			return searchRecur(n->getLeft(), key);
		}
		else {
			return searchRecur(n->getRight(), key);
		}
	}

	BinaryNode* searchIter(BinaryNode* n, int key) {
		while (n != NULL) {
			if (key == n->getData()) {
				return this;
			}
			else if (key < n->getData()) {
				n = n->getLeft();
			}
			else
				n = n->getRight();
		}
		return NULL;
	}

	void insert(BinaryNode* n){
		if (n == NULL)return;
		if (isEmpty())root = n;
		else insertRecur(root, n);
	}
	
	void insertRecur(BinaryNode* r, BinaryNode* n) {
		if (n->getData() == r->getData()) {
			return;
		}
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL) {
				r->setLeft(n);
			}
			else {
				insertRecur(r->getLeft(), n);
			}
		}
		else {
			if (r->getRight() == NULL)
			{
				r->setRight(n);
			}
			else {
				insertRecur(r->getRight(), n);
			}
		}
	}

	void remove(int key){
		if (isEmpty()) return;
		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		while (node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}
		
		if (node == NULL) {
			cout << "Error: key is not in the tree!" << endl;
			return;
		}
		else {
			remove(parent, node);
		}
	
	}

	void remove(BinaryNode* parent, BinaryNode* node) {
		if (node->isLeaf()) {
			if (parent == NULL) {
				root = NULL;
			}

			else {
				if (parent->getLeft() == node) {
					parent->setLeft(NULL);
				}
				else {
					parent->setRight(NULL);
				}
			}
		}
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
			if (node == root) {
				root = child;
			}
			else {
				if (parent->getLeft() == node) {
					parent->setLeft(child);
				}
				else
					parent->setRight(child);
			}
		}
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ) {
				succp->setLeft(succ->getRight());
			}
			else {
				succp->setRight(succ->getRight());
			}
			node->setData(succ->getData());
			node = succ;
		}
		delete node;
	}
	
};


void main() {
	BinSrchTree tree;
	
	tree.insert(new BinaryNode(35));
	tree.insert(new BinaryNode(18)); 
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));

	cout << "����� ���� = " << tree.getCount()<<endl;
	cout << "�ܸ��� ���� = " << tree.getLeafCount() << endl;
	cout << "Ʈ���� ���� = " << tree.getHeight() << endl;


	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);
	cout << "CASE1 ==> ��� 3 ����" << endl;
	tree.remove(3);
	tree.levelorder();
	cout << "CASE2 ==> ��� 68 ����" << endl;
	tree.remove(68);
	tree.levelorder();
	cout << "CASE3 ==> ��� 18 ����" << endl;
	tree.remove(18);
	tree.levelorder();
	cout << "CASE3 ==> ��� 35 ����" << endl;
	tree.remove(35);
	tree.levelorder();

	cout << "����� ���� = " << tree.getCount() << endl;
	cout << "�ܸ��� ���� = " << tree.getLeafCount() << endl;
	cout << "Ʈ���� ���� = " << tree.getHeight() << endl;
}