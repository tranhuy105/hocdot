#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Bài toán "Aggressive Cows":
Cho một mảng `a` gồm `n` vị trí trên trục số, mỗi vị trí là một số nguyên. Nhiệm vụ là chọn `c` phần tử từ mảng sao cho khoảng cách nhỏ nhất giữa bất kỳ hai phần tử được chọn là lớn nhất.

Đầu vào:
- Dòng đầu tiên chứa số nguyên `T` - số bộ test.
- Với mỗi bộ test:
  - Dòng đầu tiên chứa hai số nguyên `n` (số phần tử) và `c` (số phần tử cần chọn).
  - Dòng thứ hai chứa `n` số nguyên đại diện cho các vị trí trong mảng.

Đầu ra:
- Với mỗi bộ test, in ra một số nguyên là khoảng cách lớn nhất giữa hai phần tử gần nhau nhất trong `c` phần tử được chọn.

Ví dụ:
Input:
1
5 3
1 2 8 4 9

Output:
3
*/


int T; // Số bộ test
int n, c; // Số phần tử và số phần tử cần chọn
vector<int> a;

// Kiểm tra liệu với khoảng cách d, có thể chọn được C phần tử hay không
bool canPlaceCows(int d) {
    int count = 1; // Đã chọn phần tử đầu tiên
    int last_position = a[0]; // Vị trí của phần tử đã chọn cuối cùng

    for (int i = 1; i < n; i++) {
        if (a[i] - last_position >= d) {
            count++;
            last_position = a[i];
            if (count == c) return true; // Đủ C phần tử
        }
    }
    return false;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> n >> c;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Sắp xếp mảng đầu vào
        sort(a.begin(), a.end());

        // Binary search trên khoảng cách nhỏ nhất
        int low = 1, high = a[n - 1] - a[0];
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(mid)) {
                result = mid; // Lưu kết quả tạm thời
                low = mid + 1; // Thử khoảng cách lớn hơn
            } else {
                high = mid - 1; // Thử khoảng cách nhỏ hơn
            }
        }

        cout << result << endl; // Kết quả cho mỗi test case
    }
}

int main() {
    solve();
    return 0;
}
