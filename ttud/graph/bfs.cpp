#include <bits/stdc++.h>
using namespace std;

const int maxn = 1004;

int n, m;
vector<int> adj[maxn];
int visited[maxn];

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, 0, sizeof(visited));
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " "; // In ra đỉnh đang duyệt

        for (int v : adj[top]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    inp();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            cout << endl; // Xuống dòng nếu đồ thị không liên thông
        }
    }

    return 0;
}
