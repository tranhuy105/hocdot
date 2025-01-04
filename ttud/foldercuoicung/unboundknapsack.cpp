#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> weights, values;

void input() {
    cin >> n >> W;
    weights.resize(n);
    values.resize(n);

    for (int i = 0; i < n; i++) cin >> weights[i];
    for (int i = 0; i < n; i++) cin >> values[i];
}

int f() {
    vector<int> dp(W + 1, 0); // Khởi tạo dp với giá trị 0

    for (int i = 0; i < n; i++) { // Duyệt qua từng đồ vật
        for (int w = weights[i]; w <= W; w++) { // Duyệt trọng lượng xuôi
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    for (int it : dp) cout << it << " ";
    cout << endl;
    return dp[W];
}

int main() {
    input();
    cout << f() << endl;
    return 0;
}
