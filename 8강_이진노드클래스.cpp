#include <iostream>
using namespace std;

class BinaryNode {
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l),right(r){}
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
	BinaryTree():root(NULL){}
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
	void preorder(){
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

};

int main() {
	BinaryTree tree;
	BinaryNode* g = new BinaryNode('G', NULL, NULL);
	BinaryNode* h = new BinaryNode('H', NULL, NULL);
	BinaryNode* f = new BinaryNode('F', g, h);
	BinaryNode* c = new BinaryNode('C', f, NULL);
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* d = new BinaryNode('D', e, NULL);
	BinaryNode* b = new BinaryNode('B', d, NULL);
	BinaryNode* a = new BinaryNode('A', b, c);
	tree.setRoot(a);
	tree.inorder();
	tree.preorder();
	tree.postorder();
	cout << endl;
}