#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int fib(int n) {
	if (n == 0) { return 1; }
	if (n == 1) { return 1; }
	return (fib(n - 1) + fib(n - 2));
}

void Push(int n) {
	for (int i = 0; i <= n;i++) {
		v.push_back(fib(i));
	}
}

void Print(int n) {
	cout << "FiBO(" << n << ") = " << 1 << endl;
	for (int i = n; i > 1;i--) {
		cout << "FiBO(" << i-1 << ") = " << *(v.end() - i)<<endl;
	}
	cout << "FiBO(" << 0 << ") = " << fib(n-2) << endl;
	
}

int main() {
	Push(8);
	Print(8);
}