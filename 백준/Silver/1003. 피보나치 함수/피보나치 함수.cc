#include<iostream>
using namespace std;

long long dp[41] = {0, 1,}; //dp 배열 초기화, dp[0] = 0, dp[1] = 1로 초기화 

//피보나치를 0과 1로 쪼개는 함수
int fibonacci(int n) {

     // 이미 계산된 값을 확인하여 중복 계산 방지
    if (dp[n] || n == 0) {
        return dp[n];
    } else { // 1과 0이 아닐 경우
        dp[n] = fibonacci(n-1) + fibonacci(n-2);
    }

    return dp[n];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //테스트 케이스 수
    int t;
    cin >> t;

    for(int i =0; i<t; i++){
        int n;
        cin >>n;
        fibonacci(n);

        if(n == 0){
            cout << "1" << ' ' << "0" <<'\n';
        }
        else{
            //0이 출력되는 횟수는 fibo(n-1), 1은 fibo(0)이다.
            cout << fibonacci(n-1) << " "<< fibonacci(n) <<"\n";
        }
    }

    return 0;
}