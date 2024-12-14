#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n;
bool assigned[20];
int c[20][20];
int f_star = INT_MAX;
int f = 0;
int X[20];
int bestX[20];
int recursionCount = 0;

bool check(int v, int k) {
    return !assigned[v];
}

void solution() {
    if (f < f_star) {
        f_star = f;
        for (int i = 0; i < n; i++) {
            bestX[i] = X[i];
        }
    }
}

int g(int k) {
    int bound = f;

    for (int i = k + 1; i < n; i++) {
        int min_cost = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!assigned[j]) min_cost = min(min_cost, c[i][j]);
        }
        bound+=min_cost;
    }

    return bound;
}

void Try(int k) {
    recursionCount++; 

    for (int v = 0; v < n; v++) {
        if (check(v, k)) {
            assigned[v] = true;
            f += c[k][v];
            // ghi nhận Người k sẽ làm công việc v
            X[k] = v;

            if (k == n - 1) {
                solution();
            } else {
                if (g(k) < f_star) {
                    Try(k+1);
                }
            }

            f -= c[k][v];
            assigned[v] = false;
        }
    }
}

int main() {
    // Input dữ liệu
    cout << "Enter the number of employees/jobs: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    // Khởi tạo ban đầu
    for (int i = 0; i < n; i++) {
        assigned[i] = false;
    }

    // Gọi hàm giải
    Try(0);

    // Output lời giải tốt nhất
    cout << "Minimum cost: " << f_star << endl;
    cout << "Best assignment:\n";
    for (int i = 0; i < n; i++) {
        cout << "Person " << i+1 << " -> Job " << bestX[i]+1 << endl;
    }

     cout << "Number of recursive calls: " << recursionCount << endl;
    return 0;
}