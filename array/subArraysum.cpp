#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Đề bài:
Viết một chương trình để đếm số lượng dãy con (subarray) trong một mảng sao cho tổng của các phần tử trong dãy con đó bằng `k`.

Yêu cầu:
- Tìm tất cả các dãy con liên tiếp có tổng bằng `k`.
- Tối ưu hóa về thời gian và không gian bằng cách sử dụng các kỹ thuật như mảng tổng tiền tố (prefix sum) hoặc cấu trúc dữ liệu hash map.

Đầu vào:
- Một vector số nguyên `nums`.
- Một số nguyên `k` là tổng mục tiêu.

Đầu ra:
- Một số nguyên biểu thị số lượng dãy con có tổng bằng `k`.

Ví dụ:
- Input: nums = {1, -1, 0}, k = 0
- Output: 3 (các dãy con là {1, -1}, {-1, 0}, {0})
*/


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;
    int count = 0, sum = 0;

    mpp[0] = 1; // Trường hợp tổng tiền tố bằng đúng k.

    for (int num : nums) {
        sum += num;

        // Kiểm tra nếu sum - k đã từng xuất hiện
        if (mpp.find(sum - k) != mpp.end()) {
            count += mpp[sum - k];
        }

        // Cập nhật hash map với tổng tiền tố hiện tại
        mpp[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, -1, 0};
    int k = 0;
    cout << subarraySum(nums, k) << endl; // Output: 3
    return 0;
}