#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Bài toán con:
Đếm số cặp (i, j) trong đoạn nums[left, right] thỏa mãn:
nums[i] + nums[j] > X
*/

int countPairs(const vector<int>& nums, int left, int right, int X) {
    int count = 0;

    while (left < right) {
        // Nếu tổng nums[left] + nums[right] lớn hơn X
        if (nums[left] + nums[right] > X) {
            count += (right - left); // Tất cả các cặp từ left đến right-1 thỏa mãn
            --right;                // Dịch con trỏ phải sang trái
        } else {
            ++left;                 // Nếu không thỏa mãn, tăng con trỏ trái
        }
    }

    return count;
}

/*
Bài toán lớn:
Đếm số bộ ba (i, j, k) thỏa mãn:
nums[i] + nums[j] > nums[k]
*/

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    // Bước 1: Sắp xếp mảng để dễ dàng kiểm tra điều kiện tam giác
    sort(nums.begin(), nums.end());

    // Bước 2: Duyệt qua từng phần tử nums[k] để tìm các cặp (i, j)
    for (int k = n - 1; k >= 2; --k) {
        // Gọi bài toán con để đếm số cặp (i, j) thỏa mãn điều kiện
        count += countPairs(nums, 0, k - 1, nums[k]);
    }

    return count; // Trả về tổng số bộ ba tam giác hợp lệ
}

int main() {
    vector<int> nums = {2, 2, 3, 4}; // Input mảng độ dài các đoạn thẳng
    cout << "Số tam giác hợp lệ: " << triangleNumber(nums) << endl; // Output: 3
    return 0;
}
