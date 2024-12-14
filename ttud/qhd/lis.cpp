#include <bits/stdc++.h>
using namespace std;

// int LIS(vector<int>& a) {
//     int n = a.size();
//     // LIS trong đoạn từ 0 -> i - 1: dp[i];
//     vector<int> dp(n, 1);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (a[i] > a[j]) {
//                 // nối a[i] vào LIS a[j];
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     return *max_element(dp.begin(), dp.end());
// }

struct SegTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) return tree[v];
        int mid = (tl+tr) /2;
        return max(query(2*v+1, tl, mid, l,r), query(2*v+2, mid+1,tr, l,r));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v] = val;
            return;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(2*v+1, tl, mid, pos, val);
        } else {
            update(2*v+2, mid + 1, tr, pos, val);
        }
        tree[v] = max(tree[2*v + 1], tree[2 * v + 2]);
    }

    int query(int l, int r) {
        return query(0, 0, size - 1,l,r);
    }

    void update(int pos, int val) {
        update(0, 0, size - 1, pos, val);
    }
};

int lengthOfLIS(vector<int>& a) {
    int n = a.size();
    const int OFFSET = 1e4;
    int MAXVALUE = 2 * OFFSET;
    SegTree segTree;
    segTree.init(MAXVALUE + 1);

    for (int i = 0; i < n; i++) {
        int val = a[i] + OFFSET;
        int l = 0; int r = val - 1;
        int maxDpJ = segTree.query(l,r);
        segTree.update(val, maxDpJ + 1);
    }

    return segTree.query(0, MAXVALUE);
}

int main() {
    vector<int> arr = {-2,-1};
    cout << lengthOfLIS(arr) << endl;
}