#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i * 2<=n; i++){
        answer += i * 2;
    }
    return answer;
}