#include <iostream>
using namespace std;

//1��

int recursive(int n) {
	if (n == 1) return 1;
	return n * recursive(n - 1);
}

//2��
int recursive2(int n) {
	cout << n << endl;
	if (n == 1) return 1;
	return n * recursive2(n - 1);
}

//3��
int sum(int n) {
	cout << n << endl;
	if (n < 1) return 0;
	else return (n + sum(n - 1));
}
//4��

void asterisk(int i) {
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	cout << "*";
}


//5�� 

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
//	cout << "n�� �Է�: ";
//	cin >> num;
//	cout << "1���� " << num << "���� ���� ���: " << Sum(num) << endl;
//	return 0;
//}


//6�� 

double Sum2(int n) //�м��̹Ƿ�
{
	if (n == 1)
		return 1;
	else
		return (1 / (double)n) + Sum2(n - 1);
}



int main(void)
{
	int num;
	cout << "n �� �Է�: ";
	cin >> num;
	cout << "1���� 1/" << num << "������ �� ���: " << Sum2(num) << endl;
	return 0;
}


//int main() {
//	//cout << recursive(5); //1��
//	//cout<<recursive2(5); //2��
//	//cout << sum(5); //3��
//	//asterisk(5); //4��
//}