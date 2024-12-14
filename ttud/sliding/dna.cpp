#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen; unordered_set<string> repeat;
    int n = s.size();

    for (int i = 0; i <= n - 10; i++) {
        string sub = s.substr(i, 10);
        if (!seen.insert(sub).second) {
            repeat.insert(sub);
        }
    }

  return vector<string>(repeat.begin(), repeat.end());
}

int main() {
  for (string s : findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")) {
    cout << s << endl;
  }
}