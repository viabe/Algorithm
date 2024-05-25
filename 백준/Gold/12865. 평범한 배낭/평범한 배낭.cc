#include <iostream>
#include <vector>
using namespace std;

//구조체, 배낭에 넣을 물건의 가치와 무게
struct bagp{
    int weight; //물건의 무게
    int value; //물건의 가치
};

int main(){
    int n, k; //물품의 수와 준서가 버틸 수 잇는 무게
    cin >> n>>k;

    vector<bagp> b(n); //구조체 기반의 벡터
    
    //배열 입력
    for(int i =0; i< n; i++){
        cin >> b[i].weight >> b[i].value;
    }
    
    //값 구하기
    vector <int> dp(k+1, 0); //dp배열 선언, k+1 즉 무게의 크기 +1 로 배열 크기 선언
    //dp 배열 갱신
    for(int i =0; i<n; i++){//물건 번호
        for(int j = k; j >= b[i].weight; j--) { //현재 배낭의 무게를 거꾸로 순회
            dp[j] = max(dp[j], dp[j - b[i].weight] + b[i].value); //상태 업데이트
        }
    }

    cout << dp[k];
    return 0;
}