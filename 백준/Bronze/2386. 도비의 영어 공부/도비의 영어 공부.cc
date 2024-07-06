#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string line;

    while (getline(cin, line) && line != "#") {
        char target = line[0];
        string sentence = line.substr(2); // 공백을 제외한 문장 부분 추출

        target = tolower(target); // 소문자로 변환

        int count = 0;
        for (char ch : sentence) {
            if (tolower(ch) == target) {
                count++;
            }
        }

        cout << target << " " << count << endl;
    }

    return 0;
}
