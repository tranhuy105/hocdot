#include <bits/stdc++.h>
using namespace std;

const int maxn = 1004;

int n, m;
vector<int> adj[maxn];
int visited[maxn];
int color[maxn];

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Nếu là đồ thị vô hướng
    }

    memset(visited, 0, sizeof(visited));
    fill(color, color + maxn, 0);
}

bool chutrinhdothicohuong(int u) {
    color[u] = 1; // Đang xử lý
    for (int v : adj[u]) {
        if (color[v] == 1) return true; // Cạnh ngược (chu trình)
        if (color[v] == 0 && chutrinhdothicohuong(v)) return true;
    }
    color[u] = 2; // Đã xử lý xong
    return false;
}

bool chutrinhdothivohuong(int u, int p) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (chutrinhdothivohuong(v, u)) return true;
        } else if (v != p) { // Nếu đỉnh đã thăm và không phải đỉnh cha
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    inp();

    // Kiểm tra chu trình đồ thị có hướng
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && chutrinhdothicohuong(i)) {
            cout << "Chu trình có hướng\n";
            return 0;
        }
    }
    cout << "Không có chu trình có hướng\n";

    // Kiểm tra chu trình đồ thị vô hướng
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && chutrinhdothivohuong(i, -1)) {
            cout << "Chu trình vô hướng\n";
            return 0;
        }
    }
    cout << "Không có chu trình vô hướng\n";

    return 0;
}
