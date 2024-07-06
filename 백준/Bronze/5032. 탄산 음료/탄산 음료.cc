#include <iostream>
using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;
	int tmp = e + f;
	int result = 0;
	//첫번째는 빈병의 개수로 나오는 새 병, 두번째는 새병을 다시 먹은 수
	while (tmp >=c)
	{
		int newB = tmp / c;
		result += newB;
		tmp = newB + (tmp % c);
	}
	cout << result;
	return 0;
}