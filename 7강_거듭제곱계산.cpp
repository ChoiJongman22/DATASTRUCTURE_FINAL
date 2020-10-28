#include <iostream>

using namespace std;

//�ݺ����� �ŵ����� ��� ���α׷�
double slowPower(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

//��ȯ���� �ŵ����� �Ի� ���α׷�

double Power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) {
		return Power(x * x, n / 2);
	}
	else {
		return x * Power(x * x, (n - 1 )/ 2);
	}
}