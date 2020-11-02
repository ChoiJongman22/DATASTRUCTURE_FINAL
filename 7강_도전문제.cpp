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
	Push(10);
	Print(10);
}

#include <iostream>

using namespace std;



//순환적인 피보나치수열 계산 프로그램

//int fibonacci(int* count, int n)
//
//{
//
//    count[n]++;
//
//    if (n == 0)
//
//        return 0;
//
//    if (n == 1)
//
//        return 1;
//
//    return (fibonacci(count, n - 1) + fibonacci(count, n - 2));
//
//}
//
//
//
//int main(void)
//
//{
//
//    int num;
//
//    cout << "몇번 째 피보나치 수열을 확인하고 싶으십니까 >";
//
//    cin >> num;
//
//    int* count = new int[num + 1];
//
//    for (int i = 0; i < num + 1; i++)
//
//        count[i] = 0; //초기화
//
//    cout << num << "번째 피보나치 수열 숫자: " << fibonacci(count, num) << endl;
//
//    for (int i = num; i >= 0; i--)
//
//        cout << "fibonnaci(" << i << ") = " << count[i] << "번" << endl;
//
//    delete[]count; //동적할당한 메모리 반환
//
//    return 0;
//
//}


