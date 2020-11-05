#include <iostream>
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
	bool isLeaf() { return left == NULL && right == NULL; }


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
	int calcSize() { return calcSize(root); }
	int calcSize(BinaryNode* node){
		if (node == NULL)return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}
};

int main() {
	BinaryTree tree3;
	BinaryNode* m4 = new BinaryNode(200, NULL, NULL);
	BinaryNode* m5 = new BinaryNode(500, NULL, NULL);
	BinaryNode* m3 = new BinaryNode(100, m4, m5);
	BinaryNode* m2 = new BinaryNode(50, NULL, NULL);
	BinaryNode* m1 = new BinaryNode(0, m2, m3);
	tree3.setRoot(m1);
	cout << "디렉터리 용량 계산 결과 : " << tree3.calcSize() << endl;


}