#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 100
#include <stdio.h>
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200
#include <conio.h>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;

class Record {
private:
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];

public:
	Record(char* w = "", char* m = "") {
		set(w, m);
	}
	void set(char* w, char* m) {
		strcpy(word, w);
		strcpy(meaning, m);
	}
	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word); }
	int compareMeaning(char* m) { return strcmp(meaning, m); }
	void display() { cout << word << " : " << meaning; }
	void copy(Record* n) { set(n->word, n->meaning); }


};
class BinaryNode:public Record {
protected:
	
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(char* w="",char* m="")
		:Record(w,m), left(NULL), right(NULL) {}
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
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

};

class BinaryTree :public BinaryNode {

protected:
	BinaryNode* root;

public:
	BinaryTree() :root(NULL) {}
	
	bool isEmpty() { return root == NULL; }

	
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			inorder(node->getLeft());
			node->display();
			inorder(node->getRight());
		}
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

};

class BinSrchTree :public BinaryTree {

public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}


	BinaryNode* search(char *key) {
		
		return searchRecur(root,key);

	}

	BinaryNode* searchRecur(BinaryNode* n, char* key) {
		if (n == NULL)return NULL;
		if (n->compare(key)==0) {
			return n;
		}
		else if (n->compare(key)<0) {
			return searchRecur(n->getLeft(), key);
		}
		else {
			return searchRecur(n->getRight(), key);
		}
	}
	

	void insert(BinaryNode* n) {
		if (n == NULL)return;
		if (isEmpty())root = n;
		else insertRecur(root, n);
	}

	void insertRecur(BinaryNode* r, BinaryNode* n) {
		if (n->compare(r)==0) {
			return;
		}
		else if (n->compare(r)>0) {
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

	void remove(char* data) {
		if (isEmpty()) return;
		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		while (node != NULL && node->compare(data) !=0) {
			parent = node;
			node = (node->compare(data)<0) ? node->getLeft() : node->getRight();
		}

		if (node != NULL) {
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
			
			node = succ;
		}
		delete node;
	}

};
class Dictionary :public BinSrchTree {

public:
	void printAllWords() {
		cout << "나의 단어장 : " << endl;
		if (!isEmpty())inorder(root);
	}
	void searchWord(char* word) {
		BinaryNode* node = search(word);
		if (node != NULL) {
			cout << " >>";
			node->display();
		}
		else cout << " >> 등록되지 않은 단어: " << word << endl;

	}
	void searchMeaning(char* m) {
		BinaryNode* node = (isEmpty()) ? NULL : searchByMeaning(root, m);
		if (node != NULL) {
			cout << "      >>";
			node->display();
		}
		else cout << "     >>  등록되지 않은 의미: m" << endl;
	}

	BinaryNode* searchByMeaning(BinaryNode* node, char* m) {
		if (node != NULL || node->compareMeaning(m) == 0)return node;
		BinaryNode* theNode = searchByMeaning(node->getLeft(), m);
		if (theNode != NULL)return theNode;
		return searchByMeaning(node->getRight(), m);
	}

};

void help() { cout << "사용법: i - 추가 d - 삭제 w - 단어검색 m - 의미검색 p - 출력 q - 종료 =>"; }


void main() {
	char command;
	char word[80];
	char meaning[200];
	Dictionary tree;
	do {
		help();
		command = _getche();
		cout << endl;
		switch (command) {
		case 'i': printf(" > 삽입 단어: "); gets_s(word);
			      printf(" > 단어 설명: "); gets_s(meaning);
				  tree.insert(new BinaryNode(word, meaning));
				  break;
		case 'd': printf(" > 삭제 단어: "); gets_s(word);
			tree.remove(word);
			break;
		case 'p': tree.printAllWords();
			cout << endl;
			break;
		case 'w': printf(" > 검색 단어: "); gets_s(word);
			tree.searchWord(word);
			break;
		case 'm': printf(" > 검색 의미: "); gets_s(word);
			tree.searchMeaning(word);
			break;
					
		}
	} while (command != 'q');


	


}