#include <bits/stdc++.h>
using namespace std;

int n; int T; int D;
vector<int> a; vector<int> t;

void solve() {
    vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));
    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int k = t[i]; k <= T; k++) {
           for (int j = max(0, i - D); j < i; j++) {
                dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
            }
            res = max(res, dp[i][k]);
        }
    }

    cout << res << endl;
}

int main() {
    cin >> n >> T >> D;
    a.resize(n+1); t.resize(n+1);
    for (int i = 1; i <=n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    solve();
    return 0;
}
