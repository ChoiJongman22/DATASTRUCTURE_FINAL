#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 100

class Line {
private:
	string data;
public:
	Line(string line = "") { data = line; }
	void Print(FILE* fp = stdout) { fprintf(fp, "%s", data); }
	bool hasData(string str) {
		return str == data;
	}
};

class Node:public Line {
private:
	Node* link;
	int data;
public:
	Node(string str) :Line(str), link(NULL) {}
	Node* getlink() { return link; }
	void setlink(Node* next) { link = next; }
	void display() { cout << "<" << data << ">"; }
	

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
protected:
	Node org;//�����
public:
	LinkedList() :org("") {}
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
};

class LineEditor :public LinkedList {
public:
	void Display(FILE* fp = stdout) {
		int i = 0;
		for (Node* p = getHead(); p != NULL; p = p->getlink(), i++) {
			fprintf(stderr, "%3d", i);
			p->Print(fp);
		}
	}
	
	void InsertLine() {
		int position;
		char line[MAX];
		cout << "�Է��� ��ȣ: ";
		cin >> position;
		cout << "�Է��� ����: ";
		fflush(stdin);
		fgets(line, MAX, stdin);
		insert(position, new Node(line));
	}

	void DeleteLine() {
		cout << "������ ��ȣ: ";
		int position;
		cin >> position;
		delete remove(position);
	}

	void ReplaceLine() {
		int position;
		char line[MAX];
		cout << " ������ ��ȣ: ";
		cin >> position;
		cout << " ������ ����: ";
		fflush(stdin);
		fgets(line, MAX, stdin);
		replace(position, new Node(line));
	}

	void LoadFile(char* fname) {
		FILE* fp = fopen(fname, "r");
		if (fp != NULL) {
			char line[MAX];
			while (fgets(line, MAX, fp)) {
				insert(size(), new Node(line));
			}
			fclose(fp);
		}
	}
	
	void StoreFile(char* fname) {
		FILE* fp = fopen(fname, "w");
		if (fp != NULL) {
			Display(fp);
			fclose(fp);
		}
	}

};

void Usage() {
	cout << "[�޴�����] i-�Է�,d-����,r-����,p-���,l-�����б�,s-����,q-����=> ";
}

void main() {
	char command;
	LineEditor editor;
	do {
		Usage();
		command = getchar();
		switch (command) {
		case 'd': editor.DeleteLine(); break;
		case 'i': editor.InsertLine(); break;
		case 'r': editor.ReplaceLine(); break;
		case 'l': editor.LoadFile("Text.txt"); break;
		case 's': editor.StoreFile("Text.txt"); break;
		case 'p': editor.Display(); break;
		case 'q': break;
		}
		fflush(stdin);
	} while (command != 'q');
}