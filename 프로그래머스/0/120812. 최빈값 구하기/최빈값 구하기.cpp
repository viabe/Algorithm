#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int solution(vector<int> array) {
    int answer = 0; //최빈값을 넣을 변수

    //STL을 이용한 이진탐색
    //최빈값 : N개의 수들 중 가장 많이 나타나는 값
    
    //배열 정리
    sort(array.begin(), array.end());

    int maxCount = 0; //최빈값의 최대 개수를 갱신할 변수
    int mode = array[0]; //최빈값을 넣을 변수
    bool modeCount = false; //같은 개수의 최빈값이 또 있는지를 확인하기 위한 변수

    for (int i = 0; i < array.size();) {
        //이진 탐색을 이용해서 array[i]의 개수 찾기
        int count = upper_bound(array.begin(), array.end(), array[i]) - lower_bound(array.begin(), array.end(), array[i]);
        //만약 array[i]의 갯수가 maxCount보다 크다면 그 값을 넣는다.
        if (count > maxCount) { //빈도수가 클 경우 mode와 maxCount 업데이트
            maxCount = count; //최빈 값 갱신
            mode = array[i]; //i의 값은 i++같은 규칙성으로 올라가지 않기 때문에 이 변수가 필요
            modeCount = false; // 새로운 최빈값이 갱신되었으므로 초기화
        } 
        //만약 같은 개수의 최빈값들이 있다면 return -1 하기
        else if (count == maxCount) {
            modeCount = true;
        }
        i += count; //같은 숫자 건너뛰기
    }

    if (modeCount == false) {
        answer = mode;
    }
    else {
        return -1;
    }

    return answer;

}