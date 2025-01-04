#include <bits/stdc++.h>
using namespace std;


bool checkPosition(int i, int j, vector<pair<int, pair<int, int>>>& v) {
    pair<int, int> posI = v[i].second;
    pair<int, int> posJ = v[j].second;

    return abs(posI.first - posJ.first) + abs(posI.second - posJ.second) == 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v.push_back({matrix[i][j], {i, j}});
        }
    }    

    sort(v.begin(), v.end());
    vector<int> dp(m*n , 1);
    int l = m * n;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].first > v[j].first && checkPosition(i, j, v)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());

}

int main() {
    return 0;
}