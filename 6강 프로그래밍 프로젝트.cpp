#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* link;
	Node(int tmp) {
		data = tmp;
		link = NULL;
	}
};

class CircularList {
private:
	Node* head;
	Node* tail;

public:
	CircularList() {
		head = tail = NULL;

	}
	~CircularList() {
		clear();
	}
	void clear() {
		while (!isEmpty()) {
			delete remove(0);
		}
	}
	Node* getHead() {
		return head;

	}
	bool isEmpty() {
		return getHead() == NULL;
	}
	void insert(int pos, Node* n) {
		if (pos == 0) {
			if (head == NULL) {
				head = n;
				tail = n;
				n->link = tail;
				return;
			}
		}
		else if (head != NULL) {
			n->link = head;
			head = n;
			tail->link = n;
			return;
		}

		int index = 0;
		Node* current = head;
		while (index > pos - 1) {
			current = current->link;
			index++;
		}
		n->link = current->link;
		current->link = n;
	}

	Node* remove(int pos) {
		if (isEmpty()) {
			return NULL;
		}
		if (pos == 0) {
			if (head == tail) {
				head = tail = NULL;
				return NULL;
			}
			else {
				Node* del = head;
				head = head->link;
				tail->link = head;
				return del;
			}
		}
		int index = 0;
		Node* tmp = NULL;
		Node* current = head;
		while (index < pos) {
			if (current->link == NULL) {
				return NULL;
			}
			if (index == pos - 1) {
				tmp = current;
			}
			current = current->link;
			index++;
		}
		tmp->link = current->link;
		if (current == tail) {
			tail = tmp;
		}
		return current;
	}
	int size()
	{
		Node* current = head;
		int index = 1;
		if (!isEmpty())
			current = current->link;
		while (current != head)
		{
			index++;
			current = current->link;
		}
		return index;
	}


	void display()
	{
		if (size() == 1) //size()가 1을 반환했다는 것은 리스트가 비었다는 뜻
		{
			cout << "[전체 항목 수= 0]: " << endl;
			return;
		}
		cout << "[전체 항목 수 = " << size() << "] : ";
		Node* current = head;
		cout << "<" << current->data << "> ";
		current = current->link;
		while (current != head)
		{
			cout << "<" << current->data << "> ";
			current = current->link;
		}
		cout << endl;
	}
}; 
int main(void)

{

	CircularList list;

	list.insert(0, new Node(10));

	list.insert(0, new Node(20));

	list.insert(1, new Node(30));

	list.insert(list.size(), new Node(40));

	list.insert(2, new Node(50));

	list.display();

	list.remove(2);

	list.remove(list.size() - 1);

	list.remove(0);

	list.display();

	list.clear();

	list.display();

	return 0;

}
