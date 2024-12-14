#include <bits/stdc++.h>
using namespace std;

// I.dãy con tổng chia dư bằng r
// const int INF = -1e9; // Giá trị không hợp lệ

// const int N = 1e4 + 5; // Số lượng phần tử tối đa
// const int K = 105;     // K tối đa

// int a[N], n, k;       // Mảng đầu vào, số lượng phần tử và giá trị k
// int mem[N][K];        // Bảng ghi nhớ trạng thái

// // Hàm tính độ dài lớn nhất của dãy con có tổng chia hết cho r cho den vi tri thu i
// int DP(int i, int r) {
//     if (i == 0) return (r == 0) ? 0 : INF; // Trường hợp cơ sở
//     if (mem[i][r] != -1) return mem[i][r]; // Nếu đã tính, trả về kết quả

//     int res = DP(i - 1, r); // Không chọn phần tử a[i]
//     int new_r = (r - a[i] % k + k) % k; // Phần dư mới nếu chọn a[i]
//     res = max(res, DP(i - 1, new_r) + 1); // Chọn a[i]

//     return mem[i][r] = res; // Lưu lại kết quả
// }

// int main() {
//     // Nhập dữ liệu
//     cout << "Nhập số phần tử (n) và k: ";
//     cin >> n >> k;

//     cout << "Nhập mảng các số: ";
//     for (int i = 1; i <= n; i++) cin >> a[i];

//     // Khởi tạo mảng mem
//     memset(mem, -1, sizeof(mem));

//     // Gọi hàm DP và in kết quả
//     int result = DP(n, 0); // Bắt đầu từ phần tử cuối và phần dư 0
//     if (result < 0)
//         cout << "Không có dãy con nào chia hết cho " << k << "." << endl;
//     else
//         cout << "Độ dài lớn nhất của dãy con chia hết cho " << k << ": " << result << endl;

//     return 0;
// }

// II. có dãy con có tổng bằng x?
// Mảng a và thông số đầu vào
// int n, x;
// vector<int> a;

// // Bảng ghi nhớ trạng thái
// vector<vector<int>> mem;

// bool DP(int i, int t) {
//     if (t == 0) return true;               // Tổng 0 luôn đạt được
//     if (i == 0) return false;              // Không còn phần tử nào
//     if (mem[i][t] != -1) return mem[i][t]; // Trả về nếu đã tính trước

//     // Không chọn A[i]
//     bool res = DP(i - 1, t);
//     // Chọn A[i] nếu t >= A[i]
//     if (t >= a[i - 1]) res = res || DP(i - 1, t - a[i - 1]);

//     return mem[i][t] = res; // Lưu kết quả vào bảng ghi nhớ
// }

// void solve() {
//     // Nhập đầu vào
//     cout << "Nhập số phần tử (n) và tổng cần tìm (x): ";
//     cin >> n >> x;
//     a.resize(n);
//     cout << "Nhập mảng các số: ";
//     for (int i = 0; i < n; i++) cin >> a[i];

//     // Khởi tạo bảng ghi nhớ
//     mem.assign(n + 1, vector<int>(x + 1, -1));

//     // Gọi hàm DP
//     if (DP(n, x)) {
//         cout << "Có dãy con có tổng bằng " << x << "." << endl;
//     } else {
//         cout << "Không có dãy con nào có tổng bằng " << x << "." << endl;
//     }
// }


// III. đếm số dãy có tổng so với n và khác nhau?

// // Mảng và các thông số đầu vào
// int n, x;
// vector<int> a;

// // Bảng ghi nhớ trạng thái
// vector<vector<int>> mem;

// // Hàm đệ quy kiểm tra tổng \( t \) có khả dĩ không
// bool DP(int i, int t) {
//     if (t == 0) return true;               // Tổng 0 luôn đạt được
//     if (i == 0) return false;              // Không còn phần tử nào
//     if (mem[i][t] != -1) return mem[i][t]; // Trả về nếu đã tính trước

