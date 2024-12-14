#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Viết một chương trình để đếm số lượng cặp phần tử (i, j) trong một mảng số nguyên `a` sao cho `a[i] == a[j]` và `i < j`.

Đầu vào:
- Một vector số nguyên `a`.

Đầu ra:
- Một số nguyên biểu thị số lượng cặp phần tử thỏa mãn điều kiện.

Ví dụ:
- Input: nums = {1, 2, 2, 1, 3, 1}
- Output: 4 (các cặp thỏa mãn là (0, 3), (0, 5), (3, 5), (1, 2))

Phương pháp:
1. **Sử dụng Hash Map**:
   - Dùng `unordered_map` để lưu số lần xuất hiện của mỗi phần tử.
   - Với mỗi phần tử gặp lại, tăng số lượng cặp bằng số lần xuất hiện trước đó.
   - Độ phức tạp: O(n).

Phương pháp tối ưu:
- Sử dụng hash map để giảm độ phức tạp xuống O(n).
*/


int count(vector<int> & a) {
    unordered_map<int, int> map;
    int count  = 0; int n = a.size();

    for (int i = 0; i < n; i++) {
        if (map.find(a[i]) != map.end()) {
            count += map[a[i]];
        }

        map[a[i]]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1,2,2,1,3,1};
    cout << count(nums) << endl; // Output: 2
    return 0;
}
