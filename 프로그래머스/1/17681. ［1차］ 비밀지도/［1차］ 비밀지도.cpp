#include <string>
#include <vector>
#include<iostream>
#include <bitset> // 이진수 변환을 하기 위해서

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<string> temp(n);
    
    //10진수를 2진수로 바꾸기
    for (int i = 0; i<n; i++)
    {
		    //OR 연산을 써서 16자리를 합친 다음
        bitset<16> maprow = bitset<16> (arr1[i]) | bitset<16> (arr2[i]);
        //문자열로 만들고 16-n을 해서 자르기
        temp[i] = maprow.to_string().substr(16-n);
    }
    //지도를 #으로 변환
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(temp[i][j] != '0'){
                //0이 아니면 그자리에 # 넣기
                answer[i]=answer[i]+'#';
            }
            else{
		            //0일 경우 띄어쓰기
                answer[i]=answer[i]+' ';
            }
        }
    }
    
    return answer;
}