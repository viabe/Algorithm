#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string find_leader(int n, vector<string>& names) {
    string leader;
    int max_unique_letters = 0;

    for (const auto& name : names) {
        set<char> unique_letters;
        for (char ch : name) {
            if (isalpha(ch)) {
                unique_letters.insert(ch);
            }
        }

        int unique_count = unique_letters.size();
        if (unique_count > max_unique_letters ||
            (unique_count == max_unique_letters && name < leader)) {
            leader = name;
            max_unique_letters = unique_count;
        }
    }

    return leader;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after the number of test cases

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        cin.ignore(); // Ignore the newline after the number of names

        vector<string> names(N);
        for (int i = 0; i < N; ++i) {
            getline(cin, names[i]);
        }

        string leader = find_leader(N, names);
        cout << "Case #" << t << ": " << leader << endl;
    }

    return 0;
}