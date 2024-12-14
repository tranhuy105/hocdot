#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
Đề bài:
Viết một chương trình để tìm số bị thiếu trong dãy số từ 0 đến n trong một mảng. Mảng `nums` chứa `n` số nguyên duy nhất từ 0 đến n, nhưng bị thiếu mất một số.

Đầu vào:
- Một vector số nguyên `nums` chứa `n` số nguyên duy nhất từ 0 đến n (một số bị thiếu).

Đầu ra:
- Một số nguyên biểu thị số bị thiếu.

Ví dụ:
- Input: nums = {3, 0, 1}
- Output: 2 (vì dãy đầy đủ từ 0 đến 3 là {0, 1, 2, 3}, và số 2 bị thiếu)

Yêu cầu:
- Tìm số bị thiếu với thời gian tối ưu.
- Sử dụng các phương pháp tính toán tổng hoặc XOR để đạt được độ phức tạp O(n).
*/


int missingNumber(vector<int>& nums) {
    int sum = (nums.size() * (nums.size() + 1)) / 2;
    int s = 0; 
    for (int it : nums) {
        s += it;
    }
    return sum - s;
}

int missingNumber(vector<int>& nums) {
    int xor1=0,xor2=0;
    for (int i = 0; i < nums.size(); ++i) {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i+1);
    }
    
    return xor1 ^ xor2;
}