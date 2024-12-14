/*
Đề bài:
Có `n` hành khách được đánh số từ 1 đến `n`. Hành khách thứ `i` muốn di chuyển từ điểm `i` đến điểm `i + n` (với `i = 1, 2, ..., n`). 
Một xe buýt được đặt tại điểm 0 và có sức chứa tối đa là `k` hành khách (tức là tại bất kỳ thời điểm nào, xe buýt có thể chở tối đa `k` hành khách). 
Bạn được cung cấp ma trận khoảng cách `c`, trong đó `c(i, j)` là khoảng cách từ điểm `i` đến điểm `j` (với `i, j = 0, 1, ..., 2n`). 

Nhiệm vụ:
Tính chiều dài ngắn nhất của hành trình xe buýt khi phục vụ `n` hành khách và quay lại điểm xuất phát `0`.

Đầu vào:
- Dòng đầu tiên chứa hai số nguyên `n` (số hành khách) và `k` (số lượng chỗ ngồi tối đa của xe buýt).
- Dòng thứ `i + 1` (với `i = 1, 2, ..., 2n + 1`) chứa dòng thứ `i - 1` của ma trận khoảng cách `c`. 
  (Các hàng và cột được đánh chỉ số từ 0, 1, ..., 2n).

Đầu ra:
- Một dòng duy nhất chứa chiều dài ngắn nhất của hành trình.

Ví dụ:
Input:
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0

Output:
25

Giải thích:
- Xe buýt bắt đầu từ điểm 0.
- Xe phải phục vụ `n = 3` hành khách.
- Mỗi hành khách thứ `i` di chuyển từ điểm `i` đến điểm `i + n`.
- Xe có tối đa `k = 2` chỗ ngồi, tức là chỉ có thể chở 2 hành khách cùng lúc.
- Hành trình phải tối ưu hóa chiều dài quãng đường đi.

Lưu ý:
- Đây là bài toán tổ hợp phức tạp với số lượng điểm là `2n + 1`.
- Chỉ cần trả về chiều dài ngắn nhất của hành trình, không cần hiển thị hành trình cụ thể.
*/


#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int N;  // Số lượng yêu cầu (1, 2, ..., N). Yêu cầu i có điểm đón là i và trả là i + N.
int cap; // Sức chứa của xe buýt
vector<vector<int>> A(2 * MAX + 1, vector<int>(2 * MAX + 1)); // Ma trận khoảng cách

vector<int> x(2 * MAX + 1); // Biến quyết định: x[k] là điểm thứ k trong lộ trình
vector<int> visited(2 * MAX + 1, 0); // Mảng đánh dấu: visited[v] = 1 nếu điểm v đã được thăm
int load; // Số lượng khách hiện tại trên xe
int f; // Chi phí của lộ trình hiện tại
int f_best; // Chi phí tối ưu (kỷ lục)
vector<int> x_best(2 * MAX + 1); // Lưu trữ lộ trình tối ưu
int cmin; // Khoảng cách nhỏ nhất giữa hai điểm bất kỳ (tính cận dưới)

// Hàm nhập dữ liệu
void input() {
    cin >> N >> cap;
    cmin = INT_MAX;
    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            cin >> A[i][j];
            if (i != j) cmin = min(cmin, A[i][j]); // Tính khoảng cách nhỏ nhất
        }
    }
}

// Hàm kiểm tra tính hợp lệ
bool check(int v, int k) {
    if (visited[v]) return false; // Điểm đã được thăm
    if (v > N && !visited[v - N]) return false; // Điểm trả chưa thể đi nếu điểm đón chưa đi qua
    if (v <= N && load + 1 > cap) return false; // Vượt quá sức chứa

    return true;
}

// Hàm cập nhật lộ trình tốt nhất
void solution() {
    if (f + A[x[2 * N]][0] < f_best) {
        f_best = f + A[x[2 * N]][0];
        x_best = x; // Lưu lại lộ trình tối ưu
    }
}

int calculateBound(int k) {
    return (2 * N + 1 - k) * cmin;
}

// Hàm quay lui và nhánh cận
void Try(int k) {
    for (int v = 1; v <= 2 * N; v++) { // Duyệt qua các điểm từ 1 đến 2N
        if (check(v, k)) {
            x[k] = v;
            f += A[x[k - 1]][x[k]]; // Cập nhật chi phí
            load += (v <= N) ? 1 : -1; // Điểm đón: Tăng số khách, điểm trả: Giảm số khách
            visited[v] = 1; // Đánh dấu điểm v đã thăm

            if (k == 2 * N) {
                solution(); // Nếu đã đủ lộ trình, cập nhật kết quả
            } else if (f + calculateBound(k) < f_best) {
                // Cận dưới: nếu còn tiềm năng thì tiếp tục
                Try(k + 1);
            }

            // Quay lui: khôi phục trạng thái
            
            load -= (v <= N) ? 1 : -1;
            visited[v] = 0;
            f -= A[x[k - 1]][x[k]];
        }
    }
}

// Hàm giải quyết bài toán
void solve() {
    load = 0; // Số khách trên xe ban đầu
    f = 0; // Chi phí ban đầu
    f_best = INT_MAX; // Khởi tạo chi phí tối ưu
    fill(visited.begin(), visited.end(), 0); // Đặt trạng thái chưa thăm
    x[0] = 0; // Điểm bắt đầu là 0
    Try(1); // Bắt đầu từ bước đầu tiên
    cout << f_best << endl; // In chi phí tối ưu
}

// Hàm in lộ trình tối ưu
void print() {
    for (int i = 0; i <= 2 * N; i++) cout << x_best[i] << " ";
    cout << endl;
}

// Hàm chính
int main() {
    input(); // Nhập dữ liệu
    solve(); // Giải bài toán
    print(); // In lộ trình tối ưu
    return 0;
}
