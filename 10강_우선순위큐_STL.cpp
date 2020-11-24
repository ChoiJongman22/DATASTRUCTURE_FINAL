#include <queue>
#include <functional>
#include <iostream>
using namespace std;

void heapSortDec(int a[], int n) {
	priority_queue<int> maxHeap;
	for (int i = 0; i < n; i++) {
		maxHeap.push(a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		a[i] = maxHeap.top();
		maxHeap.pop();
	}
	
}

void heapSortInc(int a[], int n) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < n; i++) {
		minHeap.push(a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = minHeap.top();
		minHeap.pop();
	}
}

int main() {
	int data[10] = { 10,21,5,76,22,44,21,6,90,1 };
	heapSortDec(data, 10);
	for (int i = 0; i < 10; i++) {
		cout << data[i]<<" ";
	}

}