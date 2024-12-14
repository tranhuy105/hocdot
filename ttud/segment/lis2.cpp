/*
Đề bài:
- Cho một mảng số nguyên `a` gồm `n` phần tử và một số nguyên `k`.
- Một dãy con tăng thỏa mãn điều kiện: |b[i+1] - b[i]| <= k với mọi cặp phần tử liên tiếp trong dãy.
- Nhiệm vụ: Tìm độ dài lớn nhất của một dãy con tăng thỏa mãn điều kiện trên.
- Ràng buộc:
  + 1 <= n <= 10^5
  + 1 <= k <= 10^5
  + 1 <= a[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = n;
        tree.assign(4*size, 0);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) return tree[v];

        int mid = (tl + tr) / 2;
        return max(query(2*v+1, tl, mid, l, r), query(2*v+2, mid + 1, tr, l, r));
    }

    int query(int l, int r) {
        return query(0,0,size-1, l, r);
    }

    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            tree[v] = val;
            return;
        }
        int mid = (l+r) / 2;
        if (pos <= mid) {
            update(2*v+1, l, mid, pos, val);
        } else {
            update(2*v+2, mid+1, r, pos, val);
        }
        tree[v] = max(tree[2*v+1], tree[2*v+2]);
    }

    void update(int pos, int val) {
        return update(0,0,size-1, pos, val);
    }
};

int lengthOfLIS(vector<int>& a, int k) {
    int n = a.size();
    SegmentTree segTree;
    int maxVal = *max_element(a.begin(), a.end());
    segTree.init(maxVal + 1);

    // cần tìm dp[j] lớn nhất trong khoảng a[i] -k đến a[i] - 1;
    for (int i = 0; i < n; i++) {
        int l = max(0, a[i] - k); int r = a[i] - 1;
        int max_length = segTree.query(l, r);
        segTree.update(a[i], max_length+ 1);
    }

    return segTree.query(0, maxVal);
}

int main() {
    vector<int> arr = {1,100,500,100000,100000}; int k = 100000;
    cout << lengthOfLIS(arr, k) << endl;
    return 0;
}