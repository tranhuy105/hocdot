#include <iostream>
#include <vector>
using namespace std;

// Hàm kiểm tra xem có subsequence nào có tổng bằng k hay không
bool hasSubsequenceWithSumK(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    
    // Trường hợp tổng bằng 0 luôn có thể đạt được (bằng cách không chọn phần tử nào)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Quy hoạch động
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j]; // Không chọn phần tử nums[i-1]
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // Chọn phần tử nums[i-1]
            }
        }
    }

    return dp[n][k];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int k = 9;
    cout << (hasSubsequenceWithSumK(nums, k) ? "YES" : "NO") << endl;
    return 0;
}
