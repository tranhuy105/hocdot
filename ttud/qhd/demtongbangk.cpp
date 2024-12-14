

#include <iostream>
#include <vector>
using namespace std;

// Hàm đếm số subsequence có tổng bằng k
int countSubsequencesWithSumK(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Trường hợp tổng bằng 0 luôn có thể đạt được (bằng cách không chọn phần tử nào)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Quy hoạch động
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j]; // Không chọn phần tử nums[i-1]
            if (j >= nums[i - 1]) {
                dp[i][j] += dp[i - 1][j - nums[i - 1]]; // Chọn phần tử nums[i-1]
            }
        }
    }

    return dp[n][k];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int k = 9;
    cout << "Number of subsequences with sum " << k << ": " << countSubsequencesWithSumK(nums, k) << endl;
    return 0;
}
