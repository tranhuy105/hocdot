#include <iostream>
#include <vector>

using namespace std;

/*
Đề bài:
- Cho một mảng số nguyên dương `nums` và một số nguyên dương `k`.
- Tìm số lượng các dãy con liên tiếp (subarray) có tích của các phần tử nhỏ hơn `k`.

Ví dụ:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Giải thích: Các dãy con thỏa mãn là:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].

Ràng buộc:
1. 1 <= nums.length <= 3 * 10^4
2. 1 <= nums[i] <= 1000
3. 0 <= k <= 10^6
*/

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0; // Nếu k <= 1, không có dãy con nào thỏa mãn

    int product = 1;   // Tích hiện tại của cửa sổ
    int left = 0;      // Con trỏ trái của cửa sổ
    int count = 0;     // Đếm số dãy con thỏa mãn

    // Duyệt qua các phần tử với con trỏ phải
    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right]; // Cập nhật tích

        // Nếu tích >= k, thu hẹp cửa sổ từ bên trái
        while (product >= k && left <= right) {
            product /= nums[left];
            left++;
        }

        // Số lượng dãy con kết thúc tại `right` là (right - left + 1)
        count += (right - left + 1);
    }

    return count;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    cout << numSubarrayProductLessThanK(nums, k) << endl; // Output: 8
    return 0;
}
