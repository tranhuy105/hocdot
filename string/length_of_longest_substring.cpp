#include <iostream>
#include <string>
#include <limits.h>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int left = 0;
    unordered_set<char> charSet;
    int res = 0;

    for (int right = 0; right < s.size(); right++) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        res = max(res, right - left + 1);
    }
    
    return res;
}

int main() {
    cout << lengthOfLongestSubstring("aab") << endl;
    return 0;
}