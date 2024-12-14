#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tìm dãy con có tổng bằng k với số lượng phần tử lớn nhất
void findLargestSubsequenceWithSumK(const vector<int>& nums, int k) {
    int n = nums.size();
    // dp[i][j] lưu trữ số lượng phần tử lớn nhất của dãy con có tổng bằng j khi xét đến phần tử thứ i
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    // Khởi tạo: Tổng bằng 0 luôn đạt được với 0 phần tử
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; // Không chọn phần tử nào để đạt tổng 0
    }

    // Quy hoạch động
    for (int i = 1; i <= n; i++) { // Duyệt qua các phần tử từ 1 đến n
        for (int j = 0; j <= k; j++) { // Duyệt qua các giá trị tổng từ 0 đến k
            // Không chọn phần tử nums[i-1]
            dp[i][j] = dp[i-1][j];

            // Nếu chọn phần tử nums[i-1] và tổng j đủ lớn để chọn
            if (j >= nums[i-1] && dp[i-1][j - nums[i-1]] != -1) {
                // Cập nhật giá trị lớn nhất giữa việc chọn và không chọn nums[i-1]
                dp[i][j] = max(dp[i][j], dp[i-1][j - nums[i-1]] + 1);
            }
        }
    }

    // Kiểm tra nếu không thể đạt được tổng k
    if (dp[n][k] == -1) {
        cout << "No subsequence with sum " << k << endl;
        return;
    }

    // In số lượng phần tử lớn nhất trong dãy con có tổng bằng k
    cout << "Maximum length of subsequence with sum " << k << ": " << dp[n][k] << endl;

    // Truy vết để tìm dãy con
    vector<int> subsequence; // Lưu trữ dãy con
    int i = n, j = k; // Bắt đầu từ trạng thái cuối cùng dp[n][k]

    while (i > 0 && j > 0) {
        // Kiểm tra xem phần tử nums[i-1] có được chọn hay không, kiểm tra trạng thái trước có tồn tại hay k
        if (dp[i][j] != dp[i-1][j]) {
            subsequence.push_back(nums[i-1]); // Thêm phần tử vào dãy con
            j -= nums[i-1]; // Giảm tổng theo phần tử đã chọn
        }
        i--; // Di chuyển lên phần tử trước đó
    }

    // Đảo ngược dãy con để trả về thứ tự chính xác
    reverse(subsequence.begin(), subsequence.end());

    // In dãy con
    cout << "Subsequence: ";
    for (int num : subsequence) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Dữ liệu đầu vào: mảng nums và tổng cần kiểm tra k
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int k = 9;

    // Gọi hàm tìm kiếm dãy con
    findLargestSubsequenceWithSumK(nums, k);

    return 0;
}
