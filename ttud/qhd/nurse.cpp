/*
Đề bài:
Giám đốc bệnh viện muốn lập kế hoạch làm việc cho một y tá trong N ngày liên tiếp (1, ..., N). Y tá cần có ngày nghỉ và kế hoạch làm việc cần tuân theo các điều kiện sau:
1. Y tá chỉ được nghỉ 1 ngày giữa hai giai đoạn làm việc liên tiếp. Nếu y tá nghỉ hôm nay, cô ấy phải làm việc vào ngày mai.
2. Độ dài của mỗi giai đoạn làm việc phải nằm trong khoảng [K1, K2].

Yêu cầu:
- Tính tổng số lượng kế hoạch làm việc thỏa mãn các điều kiện trên, sau đó lấy kết quả modulo \(10^9+7\).

Đầu vào:
- Một dòng duy nhất chứa 3 số nguyên dương: \(N, K1, K2\) (2 ≤ N ≤ 1000, \(K1 < K2 ≤ 400\)).

Đầu ra:
- Một số nguyên duy nhất là số lượng kế hoạch làm việc modulo \(10^9+7\).

Ví dụ:
Input:
6 2 3

Output:
4

Giải thích:
- Với N = 6, K1 = 2, K2 = 3:
  - Các kế hoạch thỏa mãn: {2-2-2}, {2-3}, {3-2}, {3-3}.
*/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countWorkingPlans(int n, int k1, int k2) {
    vector<vector<int>> f(n+1, vector<int>(2));
    f[0][0] = f[0][1] = 1; // Trạng thái ban đầu: không có ngày nào => có 1 cách duy nhất (kế hoạch trống).

    for (int i = 1; i <= n; i++) { // Duyệt qua từng ngày từ 1 đến n
        for (int j = k1; j <= k2; j++) { // Xét mọi độ dài của chuỗi làm việc hợp lệ từ K1 đến K2
            if (i - j < 0) break; // Nếu vượt quá giới hạn ngày, thoát vòng lặp
            f[i][1] += f[i - j][0]; // Cộng số cách lập kế hoạch nếu ngày i-j là ngày nghỉ
            f[i][1] %= MOD; // Modulo để tránh tràn số
        }
        f[i][0] = f[i - 1][1]; // Nếu ngày i là ngày nghỉ, thì ngày i-1 phải là ngày làm việc
    }

    return (f[n][0] + f[n][1]) % MOD;
}

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    cout << countWorkingPlans(N, K1, K2) << endl;
    return 0;
}
