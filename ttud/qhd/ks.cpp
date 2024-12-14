#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Bài toán "Knapsack 0/1":
Cho `n` đồ vật, mỗi đồ vật có trọng lượng `w[i]` và giá trị `v[i]`. Có một cái túi có sức chứa tối đa là `S`. Nhiệm vụ là chọn một số lượng đồ vật sao cho tổng trọng lượng không vượt quá `S` và tổng giá trị là lớn nhất.

Đầu vào:
- Số nguyên `n` (số lượng đồ vật) và `S` (sức chứa của túi).
- Hai mảng:
  - `w[i]` (trọng lượng của đồ vật thứ i).
  - `v[i]` (giá trị của đồ vật thứ i).

Đầu ra:
- Một số nguyên biểu thị tổng giá trị lớn nhất có thể đạt được.

Ví dụ:
Input:
4 5
2 3 4 2
3 4 5 6

Output:
10

Giải thích:
- Với `n = 4` đồ vật và sức chứa túi `S = 5`:
  - Chọn đồ vật thứ 2 (trọng lượng 3, giá trị 4) và thứ 4 (trọng lượng 2, giá trị 6).
  - Tổng giá trị = 4 + 6 = 10.

Hướng dẫn giải:
1. **Dynamic Programming (Quy hoạch động):**
   - Định nghĩa `dp[i][j]`: Giá trị lớn nhất có thể đạt được khi xét các đồ vật từ 1 đến `i` và sức chứa túi là `j`.
   - Khởi tạo:
     - `dp[i][0] = 0` (không thể đạt được giá trị nào nếu sức chứa túi là 0).
     - `dp[0][j] = 0` (không có giá trị nào nếu không có đồ vật nào để chọn).
   - Công thức chuyển:
     - Không chọn đồ vật thứ `i`: `dp[i][j] = dp[i-1][j]`.
     - Chọn đồ vật thứ `i`: `dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i])` nếu `w[i] <= j`.
   - Kết quả: `dp[n][S]`.

2. **Độ phức tạp:**
   - Thời gian: O(n * S), với `n` là số lượng đồ vật và `S` là sức chứa.
   - Không gian: O(n * S) để lưu bảng `dp`.

Cải tiến:
- Có thể tối ưu không gian xuống O(S) bằng cách sử dụng mảng 1 chiều `dp`:
  - Duyệt ngược `j` để tránh ghi đè dữ liệu.
*/


int main() {
    int n, S; cin >> n >> S;
    vector<vector<int>> dp(n+1, vector<int>(S+1, 0));
    vector<int> w (n+1);
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            dp[i][j] = dp[i-1][j];
            if (w[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][S] << endl;
    return 0;
}