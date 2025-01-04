#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005; // Giới hạn số đỉnh

vector<pair<int, int>> adj[MAXN]; // Danh sách kề (đỉnh, trọng số)
int d[MAXN]; // Khoảng cách từ đỉnh gốc

typedef long long ll;

// Khởi tạo khoảng cách
void Init(int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = -1; // Đặt khoảng cách ban đầu là -1 (chưa thăm)
    }
}

// Hàm DFS để tìm khoảng cách xa nhất từ đỉnh u
void DFS(int u) {
    for (auto [v, w] : adj[u]) {
        if (d[v] < 0) { // Nếu đỉnh v chưa được thăm
            d[v] = d[u] + w; // Cập nhật khoảng cách đến v
            DFS(v); // Đệ quy thăm đỉnh v
        }
    }
}

// Tìm đường đi dài nhất trên cây
void LongestPathOnTree(int n) {
    // Bước 1: Khởi tạo và thực hiện DFS từ một đỉnh bất kỳ (đỉnh 1)
    Init(n);
    d[1] = 0; // Đặt khoảng cách đến đỉnh 1 là 0
    DFS(1);

    // Tìm đỉnh x xa nhất từ đỉnh 1
    int x = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[x]) {
            x = i;
        }
    }

    // Bước 2: Khởi tạo lại và thực hiện DFS từ đỉnh x
    Init(n);
    d[x] = 0; // Đặt khoảng cách đến x là 0
    DFS(x);

    // Tìm đỉnh y xa nhất từ x và khoảng cách dài nhất
    int y = x;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[y]) {
            y = i;
        }
    }

    // Kết quả: Đường đi dài nhất từ x đến y
    cout << "Longest path distance (tree diameter): " << d[y] << endl;
}

int main() {
    int n; // Số đỉnh
    cin >> n;

    // Nhập cây (n-1 cạnh)
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Gọi hàm tìm đường đi dài nhất
    LongestPathOnTree(n);

    return 0;
}
