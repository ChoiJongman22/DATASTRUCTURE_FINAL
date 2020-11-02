#include <iostream>
using namespace std;

//1번

int recursive(int n) {
	if (n == 1) return 1;
	return n * recursive(n - 1);
}

//2번
int recursive2(int n) {
	cout << n << endl;
	if (n == 1) return 1;
	return n * recursive2(n - 1);
}

//3번
int sum(int n) {
	cout << n << endl;
	if (n < 1) return 0;
	else return (n + sum(n - 1));
}
//4번

void asterisk(int i) {
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	cout << "*";
}


//5번 

int Sum(int n)
{
	if (n == 1)
		return 1;
	else
		return n + Sum(n - 1);
}

//int main(void)
//{
//	int num;
//	cout << "n값 입력: ";
//	cin >> num;
//	cout << "1부터 " << num << "까지 더한 결과: " << Sum(num) << endl;
//	return 0;
//}


//6번 

double Sum2(int n) //분수이므로
{
	if (n == 1)
		return 1;
	else
		return (1 / (double)n) + Sum2(n - 1);
}



int main(void)
{
	int num;
	cout << "n 값 입력: ";
	cin >> num;
	cout << "1부터 1/" << num << "까지의 합 결과: " << Sum2(num) << endl;
	return 0;
}


//int main() {
//	//cout << recursive(5); //1번
//	//cout<<recursive2(5); //2번
//	//cout << sum(5); //3번
//	//asterisk(5); //4번
//}