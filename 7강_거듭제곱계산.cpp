#include <iostream>

using namespace std;

//반복적인 거듭제곱 계산 프로그램
double slowPower(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

//순환적인 거듭제곱 게산 프로그램

double Power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) {
		return Power(x * x, n / 2);
	}
	else {
		return x * Power(x * x, (n - 1 )/ 2);
	}
}