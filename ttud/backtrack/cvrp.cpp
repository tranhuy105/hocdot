#include <iostream>
#include <climits>
using namespace std;

const int MAXN = 20;
int N, K, Q;
int d[MAXN];        // Nhu cầu hàng hóa tại các điểm
int c[MAXN][MAXN];  // Ma trận chi phí
int y[MAXN], x[MAXN];
int visited[MAXN];  // Đánh dấu điểm đã được thăm
int load[MAXN];     // Tải trọng hiện tại của mỗi xe
int f = 0, f_star = INT_MAX; // Chi phí hiện tại và tốt nhất
int segments = 0;   // Số đoạn đường đã sử dụng
int Cmin = INT_MAX; // Chi phí nhỏ nhất giữa 2 điểm
int nbR = 0;        // Số đoạn đường được sử dụng thực tế

// Kiểm tra tính hợp lệ khi gán x[s] = v
bool checkX(int v, int k) {
    if (v > 0 && visited[v]) return false; // Điểm đã được thăm
    if (load[k] + d[v] > Q) return false; // Quá tải
    return true;
}

// Kiểm tra tính hợp lệ khi gán y[k] = v
bool checkY(int v, int k) {
    if (v == 0) return true; // Xe không hoạt động
    if (load[k] + d[v] > Q) return false; // Quá tải
    if (visited[v]) return false;         // Điểm đã được thăm
    return true;
}

// Cập nhật lời giải tốt nhất
void updateBest() {
    if (f < f_star) {
        f_star = f; // Lưu chi phí tối ưu
    }
}

// Thử giá trị cho x[s] (lộ trình của xe k từ điểm s)
void TRY_X(int s, int k) {
    if (s == 0) { // Nếu xe quay lại kho
        if (k < K) { // Chuyển sang xe tiếp theo
            TRY_X(y[k + 1], k + 1);
        }
        return;
    }

    for (int v = 0; v <= N; v++) { // Duyệt tất cả các điểm
        if (checkX(v, k)) {        // Kiểm tra điểm hợp lệ
            x[s] = v;              // Gán điểm tiếp theo
            visited[v] = true;     // Đánh dấu điểm đã được giao
            f += c[s][v];          // Cộng chi phí đi từ điểm s đến điểm v
            load[k] += d[v];       // Cập nhật tải trọng xe
            segments++;            // Tăng số đoạn đường

            if (v > 0) {           // Nếu v là một điểm thực
                if (f + (N + nbR - segments) * Cmin < f_star) {
                    TRY_X(v, k);   // Tiếp tục tìm điểm tiếp theo
                }
            } else {               // Nếu xe quay lại kho
                if (k == K) {      // Nếu tất cả xe đã được xét
                    if (segments == N + nbR) updateBest(); // Cập nhật lời giải tốt nhất
                } else {
                    if (f + (N + nbR - segments) * Cmin < f_star) {
                        TRY_X(y[k + 1], k + 1); // Chuyển sang xe tiếp theo
                    }
                }
            }

            visited[v] = false;    // Bỏ đánh dấu điểm
            f -= c[s][v];          // Hoàn lại chi phí
            load[k] -= d[v];       // Hoàn lại tải trọng
            segments--;            // Giảm số đoạn đường
        }
    }
}

// Thử giá trị cho y[k] (điểm giao đầu tiên của xe k)
void TRY_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0) s = y[k - 1] + 1;
    for (int v = s; v <= N; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) segments++;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if (k < K) {
                TRY_Y(k + 1);
            } else {
                nbR = segments;
                TRY_X(y[1], 1);
            }

            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if (v > 0) segments--;
        }
    }
}

void solve() {
    f = 0;
    f_star = INT_MAX;
    y[0] = 0;

    for (int v = 1; v <= N; v++) visited[v] = false;

    TRY_Y(1);
    cout << "Minimum cost: " << f_star << endl;
}

void input() {
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++) cin >> d[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> c[i][j];
            if (i != j) Cmin = min(Cmin, c[i][j]); // Tìm chi phí nhỏ nhất
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}
