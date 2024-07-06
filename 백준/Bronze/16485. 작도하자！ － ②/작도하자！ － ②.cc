#include<iostream>
#include <iomanip> // setprecision을 사용하기 위해 필요
using namespace std;

int main() {
	double c, b;
	cin >> c >> b;
	cout << fixed << setprecision(10); //소수점 아래 숫자의 출력범위 설정

	cout << c / b;
	return 0;
}