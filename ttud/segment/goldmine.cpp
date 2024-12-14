/*
Đề bài:
Vương quốc ALPHA có `n` kho vàng nằm trên một đường thẳng và được đánh số từ 1 đến `n`. Kho thứ `i` chứa số lượng vàng `ai` và tọa độ của nó là `i`. 
Vua của ALPHA mở cuộc thi cho các thợ săn để tìm một tập con các kho vàng sao cho:
- Tổng lượng vàng trong tập con là lớn nhất.
- Khoảng cách giữa hai kho được chọn phải thỏa mãn: `L1 ≤ khoảng cách ≤ L2`.

Yêu cầu:
Tìm tổng lượng vàng lớn nhất có thể đạt được thỏa mãn các điều kiện trên.

Đầu vào:
- Dòng đầu tiên chứa 3 số nguyên `n`, `L1`, `L2` (`1 ≤ n ≤ 1000000`, `1 ≤ L1 ≤ L2 ≤ n`).
- Dòng thứ hai chứa `n` số nguyên `a1, a2, ..., an` đại diện cho số lượng vàng trong mỗi kho (mỗi số không âm).

Đầu ra:
- Một số nguyên duy nhất là tổng lượng vàng lớn nhất có thể đạt được.

Ví dụ:
Input:
6 2 3
3 5 9 6 7 4

Output:
19

Giải thích:
- Chọn kho thứ 2 và kho thứ 5, tổng lượng vàng là `5 + 7 = 19`.
- Khoảng cách giữa kho thứ 2 và kho thứ 5 là `5 - 2 = 3`, thỏa mãn điều kiện `2 ≤ khoảng cách ≤ 3`.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;

int n, l1, l2;
vector<int> a;

struct SegmentTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = n;
        tree.assign(4 * n, -INF);
    }

    void update(int pos, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(pos, val, 2 * node + 1, start, mid);
            } else {
                update(pos, val, 2 * node + 2, mid + 1, end);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int l, int r, int node, int start, int end) {
        // trường hợp tìm max min
        if (l > end || r < start) return -INF;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(query(l, r, 2 * node + 1, start, mid), 
                   query(l, r, 2 * node + 2, mid + 1, end));
    }

    void update(int pos, int val) {
        update(pos, val, 0, 0, size - 1);
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }
};

void solve() {
    cin >> n >> l1 >> l2;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree segTree;
    segTree.init(n);
    vector<int> dp(n, -INF);

    for (int i = 0; i < n; i++) {
        // l1 <= i -j < l2 -> j thuoc [i-l2, i-l1]
        if (i - l1 >= 0) {
            int l = max(0, i - l2);
            int r = i - l1;
            int max_val = segTree.query(l, r);
            dp[i] = max(dp[i], max_val + a[i]);
        } else {
            dp[i] = a[i];
        }
        segTree.update(i, dp[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    solve();
    return 0;
}
