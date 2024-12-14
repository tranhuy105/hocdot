#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Đề bài:
Tìm cặp (i, j) sao cho:
nums[i] + nums[j] < K
và giá trị tổng nums[i] + nums[j] là lớn nhất.

Ý tưởng:
1. Sắp xếp mảng để sử dụng hai con trỏ.
2. Dùng hai con trỏ `left` và `right`:
   - Nếu nums[left] + nums[right] < K:
     + Cập nhật giá trị tổng lớn nhất.
     + Tăng `left` để thử giá trị lớn hơn.
   - Nếu nums[left] + nums[right] >= K:
     + Giảm `right` để giảm tổng.
3. Trả về tổng lớn nhất thỏa mãn điều kiện.

Đầu vào:
- Một mảng số nguyên `nums` và số nguyên `K`.

Đầu ra:
- Tổng lớn nhất của cặp nums[i] + nums[j] sao cho tổng < K.

Ví dụ:
Input: nums = [2, 7, 11, 15], K = 17
Output: 16
Giải thích:
Cặp thỏa mãn là (7, 9), tổng = 16.
*/

int maxSumLessThanK(vector<int>& nums, int K) {
    sort(nums.begin(), nums.end()); // Bước 1: Sắp xếp mảng
    int left = 0, right = nums.size() - 1;
    int maxSum = -1; // Khởi tạo tổng lớn nhất (giả định không có cặp nào thỏa mãn)

    while (left < right) {
        int currentSum = nums[left] + nums[right];

        if (currentSum < K) {
            maxSum = max(maxSum, currentSum); // Cập nhật tổng lớn nhất
            left++; // Tăng `left` để kiểm tra cặp khác với tổng lớn hơn
        } else {
            right--; // Giảm `right` để kiểm tra cặp khác với tổng nhỏ hơn
        }
    }

    return maxSum; // Trả về tổng lớn nhất
}

int main() {
    vector<int> nums = {2, 7, 11, 15}; // Input mảng
    int K = 17; // Giá trị K
    cout << "Tổng lớn nhất của cặp nhỏ hơn " << K << ": " << maxSumLessThanK(nums, K) << endl; // Output: 16
    return 0;
}
