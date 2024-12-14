#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroup;

    for (string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroup[sortedStr].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto& group : anagramGroup) {
        ans.push_back(group.second);
    }   

    return ans;
}

int main() {
    vector<string> strs = {"a","a"};
    auto ans = groupAnagrams(strs);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}