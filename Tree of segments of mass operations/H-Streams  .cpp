//#define _GLIBCXX_DEBUG
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdio.h>
#include <strstream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <deque>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back
#define ins insert

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 1e5;
const int logn = 20;


struct SegTree {
    int n, k;
    vector<int> tree, laz;

    SegTree(int size_n, int cap){
        n = size_n;
        k = cap;
        tree.resize(4 * n, 0);
        laz.resize(4 * n, 0);
    }

    void push(int v, int l, int r){
        if (laz[v] == 0) return;
        tree[v] += laz[v];
        if (r - l > 1){
            laz[2 * v + 1] += laz[v];
            laz[2 * v + 2] += laz[v];
        }
        laz[v] = 0;
    }

    void add(int l, int r, int v, int lx, int rx){
        push(v, lx, rx);
        if (l >= rx || r <= lx) return;
        if (l <= lx && r >= rx) {
            ++laz[v];
            push(v, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        add(l, r, 2 * v + 1, lx, mid);
        add(l, r, 2 * v + 2, mid, rx);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }

    int get(int l, int r, int v, int lx, int rx){
        push(v, lx, rx);
        if (l >= rx || r <= lx) return 0;
        if (l <= lx && r >= rx) {
            return tree[v];
        }
        int mid = (lx + rx) / 2;
        int left = get(l, r, 2 * v + 1, lx, mid);
        int right = get(l, r, 2 * v + 2, mid, rx);
        return max(left, right);
    }

    bool check(int l, int r){
        return get(l, r, 0, 0, n) < k;
    }

    void add(int l, int r){
        add(l, r, 0, 0, n);
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> k >> m;

    SegTree st(n, k);
    for (int i = 0; i < m; ++i){
        int l, r; cin >> l >> r;
        if (st.check(l, r)){
            cout << 1 << "\n";
            st.add(l, r);
        } else {
            cout << 0 << "\n";
        }
    }
}