#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = n;
        tree.assign(size * 4, 0);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) return tree[v];
        int mid = (tl + tr) / 2;
        return max(query(2*v+1, tl, mid, l, r), query(2*v+2, mid+1, tr, l, r));
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
            update(2*v+2, mid+1,r,pos,val);
        }
        tree[v] = max(tree[2*v+1], tree[2*v+2]);
    }

    int query(int l, int r) {
        return query(0,0,size-1,l,r);
    }

    void update(int pos, int val) {
        update(0,0,size-1,pos,val);
    }
};

int longestIdealString(string s, int k) {
    int n = s.size();
    SegTree segtree;
    const int MAXVALUE = 26;
    segtree.init(MAXVALUE+1);

    for (int i = 0; i < n; i++) {
        // l là val - k, val + k?
        int val = s[i] - 'a';
        int l = max(0, val -k);
        int r = min(MAXVALUE , val+k);
        segtree.update(val, segtree.query(l,r) + 1);
    }

    return segtree.query(0,MAXVALUE);
}

int main() {
    cout << longestIdealString("acfgbd",2 ) << endl;
    return 0;
}