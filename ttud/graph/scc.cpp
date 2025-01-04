#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 4;

vector<int> adj[MAX]; // Danh sách kề
int num[MAX], low[MAX], timer = 0;
bool onStack[MAX]; // Kiểm tra đỉnh có nằm trong stack không
stack<int> s; // Stack lưu các đỉnh trong SCC
int sccCount = 0; // Đếm số SCC

void tarjanDFS(int u) {
    num[u] = low[u] = ++timer; // Gán thời gian vào
    s.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (num[v] == -1) { // Nếu v chưa được thăm
            tarjanDFS(v);
            low[u] = min(low[u], low[v]); // Kế thừa low[v]
        } else if (onStack[v]) { // Nếu v nằm trong stack
            low[u] = min(low[u], num[v]);
        }
    }

    // Nếu tìm thấy một SCC
    if (low[u] == num[u]) {
        // cout << "SCC " << ++sccCount << ": ";
        sccCount++;
        int v;
        do {
            v = s.top();
            s.pop();
            onStack[v] = false;
            // cout << v << " ";
        } while (v != u);
        // cout << endl;
    }
}

int main() {
    int n, m; // Số đỉnh và số cạnh
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Đồ thị có hướng
        adj[v].push_back(u);
    }

    // Khởi tạo
    fill(num, num + n + 1, -1);
    fill(low, low + n + 1, -1);
    fill(onStack, onStack + n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (num[i] == -1) {
            tarjanDFS(i);
        }
    }

    cout << sccCount << endl;
    return 0;
}
