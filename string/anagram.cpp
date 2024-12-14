#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    for (char c : t) {
        if (count[c] == 0) return false;
        count[c]--;
    }
    return true;
}

int main() {
    vector<int> arr = {1,2,3,1000000000};
    cout << isAnagram("hello", "nguuu") << endl;
    return 0;
}