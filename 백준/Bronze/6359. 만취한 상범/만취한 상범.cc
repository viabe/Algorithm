#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> n;
		vector<bool> dp(n+1, false); //1라운드는 모두
		for (int a = 1; a <= n; a++) { //a*b에서의 a, 라운드 수
			for (int b = a; b <= n; b += a) { //라운드의 배수
				dp[b] = !dp[b];
			}
		}
		int result = 0;
		for (int i = 1; i <= n; i++) {
			result += dp[i]; // true인 값만 result에 더한다
		}
		cout << result << '\n';
	}
	return 0;
}
