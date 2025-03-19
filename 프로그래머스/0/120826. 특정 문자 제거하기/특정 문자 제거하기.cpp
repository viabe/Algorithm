#include <string>
#include <vector>

using namespace std;

string solution(string str, string letter) {
    string answer = "";
    for(int i =0; i<str.length(); i++){
        if(str[i] != letter[0]){
            answer += str[i];
        }
    }
    return answer;
}