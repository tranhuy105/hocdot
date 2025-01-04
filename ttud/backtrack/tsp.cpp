/*
Đề bài:
Bài toán người du lịch (Travelling Salesman Problem - TSP): 
Cho một đồ thị hoàn chỉnh với `n` đỉnh, mỗi cạnh giữa hai đỉnh có chi phí di chuyển nhất định. 
Nhiệm vụ là tìm hành trình ngắn nhất xuất phát từ đỉnh 1, đi qua mỗi đỉnh đúng một lần, và quay lại đỉnh ban đầu.

Đầu vào:
- Một số nguyên `n` (số lượng đỉnh, 1 ≤ n ≤ 20).
- Một ma trận `cost[i][j]` (kích thước `n x n`) trong đó `cost[i][j]` là chi phí di chuyển từ đỉnh `i` đến đỉnh `j`.

Đầu ra:
- Chi phí tối thiểu để hoàn thành hành trình.
- Dãy đỉnh của hành trình tốt nhất.

Ví dụ:
Input:
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Output:
The minimum cost is: 80
The best path is: 1 2 4 3 1

Giải thích:
- Xuất phát từ đỉnh 1.
- Lộ trình tối ưu là 1 → 2 → 4 → 3 → 1 với chi phí tổng là 80.
*/

#include <bits/stdc++.h>
using namespace std;

// Khai báo biến toàn cục
int n;                        // Số đỉnh trong đồ thị
bool visited[20];             // Mảng đánh dấu các đỉnh đã được thăm
int cost[20][20];             // Ma trận chi phí di chuyển giữa các đỉnh
int path[20];                 // Lưu đường đi hiện tại
int bestPath[20];             // Lưu đường đi tốt nhất
int f = 0;                    // Chi phí hiện tại của hành trình
int f_star = INT_MAX;         // Chi phí nhỏ nhất của hành trình tốt nhất

// Kiểm tra xem đỉnh `v` có thể chọn tại bước `k` không
bool check(int v, int k) {
    return !visited[v]; // Chỉ chọn đỉnh `v` nếu nó chưa được thăm
}

// Tính toán cận dưới cho hành trình hiện tại
int calculateBound() {
    int bound = f; // Khởi tạo cận dưới bằng chi phí hiện tại
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // Nếu đỉnh `i` chưa được thăm
            int min_path = INT_MAX; // Tìm chi phí nhỏ nhất từ `i` đến các đỉnh khác
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    min_path = std::min(min_path, cost[i][j]);
                }
            }
            bound += min_path; // Cộng chi phí nhỏ nhất vào cận dưới
        }
    }
    return bound; // Trả về cận dưới
}

// Kiểm tra và cập nhật nếu tìm được hành trình tốt hơn
void solution() {
    // Tính tổng chi phí hành trình hoàn chỉnh, bao gồm quay lại đỉnh xuất phát
    int totalCost = f + cost[path[n-1]][path[0]];
    if (totalCost < f_star) { // Nếu chi phí nhỏ hơn hành trình tốt nhất hiện tại
        f_star = totalCost;   // Cập nhật chi phí nhỏ nhất
        for (int i = 0; i < n; i++) {
            bestPath[i] = path[i]; // Lưu hành trình tốt nhất
        }
    }
}

// Hàm thử (backtracking) tại bước `k`
void Try(int k) {
    for (int v = 0; v < n; v++) { // Duyệt qua tất cả các đỉnh
        if (check(v, k)) {        // Kiểm tra nếu có thể chọn đỉnh `v`
            path[k] = v;          // Thêm đỉnh `v` vào hành trình hiện tại
            visited[v] = true;    // Đánh dấu đỉnh `v` đã được thăm
            f += cost[path[k-1]][v]; // Cập nhật chi phí hiện tại

            if (k == n-1) {       // Nếu đã đi qua tất cả các đỉnh
                solution();       // Kiểm tra và cập nhật hành trình tốt nhất
            } else {              // Nếu chưa đi qua tất cả các đỉnh
                int bound = calculateBound(); // Tính cận dưới
                if (bound < f_star) {         // Nếu cận dưới khả thi
                    Try(k+1);                // Thử tiếp bước tiếp theo
                }
            }

            // Quay lui: khôi phục trạng thái ban đầu
            visited[v] = false;     // Bỏ đánh dấu đỉnh `v`
            f -= cost[path[k-1]][v]; // Khôi phục chi phí
        }
    }
}

int main() {
    // Đọc dữ liệu đầu vào
    cin >> n; // Số đỉnh
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j]; // Ma trận chi phí giữa các đỉnh
        }
    }

    // Khởi tạo trạng thái ban đầu
    path[0] = 0;              // Bắt đầu từ đỉnh 0
    visited[0] = true;        // Đánh dấu đỉnh 0 đã được thăm
    for (int i = 1; i < n; i++) visited[i] = false; // Các đỉnh khác chưa được thăm

    // Bắt đầu thử từ bước 1
    Try(1);

    // In kết quả
    cout << "The minimum cost is: " << f_star << endl; // In chi phí nhỏ nhất
    cout << "The best path is: ";
    for (int i = 0; i < n; i++) {
        cout << bestPath[i]+1 << " "; // In đường đi tốt nhất (đỉnh bắt đầu từ 1)
    }
    cout << bestPath[0]+1 << endl;   // Quay lại đỉnh xuất phát

    return 0;
}