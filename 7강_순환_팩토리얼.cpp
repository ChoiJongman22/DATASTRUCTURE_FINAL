#include <iostream>

using namespace std;

//순환적인 팩토리얼 계산프로그램
int factorial(int n) {
	cout << "factorial(" << n << ")" << endl;
	if (n == 1) return 1;
	else return (n * factorial(n - 1));
}


//반복적인 팩토리얼 계산프로그램
int factorialIter(int n) {
	int result = 1;
	for (int k = n; k > 0; k--) {
		result *= k;
	}
	return result;
}
