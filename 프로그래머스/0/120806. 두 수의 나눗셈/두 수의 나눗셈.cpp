#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num1, int num2) {
    float answer = static_cast<float> (num1) / num2;
    answer = answer * 1000;
    return answer;
}