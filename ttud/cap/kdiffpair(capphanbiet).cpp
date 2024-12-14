#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Đề bài:
- Cho một mảng số nguyên `nums` và một số nguyên `k`.
- Một cặp số (i, j) là một "k-diff pair" nếu:
  + |nums[i] - nums[j]| == k
  + i != j (vị trí khác nhau).

- Tìm số lượng các cặp (i, j) thỏa mãn điều kiện trên.
- Cặp (i, j) và (j, i) được tính là một.

Ví dụ:
Input: nums = [3, 1, 4, 1, 5], k = 2
Output: 2
Giải thích: Hai cặp (3, 1) và (1, 3) được tính là 1. Cặp thỏa mãn là:
(3, 1) và (4, 2).

Ràng buộc:
1. 1 <= nums.length <= 10^4
2. -10^7 <= nums[i] <= 10^7
3. 0 <= k <= 10^7
*/

int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0; // Không thể có cặp với k âm

    unordered_map<int, int> freq; // Bảng đếm tần suất các phần tử
    for (int num : nums) {
        freq[num]++;
    }

    int count = 0;

    for (auto& [key, value] : freq) {
        if (k == 0) {
            // Nếu k == 0, đếm số phần tử có tần suất >= 2
            if (value > 1) count++;
        } else {
            // Nếu k > 0, kiểm tra xem key + k có tồn tại trong bảng tần suất không
            if (freq.count(key + k)) count++;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    cout << "Số lượng k-diff pairs: " << findPairs(nums, k) << endl;
    return 0;
}
