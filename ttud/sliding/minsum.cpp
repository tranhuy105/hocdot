#include <bits/stdc++.h>

/*
Đề bài:
Cho một mảng số nguyên `arr` và một số nguyên `target`. Nhiệm vụ là tìm độ dài nhỏ nhất của một dãy con liên tiếp (subarray) sao cho tổng của các phần tử trong dãy con đó lớn hơn hoặc bằng `target`. Nếu không tồn tại dãy con nào thỏa mãn, trả về 0.

Đầu vào:
- Một số nguyên `target` - tổng mục tiêu.
- Một mảng số nguyên `arr`.

Đầu ra:
- Một số nguyên biểu thị độ dài nhỏ nhất của dãy con liên tiếp thỏa mãn điều kiện, hoặc 0 nếu không có dãy con nào thỏa mãn.

Ví dụ:
Input:
target = 7
arr = {2, 3, 1, 2, 4, 3}

Output:
2

Giải thích:
- Dãy con liên tiếp ngắn nhất có tổng ≥ 7 là {4, 3}, với độ dài là 2.
*/


using namespace std;

int minSubArrayLen(int target, vector<int>& arr) {
    int res = INT_MAX; int l = 0;
    int n = arr.size();
    int sum = 0;

    for (int r = 0; r < n; r++) {
        sum += arr[r];

        while (sum >= target) {
            res = min(res, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }

    return res == INT_MAX ? 0 : res;
}

int main()
{
    vector<int> arr = {2,3,1,2,4,3}; int target = 7;
    cout << minSubArrayLen(target, arr) << endl;
    return 0;
}
