#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Cho một danh sách các mệnh giá tiền xu `coins` và một số nguyên `amount`. Nhiệm vụ là tìm số lượng đồng xu tối thiểu cần sử dụng để tổng giá trị bằng `amount`. Nếu không thể tạo được tổng `amount` bằng các đồng xu, trả về `-1`.

Đầu vào:
- Một vector số nguyên `coins` đại diện cho các mệnh giá tiền xu.
- Một số nguyên `amount` đại diện cho tổng cần tạo.

Đầu ra:
- Một số nguyên biểu thị số lượng đồng xu tối thiểu cần để tạo tổng bằng `amount`, hoặc `-1` nếu không thể.

Ví dụ:
Input:
coins = {1, 2, 5}
amount = 11

Output:
3

Giải thích:
- Sử dụng 3 đồng xu với giá trị {5, 5, 1}.

Hướng dẫn giải:
1. **Dynamic Programming (Quy hoạch động):**
   - Định nghĩa `dp[i][j]`: Số lượng đồng xu tối thiểu để tạo ra tổng `j` khi sử dụng các đồng xu từ `1` đến `i`.
   - Khởi tạo:
     - `dp[i][0] = 0` (không cần đồng xu nào để tạo tổng 0).
     - `dp[i][j] = INT_MAX` với các giá trị không khả thi.
   - Công thức chuyển:
     - Không chọn đồng xu thứ `i`: `dp[i][j] = dp[i-1][j]`.
     - Chọn đồng xu thứ `i`: `dp[i][j] = dp[i][j - coins[i-1]] + 1` nếu khả thi.
   - Kết quả: `dp[n][amount]` (nếu khả thi), ngược lại trả về `-1`.

2. **Độ phức tạp:**
   - Thời gian: O(n * amount), với `n` là số lượng mệnh giá tiền xu và `amount` là tổng cần tạo.
   - Không gian: O(n * amount) để lưu bảng `dp`.

Cải tiến:
- Có thể tối ưu không gian xuống O(amount) bằng cách chỉ sử dụng một mảng 1 chiều `dp`:
  - Cập nhật `dp[j]` tại mỗi bước với các giá trị `coins[i]`.
*/

    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[i][j]: độ dài ngắn nhất khi dùng đồng xu từ 1 đến i với cái túi j
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            int coin = coins[i-1];
            // j là các độ rộng tối,
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i-1][j];
                // Kiểm tra nếu j - coin khả thi (không phải trạng thái không thể INT_MAX)
                if (j >= coin && dp[i][j - coin] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i][j - coin] + 1);  // Taking the coin
                }
            }
        }

        return dp[n][amount] != INT_MAX ? dp[n][amount] : -1;
    }