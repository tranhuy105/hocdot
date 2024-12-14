#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Tìm khoảng cách nhỏ nhất giữa hai phần tử trong mảng (theo giá trị):
    min(|nums[i] - nums[j]|) với i ≠ j.

Ý tưởng:
- Khoảng cách nhỏ nhất chỉ có thể xuất hiện giữa hai phần tử liền kề trong mảng đã được sắp xếp.
- Vì vậy, ta:
  1. Sắp xếp mảng.
  2. Duyệt qua từng cặp phần tử liền kề và tính hiệu nums[i+1] - nums[i].
  3. Lấy giá trị nhỏ nhất trong các khoảng cách đó.

Đầu vào:
- Một mảng `nums` gồm các số nguyên.

Đầu ra:
- Khoảng cách nhỏ nhất giữa hai phần tử.

Ví dụ:
Input: nums = [3, 10, 6, 8]
Output: 2
Giải thích:
Khoảng cách nhỏ nhất là giữa 6 và 8.
*/

int findMinimumDifference(vector<int>& nums) {
    // Bước 1: Sắp xếp mảng
    sort(nums.begin(), nums.end());

    // Bước 2: Tính khoảng cách nhỏ nhất giữa các phần tử liền kề
    int minDiff = INT_MAX; // Gán giá trị ban đầu lớn nhất

    for (int i = 1; i < nums.size(); i++) {
        minDiff = min(minDiff, nums[i] - nums[i - 1]); // Cập nhật khoảng cách nhỏ nhất
    }

    return minDiff; // Trả về kết quả
}

int main() {
    vector<int> nums = {3, 10, 6, 8}; // Mảng đầu vào
    cout << "Khoảng cách nhỏ nhất: " << findMinimumDifference(nums) << endl; // Output: 2
    return 0;
}
