#include <bits/stdc++.h>
using namespace std;

int n; int W;
vector<int> weights;
vector<int> values;

void input() {
    cin >> n >> W;
    weights.resize(n);
    values.resize(n);

    for (int i = 0; i < n; i++) cin >> weights[i];
    for (int i = 0; i < n; i++) cin >> values[i];
}

int f() {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) { // Duyệt ngược để tránh ghi đè
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

int main() {
    input();
    cout << f() << endl;
    return 0;
}