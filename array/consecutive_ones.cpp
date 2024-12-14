#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
Đề bài:
Viết một chương trình để tìm độ dài của dãy số 1 liên tiếp dài nhất trong một mảng nhị phân (gồm các số 0 và 1).

Đầu vào:
- Một mảng số nguyên `nums` chỉ chứa các số 0 và 1.

Đầu ra:
- Một số nguyên biểu thị độ dài lớn nhất của dãy số 1 liên tiếp trong mảng.

Ví dụ:
- Input: nums = {1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1}
- Output: 4 (vì dãy số 1 liên tiếp dài nhất có độ dài là 4)
*/


int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int m = 0;

    for (int it : nums) {
        if (it == 1) {
            cnt++;
            m = max(cnt, m);
        } else {
            cnt = 0;
        }
    }

    return m;
}

int main() {
    vector<int> arr = {1,1,1,1,0,0,0,1,1,0,0,1,0,1};
    cout << findMaxConsecutiveOnes(arr) << endl;
    return 0;
}