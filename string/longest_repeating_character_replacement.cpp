#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k) {
    int left = 0;
    int maxLength = 0, maxCount = 0;
    unordered_map<char, int> frequencyMap;

    for (int right = 0; right < s.size(); right++) {
        frequencyMap[s[right]]++;
        maxCount = max(maxCount, frequencyMap[s[right]]);

        while ((right - left + 1) - maxCount > k) {
            frequencyMap[s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }    

    return maxLength;
}

int main() {
    cout << characterReplacement("ABAB", 2) << endl;;
    return 0;
}