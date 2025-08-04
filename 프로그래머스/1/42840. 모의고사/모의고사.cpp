#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//수포자 1의 1,2,3,4,5 패턴 반복
//수포자 2 패턴 : 2, 1, 2, 3, 2, 4, 2, 5 패턴 반복
//수포자 3 패턴 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 패턴 반복
//완전 탐색

//수포자 1, 2, 3의 패턴이 들어간 배열을 answer과 일일히 비교하고 만약 겹친다면 ++하기. 그래서 값이 큰 걸 return

vector<int> math1= {1,2,3,4,5};
vector<int> math2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> math3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> math(3); //수포자들의 맞은 답을 넣을 배열
    
    for(int i = 0; i<answers.size(); i++){
        if(answers[i] == math1[i%math1.size()]){
            math[0]++;
        }
        
        if(answers[i] == math2[i%math2.size()]){
            math[1]++;
        }
        
        if(answers[i] == math3[i%math3.size()]){
            math[2]++;
        }
        
    }
    
    //가장 큰 점수
    int maxScore = *max_element(math.begin(), math.end());
    for(int i = 0; i<3; i++){
        if(math[i] == maxScore){
            answer.push_back(i+1); //가장 큰 점수를 가진 수포자 번호들을 넣기
        }
    }

    
    return answer;
}