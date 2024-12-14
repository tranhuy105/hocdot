/*
Đề bài:
Bài toán người du lịch (Travelling Salesman Problem - TSP): 
Cho một đồ thị hoàn chỉnh với `n` đỉnh, mỗi cạnh giữa hai đỉnh có chi phí di chuyển nhất định. 
Nhiệm vụ là tìm hành trình ngắn nhất xuất phát từ đỉnh 1, đi qua mỗi đỉnh đúng một lần, và quay lại đỉnh ban đầu.

Đầu vào:
- Một số nguyên `n` (số lượng đỉnh, 1 ≤ n ≤ 20).
- Một ma trận `cost[i][j]` (kích thước `n x n`) trong đó `cost[i][j]` là chi phí di chuyển từ đỉnh `i` đến đỉnh `j`.

Đầu ra:
- Chi phí tối thiểu để hoàn thành hành trình.
- Dãy đỉnh của hành trình tốt nhất.

Ví dụ:
Input:
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Output:
The minimum cost is: 80
The best path is: 1 2 4 3 1

Giải thích:
- Xuất phát từ đỉnh 1.
- Lộ trình tối ưu là 1 → 2 → 4 → 3 → 1 với chi phí tổng là 80.
*/


#include <iostream>
#include <climits>
using namespace std;

int n;
bool visited[20];
int cost[20][20];
int path[20];
int bestPath[20];
int f = 0;
int f_star = INT_MAX;

bool check(int v, int k) {
    return !visited[v];
}

int calculateBound() {
    int bound = f;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int min_path = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (i != j ) min_path = std::min(min_path, cost[i][j]);
            }
            bound += min_path;
        }
    }
    return bound;
}

void solution() {
    int totalCost = f + cost[path[n-1]][path[0]];
    if (totalCost < f_star) {
        f_star = totalCost;
        for (int i = 0; i < n; i++) {
            bestPath[i] = path[i];
        }
    }
}

void Try(int k){
    for (int v = 0; v < n; v++) {
        if(check(v, k)) {
            path[k] = v;
            visited[v] = true;
            f += cost[path[k-1]][v];

            if (k == n-1) {
                solution();
            } else {
                int bound = calculateBound();
                if (bound < f_star) {
                    Try(k+1);
                }
            }

            visited[v] = false;
            f -= cost[path[k-1]][v];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    path[0] = 0;
    visited[0] = true;
    for (int i = 1; i < n; i++) visited[i] =false;

    Try(1);

    cout << "The minimum cost is: " << f_star << endl;
    cout << "The best path is: ";
    for (int i = 0; i < n; i++) {
        cout << bestPath[i]+1 << " ";
    }
    cout << bestPath[0]+1 << endl;

    return 0;

}