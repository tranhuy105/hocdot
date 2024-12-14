#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Đề bài (Two Sum < X):
Đếm số lượng cặp (i, j) trong mảng `nums` sao cho:
nums[i] + nums[j] < X
với 0 <= i < j < n.

Input:
- Một mảng số nguyên `nums`.
- Một số nguyên `X`.

Output:
- Trả về số lượng cặp (i, j) thỏa mãn điều kiện.
*/

int countPairsLessThanX(vector<int>& nums, int X) {
    // Bước 1: Sắp xếp mảng
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int count = 0;

    // Bước 2: Dùng hai con trỏ để đếm số cặp
    while (left < right) {
        // Nếu tổng nums[left] + nums[right] < X
        if (nums[left] + nums[right] < X) {
            count += (right - left); // Tất cả các cặp (left, ..., right-1) đều thỏa mãn
            ++left;                 // Tăng con trỏ trái để kiểm tra tiếp
        } else {
            --right; // Nếu không thỏa mãn, giảm con trỏ phải
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2, 3, 5, 8, 10}; // Input mảng
    int X = 10;                         // Tổng cần kiểm tra

    cout << "Số cặp có tổng nhỏ hơn " << X << ": " << countPairsLessThanX(nums, X) << endl; // Output
    return 0;
}
