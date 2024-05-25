#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
#include <stdlib.h>

using namespace std;

int year, month, day, total;
 map <char, int> tMap; // 문자열 숫자로 바꿔서 넣을 맵
vector<int> v; // 계산한 날짜 결과를 넣을 배열

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer; // 출력할 배열
    
    //날짜 계산
    year = stoi(today.substr(0,4));
    month = stoi(today.substr(5,2));
    day = stoi(today.substr(8,2)); //2020.01.01
    
    total = year * 12 * 28 + (month -1) * 28 + day;
    
    //약관 자르기
    for(int i =0; i < terms.size(); i++){
        stringstream ss(terms[i]);
        char alpha;
        int months;
        ss >> alpha >> months;
        tMap[alpha] = months;
    }
    
    //날씨 계산하기
    for(int i =0; i< privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5,2));
        int d = stoi(privacies[i].substr(8,2));
        char a = privacies[i].back();
        
        int tmp = y * 12 * 28 + (m-1) * 28 + d + (tMap[a] * 28 -1);
        
        v.push_back (tmp);
    }
    
    //비교
    for(int i =0; i< v.size(); i++){
        if(v[i] < total){ //만약 today보다 수가 클 경우
            answer.push_back(i + 1);
        }
    }

    return answer;
}