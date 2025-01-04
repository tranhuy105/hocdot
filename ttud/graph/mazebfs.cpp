#include <bits/stdc++.h>
using namespace std;

const int maxn = 1004;

int a[maxn][maxn];
int d[maxn][maxn]; // Mảng lưu số bước
int n, m, r, c;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void inp() {
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = -1; // Khởi tạo mảng d
        }
    }
}

int maze(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    d[r][c] = 0; // Điểm bắt đầu

    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = top.first + dx[i];
            int newY = top.second + dy[i];

            // Nếu vượt biên, nghĩa là đã thoát
            if (newX <= 0 || newX > n || newY <= 0 || newY > m) {
                return d[top.first][top.second] + 1; // Trả về số bước
            }

            // Nếu ô trống và chưa được thăm
            if (a[newX][newY] == 0 && d[newX][newY] == -1) {
                d[newX][newY] = d[top.first][top.second] + 1; // Cập nhật số bước
                q.push({newX, newY});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    inp();
    cout << maze(r, c) << endl;

    return 0;
}
