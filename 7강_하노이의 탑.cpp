#include <iostream>

using namespace std;

void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1)cout << "원판1을 " << from << "를 " << to << "으로 옮긴다." << endl;
	else {
		hanoiTower(n - 1, from, to, tmp);
		cout << "원판" << n << "을(를) " << from << "에서 " << to << "으로 옮긴다." << endl;
		hanoiTower(n - 1, tmp, from, to);
	}
}
void main() {
	hanoiTower(4, 'A', 'B', 'C');
}