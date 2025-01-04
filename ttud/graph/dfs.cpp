#include <bits/stdc++.h>
using namespace std;

const int maxn = 1004;

int n; int m;
vector<int> adj[maxn];
int visited[maxn];

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void dfs2(int u) {
    stack<int> s;
    s.push(u);

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (!visited[top]) { 
            visited[top] = true; // Đánh dấu đã thăm khi xử lý
            cout << top << " "; // Xử lý đỉnh (in ra)

            for (int v : adj[top]) {
                if (!visited[v]) {
                    s.push(v); // Đẩy các đỉnh kề chưa thăm vào stack
                }
            }
        }
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    inp();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs2(i);
        }
    }

    return 0;
}
