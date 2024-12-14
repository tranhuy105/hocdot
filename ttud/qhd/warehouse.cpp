/*
Đề bài:
Một xe tải cần đến các trạm trong số `N` trạm (1, 2, ..., N) nằm trên một đường thẳng. Mỗi trạm `i` có:
- `ai`: lượng hàng hóa tại trạm.
- `ti`: thời gian cần thiết để lấy hàng tại trạm.

Yêu cầu:
- Lộ trình xe tải là một dãy các trạm tăng dần `x1 < x2 < ... < xk` (1 ≤ xj ≤ N).
- Khoảng cách giữa hai trạm liên tiếp không vượt quá `D`.
- Tổng thời gian lấy hàng không vượt quá `T`.

Nhiệm vụ:
Tìm tổng lượng hàng hóa lớn nhất mà xe tải có thể lấy được.

Đầu vào:
- Dòng 1: `N`, `T`, `D` (1 ≤ N ≤ 1000, 1 ≤ T ≤ 100, 1 ≤ D ≤ 10).
- Dòng 2: `a1, ..., aN` (1 ≤ ai ≤ 10): lượng hàng hóa tại mỗi trạm.
- Dòng 3: `t1, ..., tN` (1 ≤ ti ≤ 10): thời gian lấy hàng tại mỗi trạm.

Đầu ra:
- Một số nguyên duy nhất là tổng lượng hàng hóa lớn nhất mà xe tải có thể lấy được.

Ví dụ:
Input:
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2

Output:
24

Giải thích:
- Lộ trình tối ưu: chọn trạm 1 (6 hàng, 1 thời gian), trạm 3 (5 hàng, 2 thời gian), trạm 5 (11 hàng, 3 thời gian).
- Tổng hàng hóa: 6 + 5 + 11 = 24.
- Tổng thời gian: 1 + 2 + 3 = 6 (không vượt quá T).
*/


#include <bits/stdc++.h>
using namespace std;

int n; int T; int D;
vector<int> a; vector<int> t;

void solve() {
    vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));
    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int k = 1; k <= T; k++) {
            dp[i][k] = dp[i-1][k];
            if (k >= t[i]) {
                for (int j = max(0, i - D); j < i; j++) {
                    dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
                }
                res = max(res, dp[i][k]);
            }
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
