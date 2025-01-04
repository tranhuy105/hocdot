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

const int maxn = 1004;
int N; int T; int D;
int a[maxn];
int t[maxn];

void inp() {
    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> t[i];
}

int maxAmount() {
    // dp[i][w]: tổng số hàng hóa lấy được lớn nhất nếu kết thúc hành trình tại trạm i, với tải trọng còn là w;
    vector<vector<int>> dp(N+1, vector<int>(T+1, 0));
    int res = 0;

    for (int i = 1; i <= N; i++) {
        for (int w = T; w >= t[i]; w--) {
            for (int j = max(0, i - D); j < i; j++) {
                dp[i][w] = max(dp[i][w], dp[j][w-t[i]] + a[i]);
            }
            res = max(res, dp[i][w]);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    inp();
    cout << maxAmount() << endl;
    return 0;
}