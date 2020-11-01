#include <iostream>
#define MAX 100
using namespace std;

class ArrayList {
private:
	int data[MAX];//정적 할당
	int length; //요소의 개수
public:
	ArrayList() { length = 0; }
	bool isFull() { return length == MAX; }
	bool isEmpty() { return length == 0; }
	void insert(int pos, int e) {
		if (!isFull() && pos >= 0 && pos <= length) {
			for (int i = length; i > pos; i--) {
				data[i] = data[i - 1];
			}	
			data[pos] = e;
			length++;
		}
		else {
			cout << "포화상태 오류 또는 삽입 위치 오류";
		}
	}
	void remove(int pos) {
		if (!isEmpty() && 0 <= pos && pos < length) {
			for (int i = pos + 1; i < length; i++) {
				data[i - 1] = data[i];
			}
			length--;
		}
		else {
			cout << "공백상태 오류 또는 삭제 위치 오류";
		}
	}

	int getEntry(int pos) {
		return data[pos];
	}
	
	bool find(int item) {
		for (int i = 0; i < length; i++) {
			if (data[i] == item) {
				return true;
			}
		}
		return false;
	}
	void replace(int pos, int e) {
		data[pos] = e;
	}
	int size() {
		return length;
	}
	void display() {
		cout << "[배열로 구현한 리스트 전체 항목수: " << size() << "] : ";
		for (int i = 0; i < size(); i++) {
			cout << "[" << data[i] << "]";
		}
		cout << endl;
	}
	void clear() { length = 0; }
};

int main() {
	ArrayList list;
	list.insert(0, 10);
	list.insert(0, 20);
	list.insert(1, 30);
	list.insert(list.size(), 40);
	list.insert(2, 50);
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, 90);
	list.display();
	list.clear();
	list.display();
}