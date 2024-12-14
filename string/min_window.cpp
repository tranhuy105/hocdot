#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    int left = 0; int minLength = INT_MAX; int formed = 0; int start = 0;
    unordered_map<char, int> tFreq, windowFreq;

    for (char c : t) {
        tFreq[c]++;
    }

    int required = tFreq.size();

    for (int right = 0; right < s.size(); right++) {
        windowFreq[s[right]]++;
        if (tFreq.find(s[right]) != tFreq.end() && windowFreq[s[right]] == tFreq[s[right]]) {
            formed++;
        }

        while (left <= right && formed == required) {
            char charLeft = s[left];
            
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }

            windowFreq[s[left]]--;
            if (tFreq.find(charLeft) != tFreq.end() && windowFreq[s[left]] < tFreq[s[left]]) {
                formed--;
            }
            left++;
        }
    }

    return minLength == INT_MAX ? "" : s.substr(start, minLength);
}

int main() {
    cout << minWindow("aa", "aa") << endl;
    return 0;
}