#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 4;
vector<int> adj[MAX];
int n, m; // Số đỉnh và số cạnh
int num[MAX], low[MAX], cnt = 0;
int bridge = 0, articulation = 0;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Đồ thị vô hướng
    }
}

void dfs(int u, int p) {
    num[u] = low[u] = ++cnt;
    int node = (p != 0); // Đếm số con trực tiếp của u
    for (int v : adj[u]) if (v != p) {
        if (num[v]) {
            // Nếu v đã được thăm, cập nhật low[u] qua cạnh ngược
            low[u] = min(low[u], num[v]);
        } else {
            // Nếu v chưa được thăm, duyệt DFS vào v
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            // Kiểm tra cầu
            if (low[v] == num[v]) {
                bridge++;
                cout << "Bridge: " << u << " - " << v << endl;
            }
            // Kiểm tra đỉnh khớp
            if (low[v] >= num[u]) node++;
        }
    }
    // Nếu u là đỉnh khớp
    if (node >= 2) {
        articulation++;
        cout << "Articulation Point: " << u << endl;
    }
}

int main() {
    inp();
    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i, 0); // DFS từ mỗi đỉnh chưa được thăm
    }
    cout << articulation << bridge << endl;
    return 0;
}
