#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector <int> v;
    
    //7번 도는 동안
    for(int i = 0; i < score.size(); i++){
        v.push_back(score[i]); //값 삽입
        sort(v.begin(), v.end()); //값이 계속 들어와도 정렬
        //넘칠 경우 맨 앞의 수를 지운다.
        //k개 이상일 경우 값이 넘치기 때문에 첫번째 값을 지운다
        if(v.size() > k){
            v.erase(v.begin());
        }
        //그 다음 v의 첫번째 값을 벡터에 넣는다.
        answer.push_back(*v.begin()); 
    }
    
    return answer;
}