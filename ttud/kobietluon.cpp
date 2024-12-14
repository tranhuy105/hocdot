#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Đề bài:
Cho một mảng số nguyên `nums` và một số nguyên `target`, tìm số lượng các subsequence (dãy con không liền kề) 
mà tổng của phần tử nhỏ nhất và lớn nhất trong dãy nhỏ hơn hoặc bằng `target`. 
Do kết quả có thể rất lớn, trả về kết quả theo modulo 10^9 + 7.
*/

const int MOD = 1e9 + 7;

// Hàm tính số lượng subsequence thỏa mãn điều kiện
int numSubseq(vector<int>& nums, int target) {
    int n = nums.size();

    // Bước 1: Sắp xếp mảng
    sort(nums.begin(), nums.end());

    // Bước 2: Tiền tính lũy thừa của 2 theo modulo MOD
    vector<int> power_of_2(n, 1);
    for (int i = 1; i < n; ++i) {
        power_of_2[i] = (power_of_2[i - 1] * 2) % MOD;
    }

    int left = 0, right = n - 1;
    int result = 0;

    // Bước 3: Dùng hai con trỏ để duyệt mảng
    while (left <= right) {
        // Nếu tổng của phần tử nhỏ nhất và lớn nhất <= target
        if (nums[left] + nums[right] <= target) {
            // Thêm tất cả subsequence có thể từ left đến right
            result = (result + power_of_2[right - left]) % MOD;
            ++left; // Dịch con trỏ trái sang phải
        } else {
            // Nếu tổng vượt quá target, giảm con trỏ phải
            --right;
        }
    }

    return result;
}

int main() {
    // Dữ liệu đầu vào
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    // Tính kết quả và in ra màn hình
    int result = numSubseq(nums, target);
    cout << "Số lượng subsequence thỏa mãn: " << result << endl;

    return 0;
}
