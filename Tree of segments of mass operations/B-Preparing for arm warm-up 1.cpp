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
const int maxn = 20;
const int logn = 20;

struct SegTree {
    vector<int> tree, laz;
    int n;

    void build(int v, int l, int r, const vector<int>& a) {
        if (r - l == 1) {
            tree[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, a);
        build(2 * v + 2, mid, r, a);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }


    SegTree(const vector<int>& a){
        n = len(a);
        tree.resize(4 * n);
        laz.resize(4 * n);
        build(0, 0, n, a);
    }

    void push(int x, int lx, int rx){
        if (rx - lx == 0) return;
        if (rx - lx > 1){
            int mid = (rx + lx) / 2;
            laz[2 * x + 1] += laz[x];
            laz[2 * x + 2] += laz[x];
            tree[2 * x + 1] += laz[x] * (mid - lx);
            tree[2 * x + 2] += laz[x] * (rx - mid);
        }
        laz[x] = 0;
    }

    void add_val(int l, int r, int val, int x, int lx, int rx){
        push(x, lx, rx);
        if (l >= rx || r <= lx) return;

        if (l <= lx && rx <= r) {
            tree[x] += val * (rx - lx);
            laz[x] += val;
            return;
        }

        int m = (lx + rx) / 2;
        add_val(l, r, val, 2 * x + 1, lx, m);
        add_val(l, r, val, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int get_sum(int l, int r, int x, int lx, int rx){
        push(x, lx, rx);
        if (l >= rx || r <= lx) return 0;
        if (l <= lx && r >= rx) return tree[x];

        int m = (lx + rx) / 2;
        return get_sum(l, r, 2 * x + 1, lx, m) +
               get_sum(l, r, 2 * x + 2, m, rx);
    }

    int get_sum(int l, int r){
        return get_sum(l, r, 0, 0, n);
    }

    void add_val(int l, int r, int val){
        add_val(l, r, val, 0, 0, n);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }

    SegTree st(arr);

    int q; cin >> q;
    for (int _ = 0; _ < q; ++_){
        string s; cin >> s;
        if (s == "sum"){
            int l, r; cin >> l >> r;
            cout << st.get_sum(l-1, r) << "\n";
        } else {
            int l, r, val; cin >> l >> r >> val;
            st.add_val(l-1, r, val);
        }
    }
}