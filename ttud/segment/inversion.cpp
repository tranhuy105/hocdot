#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
const int MODULO = 1e9 + 7;
vector<int> segTree(4 * MAX, 0);

void update(int v, int l, int r, int pos, int value) {
    if (l == r) {
        segTree[v] += value;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * v, l, mid, pos, value);
    } else {
        update(2 * v + 1, mid + 1, r, pos, value);
    }
    segTree[v] = segTree[2 * v] + segTree[2 * v + 1];
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return segTree[v];
    int mid = (tl + tr) / 2;
    return query(2*v, tl, mid, l, min(r, mid)) + query(2*v + 1, mid + 1, tr, max(l, mid + 1), r);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int maxVal = *max_element(a.begin(), a.end());
    long long count = 0;

    // Duyệt từ phải sang trái
    for (int i = n - 1; i >= 0; i--) {
        // Đếm số phần tử nhỏ hơn a[i], a[i] có thể nằm trong khoảng từ 0 đến maxVal;
        count += query(1, 0, maxVal, 0, a[i] - 1);
        // Ghi nhận a[i] vào cây phân đoạn
        update(1, 0, maxVal, a[i], 1);
    }

    cout << count % MODULO << endl;
}

int main() {
    solve();
    return 0;
}
