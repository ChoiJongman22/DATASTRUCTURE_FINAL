#include <iostream>

using namespace std;

//��ȯ���� ���丮�� ������α׷�
int factorial(int n) {
	cout << "factorial(" << n << ")" << endl;
	if (n == 1) return 1;
	else return (n * factorial(n - 1));
}


//�ݺ����� ���丮�� ������α׷�
int factorialIter(int n) {
	int result = 1;
	for (int k = n; k > 0; k--) {
		result *= k;
	}
	return result;
}
