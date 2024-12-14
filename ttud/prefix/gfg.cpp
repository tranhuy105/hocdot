#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int Q; int l; int r;
    cin >> s;

    int n = s.size();
    vector<vector<int>> pref(n+1, vector<int>(26));
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i];
        int currentChar = s[i] - 'a';
        pref[i+1][currentChar]++;
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        char bestChar = '?';
        int bestFreq = 0;
        for (int i = 0; i < 26; i++) {
            int currentChar = i;
            int freq = pref[r+1][currentChar] - pref[l][currentChar];
            if (freq > bestFreq) {
                bestFreq = freq;
                bestChar = currentChar + 'a';
            }
        }
        cout << bestChar << endl;
    }
    return 0;
}

// abcabcabc
// 3
// 0 2
// 1 4
// 2 8

/*
Đề bài:
Cho một chuỗi `s` và một số nguyên `Q` biểu thị số lượng truy vấn. Với mỗi truy vấn, bạn cần trả về ký tự có tần suất xuất hiện nhiều nhất trong một đoạn chuỗi con từ vị trí `l` đến `r` (tính từ 0). Nếu có nhiều ký tự có cùng tần suất, trả về ký tự xuất hiện trước theo thứ tự bảng chữ cái.

Đầu vào:
- Một chuỗi `s` (chỉ chứa các ký tự từ 'a' đến 'z').
- Một số nguyên `Q` (số lượng truy vấn).
- `Q` dòng tiếp theo, mỗi dòng chứa hai số nguyên `l` và `r` (vị trí bắt đầu và kết thúc của đoạn chuỗi con).

Đầu ra:
- Với mỗi truy vấn, in ra ký tự có tần suất xuất hiện nhiều nhất trong đoạn chuỗi con từ `l` đến `r`.

Ví dụ:
Input:
s = abcabcabc
Q = 3
0 2
1 4
2 8

Output:
a
b
a

Giải thích:
1. Đoạn từ 0 đến 2: "abc" → Ký tự 'a' có tần suất cao nhất (1 lần).
2. Đoạn từ 1 đến 4: "bcab" → Ký tự 'b' có tần suất cao nhất (2 lần).
3. Đoạn từ 2 đến 8: "cabcbca" → Ký tự 'a' có tần suất cao nhất (3 lần).

Hướng dẫn giải:
1. **Tiền xử lý với mảng tổng tiền tố (prefix sum):**
   - Tạo mảng `pref` để lưu tần suất xuất hiện của từng ký tự trong chuỗi.
   - `pref[i+1][j]` biểu thị số lần ký tự `'a' + j` xuất hiện trong chuỗi từ đầu đến vị trí `i`.

2. **Trả lời truy vấn:**
   - Với mỗi truy vấn `(l, r)`, tính tần suất của mỗi ký tự trong đoạn từ `l` đến `r` bằng:
     \[
     \text{freq[j]} = \text{pref[r+1][j]} - \text{pref[l][j]}
     \]
   - Duyệt qua tần suất của 26 ký tự để tìm ký tự có tần suất cao nhất.

Độ phức tạp:
- Tiền xử lý: O(n * 26) với n là độ dài chuỗi.
- Truy vấn: O(Q * 26).
- Tổng: O((n + Q) * 26).
*/
