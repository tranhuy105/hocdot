#include <bits/stdc++.h>
using namespace std;

const int maxn = 1004;

int n, m;
vector<int> adj[maxn];
vector<int> topo;
int color[maxn]; // Mảng màu: 0 = trắng, 1 = xám, 2 = đen

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

bool hasCycle(int u) {
    color[u] = 1; // Đánh dấu đỉnh đang được xử lý (xám)
    for (int v : adj[u]) {
        if (color[v] == 1) return true; // Phát hiện chu trình
        if (color[v] == 0 && hasCycle(v)) return true; // DFS đỉnh chưa thăm
    }
    color[u] = 2; // Đánh dấu đỉnh đã xử lý xong (đen)
    return false;
}

void topoSort(int u) {
    color[u] = 1; // Đang xử lý
    for (int v : adj[u]) {
        if (color[v] == 0) {
            topoSort(v);
        }
    }
    color[u] = 2; // Xử lý xong
    topo.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    inp();

    // Kiểm tra chu trình
    fill(color, color + maxn, 0);
    bool cycle = false;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && hasCycle(i)) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout << "Graph has a cycle. Topological sort is not possible.\n";
        return 0;
    }

    // Sắp xếp topo
    fill(color, color + maxn, 0);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            topoSort(i);
        }
    }

    reverse(topo.begin(), topo.end());
    for (int it : topo) cout << it << " ";
    cout << endl;

    return 0;
}
