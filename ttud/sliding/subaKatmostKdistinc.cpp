/*
- Cho một mảng số nguyên `nums` và một số nguyên `k`.
- Nhiệm vụ: Đếm số lượng dãy con liên tiếp (subarrays) trong mảng chứa **chính xác** `k` số nguyên khác nhau.

Ví dụ:
Input: nums = [1, 2, 1, 2, 3], k = 2
Output: 7
Giải thích: Các dãy con thỏa mãn là:
[1, 2], [1, 2, 1], [2, 1], [2, 1, 2], [1, 2], [1, 2, 3], [2, 3].

Ràng buộc:
1. 1 <= nums.length <= 2 * 10^4
2. 1 <= nums[i], k <= nums.length
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Hàm tính số dãy con có **tối đa** k số khác nhau.
*/
int atMostKDistinct(vector<int>& nums, int k) {
    unordered_map<int, int> freq; // Bảng đếm tần suất các phần tử
    int left = 0;                // Con trỏ trái của cửa sổ trượt
    int count = 0;               // Kết quả lưu số dãy con

    // Duyệt qua từng phần tử trong mảng với con trỏ phải
    for (int right = 0; right < nums.size(); ++right) {
        freq[nums[right]]++; // Thêm phần tử vào cửa sổ

        // Nếu số phần tử khác nhau vượt quá `k`, thu nhỏ cửa sổ từ trái
        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]); // Xóa phần tử nếu tần suất bằng 0
            }
            left++;
        }

        // Cộng số lượng dãy con kết thúc tại `right`
        count += (right - left + 1);
    }

    return count;
}

/*
Hàm chính: Đếm số dãy con có **chính xác** k số khác nhau.
*/
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3}; // Mảng đầu vào
    int k = 2;                          // Số lượng phần tử khác nhau yêu cầu

    cout << "Số lượng dãy con có chính xác " << k << " số khác nhau: "
         << subarraysWithKDistinct(nums, k) << endl; // Output: 7

    return 0;
}
