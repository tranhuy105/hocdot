#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Hàm tìm chỉ số của phần tử lớn nhất nhưng nhỏ hơn k trong mảng đã sắp xếp.
*/
int findLargestLessThanK(const vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    int result = -1; // Khởi tạo kết quả là -1 (không tìm thấy)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < k) {
            result = mid; // Cập nhật kết quả
            left = mid + 1; // Tìm tiếp ở bên phải
        } else {
            right = mid - 1; // Thu hẹp khoảng sang bên trái
        }
    }

    return result; // Trả về chỉ số của phần tử lớn nhất nhỏ hơn k (hoặc -1 nếu không tìm thấy)
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9}; // Mảng đã sắp xếp
    int k = 6;

    int index = findLargestLessThanK(nums, k);
    if (index != -1) {
        cout << "Chỉ số của phần tử lớn nhất nhỏ hơn " << k << ": " << index << endl;
        cout << "Phần tử đó là: " << nums[index] << endl;
    } else {
        cout << "Không có phần tử nào nhỏ hơn " << k << endl;
    }

    return 0;
}
