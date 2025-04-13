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
    vector<bool> flag;
    int n;

    void build(int v, int l, int r, const vector<int>& a) {
        if (r - l == 1) {
            tree[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, a);
        build(2 * v + 2, mid, r, a);
        tree[v] = tree[2 * v + 1];
    }


    SegTree(const vector<int>& a){
        n = len(a);
        tree.resize(4 * n, 0);
        laz.resize(4 * n, 0);
        flag.resize(4 * n, false);
        build(0, 0, n, a);
    }

    void push(int x, int lx, int rx){
        if (!flag[x]) return;
        if (rx - lx == 1) {
            flag[x] = false;
            return;
        }
        tree[2 * x + 1] = laz[x];
        tree[2 * x + 2] = laz[x];

        laz[2 * x + 1] = laz[x];
        laz[2 * x + 2] = laz[x];

        flag[2 * x + 1] = 1;
        flag[2 * x + 2] = 2;
        flag[x] = 0;
    }

    void set_val(int l, int r, int val, int x, int lx, int rx){
        push(x, lx, rx);
        if (l >= rx || r <= lx) return;

        if (l <= lx && rx <= r) {
            tree[x] = val;
            laz[x] = val;
            flag[x] = 1;
            return;
        }

        int m = (lx + rx) / 2;
        set_val(l, r, val, 2 * x + 1, lx, m);
        set_val(l, r, val, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1];
    }

    int get_val(int pos, int x, int lx, int rx){
        push(x, lx, rx);
        if (rx - lx == 1){
            return tree[x];
        }

        int m = (lx + rx) / 2;
        if (pos < m){
            return get_val(pos, 2 * x + 1, lx, m);
        } else {
            return get_val(pos, 2 * x + 2, m, rx);
        }
    }

    void set_val(int l, int r, int val){
        set_val(l, r, val, 0, 0, n);
    }

    int get_val(int pos){
        return get_val(pos, 0, 0, n);
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
        if (s == "set"){
            int l, r, val; cin >> l >> r >> val;
            st.set_val(l-1, r, val);
        } else {
            int pos; cin >> pos;
            cout << st.get_val(pos-1) << "\n";
        }
    }
}