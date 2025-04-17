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
    vector<int> tree_sum, tree_max, tree_min;
    vector<int> laz_add, laz_set;
    vector<bool> flag;
    int n;

    void build(int v, int l, int r, const vector<int>& a) {
        if (r - l == 1) {
            tree_sum[v] = tree_max[v] = tree_min[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, a);
        build(2 * v + 2, mid, r, a);
        tree_max[v] = max(tree_max[2 * v + 1], tree_max[2 * v + 2]);
        tree_min[v] = min(tree_min[2 * v + 1], tree_min[2 * v + 2]);
        tree_sum[v] = tree_sum[2 * v + 1] + tree_sum[2 * v + 2];
    }

    SegTree(const vector<int>& a) {
        n = len(a);
        tree_sum.resize(4 * n);
        tree_min.resize(4 * n);
        tree_max.resize(4 * n);
        laz_add.resize(4 * n);
        laz_set.resize(4 * n);
        flag.resize(4 * n);
        build(0, 0, n, a);
    }

    void push(int v, int l, int r) {
        if (r - l == 1) return;

        int mid = (l + r) / 2;
        if (flag[v]) {
            tree_sum[2 * v + 1] = laz_set[v] * (mid - l);
            tree_sum[2 * v + 2] = laz_set[v] * (r - mid);

            tree_max[2 * v + 1] = tree_min[2 * v + 1] = laz_set[v];
            tree_max[2 * v + 2] = tree_min[2 * v + 2] = laz_set[v];

            laz_set[2 * v + 1] = laz_set[2 * v + 2] = laz_set[v];
            laz_add[2 * v + 1] = laz_add[2 * v + 2] = 0;
            flag[2 * v + 1] = flag[2 * v + 2] = true;
        }
        if (laz_add[v]) {
            tree_sum[2 * v + 1] += laz_add[v] * (mid - l);
            tree_sum[2 * v + 2] += laz_add[v] * (r - mid);

            tree_min[2 * v + 1] += laz_add[v];
            tree_min[2 * v + 2] += laz_add[v];
            tree_max[2 * v + 1] += laz_add[v];
            tree_max[2 * v + 2] += laz_add[v];

            laz_add[2 * v + 1] += laz_add[v];
            laz_add[2 * v + 2] += laz_add[v];
        }
        laz_add[v] = 0;
        flag[v] = false;
    }

    void add(int l, int r, int val, int v, int lx, int rx) {
        push(v, lx, rx);
        if (l >= rx || r <= lx) return;
        if (l <= lx && rx <= r) {
            tree_sum[v] += val * (rx - lx);
            tree_max[v] += val;
            tree_min[v] += val;
            laz_add[v] += val;
            return;
        }

        int mid = (lx + rx) / 2;
        add(l, r, val, 2 * v + 1, lx, mid);
        add(l, r, val, 2 * v + 2, mid, rx);

        tree_max[v] = max(tree_max[2 * v + 1], tree_max[2 * v + 2]);
        tree_min[v] = min(tree_min[2 * v + 1], tree_min[2 * v + 2]);
        tree_sum[v] = tree_sum[2 * v + 1] + tree_sum[2 * v + 2];
    }

    void set(int l, int r, int val, int v, int lx, int rx) {
        push(v, lx, rx);
        if (l >= rx || r <= lx) return;
        if (l <= lx && rx <= r) {
            tree_sum[v] = val * (rx - lx);
            tree_max[v] = tree_min[v] = val;
            laz_set[v] = val;
            laz_add[v] = 0;
            flag[v] = true;
            return;
        }

        int mid = (lx + rx) / 2;
        set(l, r, val, 2 * v + 1, lx, mid);
        set(l, r, val, 2 * v + 2, mid, rx);

        tree_max[v] = max(tree_max[2 * v + 1], tree_max[2 * v + 2]);
        tree_min[v] = min(tree_min[2 * v + 1], tree_min[2 * v + 2]);
        tree_sum[v] = tree_sum[2 * v + 1] + tree_sum[2 * v + 2];
    }

    vector<int> get(int l, int r, int v, int lx, int rx) {
        push(v, lx, rx);
        if (l >= rx || r <= lx) return {0, inf, -inf};
        if (l <= lx && rx <= r) {
            return {tree_sum[v], tree_min[v], tree_max[v]};
        }

        int mid = (lx + rx) / 2;
        vector<int> left = get(l, r, 2 * v + 1, lx, mid);
        vector<int> right = get(l, r, 2 * v + 2, mid, rx);
        return {
                left[0] + right[0],
                min(left[1], right[1]),
                max(left[2], right[2])
        };
    }

    void add(int l, int r, int val) { add(l, r, val, 0, 0, n); }
    void set(int l, int r, int val) { set(l, r, val, 0, 0, n); }
    vector<int> get(int l, int r) { return get(l, r, 0, 0, n); }
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
        int l, r; cin >> l >> r;
        if (s == "add" || s == "set"){
            int val; cin >> val;
            if (s == "add") st.add(l-1, r, val);
            else st.set(l-1, r, val);
        } else {
            vector<int> ans = st.get(l-1, r);
            if (s == "sum") cout << ans[0];
            else if (s == "min") cout << ans[1];
            else cout << ans[2];
            cout << "\n";
        }
    }
}