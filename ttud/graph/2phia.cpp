#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005; // Số công việc tối đa
const int MAXM = 10005; // Số nhân viên tối đa

/*
 * Bài toán:
 * - Có n công việc (tasks) và m nhân viên (staffs).
 * - Mỗi công việc có một danh sách các nhân viên có thể làm.
 * - Yêu cầu: Gán công việc cho nhân viên sao cho:
 *   + Mỗi công việc chỉ được gán cho 1 nhân viên.
 *   + Mỗi nhân viên chỉ làm 1 công việc.
 *   + Số lượng công việc được gán là tối đa.
 * 
 * Ý tưởng:
 * - Biểu diễn bài toán dưới dạng đồ thị hai phía (bipartite graph).
 * - Một phía là tập các công việc, phía còn lại là tập các nhân viên.
 * - Sử dụng thuật toán tìm ghép cặp tối đa với DFS để giải quyết bài toán.
 */

int n, m; // n: số công việc, m: số nhân viên
vector<int> graph[MAXN];  // Danh sách kề: công việc -> nhân viên
int match[MAXM];          // match[v]: công việc mà nhân viên v đang làm
bool visited[MAXM];       // visited[v]: đã thăm nhân viên v hay chưa trong vòng lặp hiện tại


void inp() {
    cin >> n >> m;
    // Nhập danh sách nhân viên có thể làm từng công việc
    for (int i = 1; i <= n; ++i) {
        int k; // Số nhân viên có thể làm công việc i
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int staff;
            cin >> staff;
            graph[i].push_back(staff); // Thêm cạnh từ công việc i đến nhân viên staff
        }
    }
}

// Hàm DFS tìm xem công việc u có thể được gán cho nhân viên nào không
bool dfs(int u) {
    // Duyệt qua tất cả nhân viên có thể làm công việc u
    for (int v : graph[u]) {
        // Nếu nhân viên v chưa được thăm trong vòng lặp này
        if (!visited[v]) {
            visited[v] = true; // Đánh dấu nhân viên v đã được thăm

            // Nếu nhân viên v đang rảnh (chưa làm công việc nào) 
            // hoặc có thể "đẩy" công việc hiện tại của v sang nhân viên khác
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u; // Gán công việc u cho nhân viên v
                return true;  // Thành công
            }
        }
    }
    return false; // Không thể gán công việc u
}

// Hàm tìm ghép cặp tối đa cho tất cả công việc
int maximumMatching() {
    memset(match, -1, sizeof(match)); // Ban đầu tất cả nhân viên đều rảnh
    int maxMatch = 0;

    // Duyệt qua từng công việc u từ 1 đến n
    for (int u = 1; u <= n; ++u) {
        memset(visited, false, sizeof(visited)); // Reset trạng thái thăm nhân viên
        if (dfs(u)) { // Nếu công việc u được gán thành công
            maxMatch++; // Tăng số lượng công việc được gán
        }
    }

    return maxMatch; // Trả về số lượng công việc được gán tối đa
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    inp();
    // Tìm ghép cặp tối đa và in ra kết quả
    cout << maximumMatching() << '\n';
    return 0;
}
