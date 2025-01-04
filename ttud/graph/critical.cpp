/*
Tóm tắt:
- Tính thời gian hoàn thành sớm nhất (earliest) và muộn nhất (latest) cho toàn bộ dự án.
- Tìm Critical Path: Các công việc có slack = 0 (không có thời gian dư dả).
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005; 
const int MAXM = 200005; 

int n, m;                       
int duration[MAXN];             
vector<int> adj[MAXN], rev_adj[MAXN]; 
bool visited[MAXN];             
vector<int> topo_order;         
int earliest[MAXN], latest[MAXN]; 

void readInput() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> duration[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // Tạo danh sách kề ngược
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfs(v);
    topo_order.push_back(u);
}

void calculateEarliest() {
    for (int i = 1; i <= n; ++i) earliest[i] = duration[i];
    reverse(topo_order.begin(), topo_order.end());
    for (int u : topo_order) 
        for (int v : adj[u]) 
            earliest[v] = max(earliest[v], earliest[u] + duration[v]);
}

void calculateLatest(int max_time) {
    for (int i = 1; i <= n; ++i) latest[i] = max_time;
    for (int u : topo_order) 
        for (int v : rev_adj[u]) 
            latest[v] = min(latest[v], latest[u] - duration[v]);
}

vector<int> findCriticalPath() {
    vector<int> criticalPath;
    for (int i = 1; i <= n; ++i) {
        if (earliest[i] == latest[i]) {
            criticalPath.push_back(i);
        }
    }
    return criticalPath;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    readInput();

    for (int i = 1; i <= n; ++i) if (!visited[i]) dfs(i);
    calculateEarliest();
    int max_time = *max_element(earliest + 1, earliest + n + 1);
    calculateLatest(max_time);

    vector<int> criticalPath = findCriticalPath();
    cout << "Critical Path: ";
    for (int u : criticalPath) cout << u << " ";
    cout << endl;

    cout << "Project Completion Time: " << max_time << '\n';

    return 0;
}
