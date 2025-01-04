#include <bits/stdc++.h>
using namespace std;

/*
Tóm tắt:
Code này tính tổng khoảng cách từ mỗi đỉnh đến tất cả các đỉnh khác trong một cây có trọng số. 
Sử dụng 2 pha:
1. DFS1: Tính tổng khoảng cách trong nhánh con và số đỉnh thuộc nhánh đó (d[u] và N[u]).
2. DFS2: Tính tổng khoảng cách từ đỉnh u đến tất cả các đỉnh khác (f[u]) bằng cách chuyển đổi từ d[u].
*/

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN]; // Danh sách kề (đỉnh, trọng số)
int p[MAXN]; // Đỉnh cha
long long d[MAXN]; // Tổng khoảng cách từ con cháu đến u
int N[MAXN]; // Số đỉnh trong nhánh của u
long long f[MAXN]; // Tổng khoảng cách từ u đến tất cả các đỉnh khác
int n; // Số đỉnh

// DFS1: Tính tổng khoảng cách (d[u]) và số lượng đỉnh trong nhánh (N[u])
void DFS1(int u) {
    for (auto [v, w] : adj[u]) { // Duyệt qua các đỉnh kề của u
        if (p[v] == 0) { // Nếu đỉnh v chưa được thăm
            p[v] = u; // Gán u là cha của v
            DFS1(v); // Đệ quy tính toán cho đỉnh con v
            
            // Cập nhật tổng khoảng cách d[u]:
            // d[v]: Tổng khoảng cách trong nhánh của v
            // N[v] * w: Khoảng cách từ tất cả các đỉnh trong nhánh của v đến u
            d[u] += d[v] + N[v] * w; 

            // Cập nhật số đỉnh trong nhánh N[u]: N[v] là số đỉnh trong nhánh của v
            N[u] += N[v];
        }
    }
}

// Phase1: Chuẩn bị các giá trị cơ bản d[u] và N[u] cho mỗi đỉnh
void Phase1() {
    for (int i = 1; i <= n; ++i) {
        p[i] = 0; // Ban đầu, chưa có đỉnh nào có cha
        d[i] = 0; // Tổng khoảng cách ban đầu là 0
        N[i] = 1; // Mỗi đỉnh là một nhánh riêng lẻ với 1 đỉnh
        f[i] = 0; // Khởi tạo giá trị f ban đầu
    }
    p[1] = 1; // Gốc của cây (đỉnh 1)
    DFS1(1); // Duyệt DFS1 từ gốc để tính d[u] và N[u]
}

// DFS2: Tính tổng khoảng cách f[v] từ u dựa vào công thức chuyển đổi
void DFS2(int u) {
    for (auto [v, w] : adj[u]) { // Duyệt qua các đỉnh kề của u
        if (p[v] == 0) { // Nếu đỉnh v chưa được thăm
            // Công thức tính f[v]:
            // f[u] - (d[v] + N[v] * w): Loại bỏ ảnh hưởng của nhánh v từ u
            // + (n - N[v]) * w: Cộng thêm ảnh hưởng của các đỉnh ngoài nhánh v
            f[v] = f[u] - N[v] * w + (n - N[v]) * w;

            p[v] = u; // Gán u là cha của v
            DFS2(v); // Đệ quy tính toán cho đỉnh con v
        }
    }
}

// Phase2: Tính giá trị f[u] cho tất cả các đỉnh
void Phase2() {
    for (int i = 1; i <= n; ++i) p[i] = 0; // Đặt lại cha của các đỉnh
    f[1] = d[1]; // Giá trị f tại gốc là d[1] (tổng khoảng cách từ gốc đến tất cả các đỉnh con)
    p[1] = 1; // Gốc của cây (đỉnh 1)
    DFS2(1); // Duyệt DFS2 từ gốc để tính f[u]
}

int main() {
    cin >> n; // Nhập số đỉnh trong cây
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Nhập cạnh nối hai đỉnh u và v với trọng số w
        adj[u].emplace_back(v, w); // Thêm cạnh (v, w) vào danh sách kề của u
        adj[v].emplace_back(u, w); // Thêm cạnh (u, w) vào danh sách kề của v
    }

    Phase1(); // Pha 1: Tính d[u] và N[u] cho mỗi đỉnh
    Phase2(); // Pha 2: Tính f[u] cho mỗi đỉnh

    // Tìm giá trị lớn nhất của f[u], tương ứng với đường đi dài nhất trên cây
    cout << *max_element(f + 1, f + n + 1) << endl;

    return 0;
}