//     // Không chọn A[i]
//     bool res = DP(i - 1, t);
//     // Chọn A[i] nếu t >= A[i]
//     if (t >= a[i - 1]) res = res || DP(i - 1, t - a[i - 1]);

//     return mem[i][t] = res; // Lưu kết quả vào bảng ghi nhớ
// }

// void solve() {
//     cout << "Nhập số phần tử (n) và tổng cần tìm (>= x): ";
//     cin >> n >> x;
//     a.resize(n);
//     cout << "Nhập mảng các số: ";
//     for (int i = 0; i < n; i++) cin >> a[i];

//     // Tính tổng lớn nhất có thể đạt được
//     int max_sum = accumulate(a.begin(), a.end(), 0);

//     // Khởi tạo bảng ghi nhớ
//     mem.assign(n + 1, vector<int>(max_sum + 1, -1));

//     // Duyệt từ x đến max_sum để đếm số lượng tổng khả dĩ
//     int result = 0;
//     for (int t = x; t <= max_sum; t++) {
//         if (DP(n, t)) result++;
//     }

//     cout << "Số lượng tổng >= " << x << " mà không lặp lại: " << result << endl;
// }

// IV. dạng độ dài lớn nhất:
// int LIS(vector<int>& a) {
//     int n = a.size();
//     vector<int> dp(n, 1); // Khởi tạo DP, mỗi phần tử có LIS ban đầu = 1

//     // Tính DP[i] cho tất cả i
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (a[j] < a[i]) { // thay điều kiện là làm dc mọi bài
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     // Tìm LIS lớn nhất
//     return *max_element(dp.begin(), dp.end());
// }
// hoac la nhu nay
// int f(int i) {
//     if (mem[i] != -1) return mem[i];

//     int res = 1;
//     for (int j = 0; j < i; j++) {
//         if ((A[j] > A[i]) && (A[i] % 2 != A[j] % 2)) {
//             res = max(res, f(j) + 1);
//         }
//     }

//     return mem[i] = res;
// }


// int LongestZigZagSequence(vector<int>& a) {
//     int n = a.size();
//     if (n == 0) return 0;
//     vector<int> up(n, 1), down(n, 1);
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (a[i] > a[j]) {
//                 up[i] = max(up[i], down[j] + 1);
//             } else if (a[i] < a[j]) {
//                 down[i] = max(down[i], up[j] + 1);
//             }
//         }
//     }
//     return max(*max_element(up.begin(), up.end()), *max_element(down.begin(), down.end()));
// }

// int LongestPalindromicSubsequence(string s) {
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for (int i = n - 1; i >= 0; i--) {
//         dp[i][i] = 1;
//         for (int j = i + 1; j < n; j++) {
//             if (s[i] == s[j]) {
//                 dp[i][j] = dp[i + 1][j - 1] + 2;
//             } else {
//                 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     return dp[0][n - 1];
// }

// Đếm tổng bằng k:
// int f(int i, int t) {
//     if (i == 0) return a[0] == t;
//     if (t == 0) return 1;
//     if (mem[i][t] != -1) return mem[i][t];

//     int res = f(i-1, t);
//     if (a[i] <= t) res = res + f(i-1, t - a[i]);

//     return mem[i][t] = res;
// }

// Đếm số LIS có độ dài bằng len
// int f(int i, int len, int target, vector<int>& nums, vector<vector<int>>& mem) {
//     if (len > target) return 0; // Dãy quá dài, không hợp lệ
//     if (len == target) return 1; // Đúng độ dài LIS, đếm 1 cách

//     if (mem[i][len] != -1) return mem[i][len];

//     int count = 0;

//     // Duyệt tất cả các phần tử trước `i`
//     for (int j = 0; j < i; j++) {
//         if (nums[j] < nums[i] && LIS[j] + 1 == LIS[i]) {
//             count += f(j, len + 1, target, nums, LIS, mem);
//         }
//     }

//     return mem[i][len] = count;
// }