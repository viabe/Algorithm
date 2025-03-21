#include <iostream>
using namespace std;

int main() {
	// 30분안에 문제 풀기 시작 :  2시 7분
	//5킬로와 3킬로를 가지고 있고 정해진 값에서 가장 적게 봉지를 들고 가는 문제
	//그리디 문제
	//우선 5킬로를 최대한 들고 가는게 이득 5로 계속해서 최대한 나누고 
	//아닐 경우 3을 뺀다

	int N;
	cin >> N;//배달해야하는 봉지
	int result =0; //결과적으로 들고갈 봉지

	while (N>=0)
	{
		if(N % 5 == 0){
			result += N / 5;
			cout << result;
			return 0;
		}else{
			N -= 3; //3으로 나누기
			result++;
		}
	}
	cout << "-1";
	
	return 0;
}