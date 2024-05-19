#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct sta{
    int indexNum; //인덱스 넘버
    double failNumber; //스테이지마다의 실패율
};

// 내림차순으로 수 정리
bool compare(sta a, sta b) {
    if (a.failNumber == b.failNumber) {
        return a.indexNum < b.indexNum; // 실패율이 같을 경우 스테이지 번호가 작은 순으로 정렬
    }
    return a.failNumber > b.failNumber; // 실패율 내림차순 정렬
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N); //결과를 출력할 배열
    
    //임시로 값을 담을 배열, 여기서 값이란 같은 수의 개수이다.
    vector<int> arr(N+2, 0);
    
    //우선 배열을 정렬한 후 이분 탐색으로 같은 수의 개수를 찾는다.
    sort(stages.begin(), stages.end()); //수 정렬
    
    int num = 0; //임시 변수
    
    //정렬한 수에서 같은 수의 개수를 구해서 값을 배열에 넣은다.
    //N+1은 스테이지를 해결한 경우가 있을 수 있기 때문이다.
    for(int i =0; i<= N; i++){
        auto a = lower_bound(stages.begin(), stages.end(), i+1);
        auto b = upper_bound(stages.begin(), stages.end(), i+1);
        //중복되는 수 arr배열에 넣기
        arr[i] = b - a;
        //cout << arr[num] << " ";
        //num++;
    }
    
    //첫 실패율을 구하기위한 스테이지 도달한 플레이어 수 구하기
    int failNum = stages.size();
    
    //각각 스테이지의 실패율 구하기
    //두개의 값을 넣을 수 있는 벡터
    vector <sta> player(N); //구조체 형식의 배열
    
    for(int i =0; i < N; i++){
        player[i].indexNum = i+1; //스테이지 번호 넣기
        if (failNum == 0) {
            player[i].failNumber = 0.0; // 남은 인원이 없을 경우 실패율 0으로 설정
        } else
        {
            player[i].failNumber = static_cast<double>(arr[i]) / static_cast<double>(failNum);   
        }
        
        //실패율 구해서 넣기, 자료형 int로 나누면 0으로 계산되기 때문에 static_cast<double>를 붙여서 계산해야한다.
        failNum -= arr[i]; //전 스테이지 인원수 빼기
    }
    
    //내림차순으로 정렬하기
    sort(player.begin(), player.end(), compare);
    
    for(int i = 0; i< N; i++){
        answer[i] = player[i].indexNum;
        cout << answer[i] << " ";
    }
    
    return answer;
}