#include <queue>
#include <functional>
using namespace std;

void hearSortDec(int a[], int n) {
	priority_queue<int> maxHeap;

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