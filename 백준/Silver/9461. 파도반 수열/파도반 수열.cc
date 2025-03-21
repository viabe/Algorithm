#include<iostream>
#include<vector>
using namespace std;

int main(){
    //테스트 케이스의 개수
    int t;
    cin >> t;
    //정삼각형의 변의 길이
    long long n;

    vector <long long> p(n); //배열 선언
    //배열 우선 선언
    p[0] = 0;
    p[1] = p[2] = p[3] = 1;

    for(int i =0; i<t; i++){
        cin >> n;
        for(int j = 3; j<=n; j++){
            //값을 반복해서 사용해야하기 때문에 배열에 저장하기
            p[j] = p[j-3] + p[j-2];
        }
        cout << p[n] << "\n";
    }
}