#include <iostream>
#include <vector>
using namespace std;


string answer = "";
string reverse(string n, int len) {

	if (len >= 0){
		answer += n[len]; 
		len--;
		reverse(n, len);
    }
	return answer;
}

int main() {
	cout<< reverse("ABCDE",5);
}