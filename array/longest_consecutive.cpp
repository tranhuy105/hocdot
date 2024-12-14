#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

/*
Đề bài:
Viết một chương trình để tìm độ dài dãy số liên tiếp dài nhất trong một mảng số nguyên.

Yêu cầu:
- Một dãy số liên tiếp được định nghĩa là một tập hợp các số liên tiếp (ví dụ: {1, 2, 3, 4}).
- Tìm độ dài lớn nhất của dãy số liên tiếp trong mảng.

Đầu vào:
- Một vector số nguyên `nums`.

Đầu ra:
- Một số nguyên biểu thị độ dài của dãy số liên tiếp dài nhất.

Ví dụ:
- Input: nums = {100, 4, 200, 1, 3, 2}
- Output: 4 (vì dãy số liên tiếp dài nhất là {1, 2, 3, 4})

Ghi chú:
- Nếu mảng rỗng, trả về 0.
- Phần tử trùng lặp không được tính trong dãy liên tiếp.
*/


int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;

    for (int num : numSet) {
        // Check if 'num' is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            // Count the length of the sequence starting from 'num'
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentLength += 1;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    sort(nums.begin(), nums.end());
    int count = 1;
    int maximum = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            maximum = max(maximum, count);
            continue;
        }

        if (nums[i] - 1 == nums[i-1]) {
            count++;
            maximum = max(maximum, count);
        } else {
            count = 1;
            maximum = max(maximum, count);
        }
    }

    return maximum;
}

int main() {
    // 0 1 1 2
    vector<int> arr = {2};
    cout << longestConsecutive(arr) << endl;
    return 0;
}