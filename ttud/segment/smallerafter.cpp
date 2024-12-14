#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int OFFSET = 1e4;
const int MAX_VAL = 2 * OFFSET; 

struct SegmentTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0; // No overlap
        if (l <= tl && tr <= r) return tree[v]; // Full overlap

        int mid = (tl + tr) / 2;
        return query(2*v+1, tl, mid, l, r) + query(2*v+2, mid + 1, tr, l, r);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v] += val;
            return;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(2*v+1, tl, mid, pos, val);
        } else {
            update(2*v+2, mid + 1, tr, pos, val);
        }
        tree[v] = tree[2*v + 1] + tree[2 * v + 2];
    }

    ll query(int l, int r) {
        return query(0, 0, size - 1,l,r);
    }

    void update(int pos, int val) {
        update(0, 0, size - 1, pos, val);
    }
};

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    SegmentTree segTree;
    segTree.init(MAX_VAL + 1);
    for (int i = n - 1; i >= 0; --i) {
        int num = nums[i] + OFFSET;
        res[i] = segTree.query(0, num - 1);
        segTree.update(num, 1);
    }

    return res;
}

int main() {
    vector<int> arr = {5,2,6,1};
    for (auto n : countSmaller(arr)) cout << n << " ";
    cout << endl;
    return 0;
}