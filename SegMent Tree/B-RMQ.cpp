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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 1e2;

vector<int> c(maxn + 1);
vector<int> pred(maxn, -1);

struct SegTree {
    int n; 
    vector<pair<int,int>> t;

    void build(int v, int l, int r, const vector<int>& a) {
        if (r - l == 1) {
            t[v] = {a[l], l}; 
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, a);
        build(2 * v + 2, mid, r, a);
        if (t[2 * v + 1].first > t[2 * v + 2].first) {
            t[v] = t[2 * v + 1];
        } else {
            t[v] = t[2 * v + 2];
        }
    }

    SegTree(const vector<int>& a) {
        n = len(a);
        t.resize(4 * n);
        build(0, 0, n, a);
    }

    pair<int,int> get(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return {-inf, -1}; 
        } 
        if (ql <= l && r <= qr) {
            return t[v]; 
        }
        int mid = (l + r) / 2;
        pair<int,int> el1 = get(2 * v + 1, l, mid, ql, qr);
        pair<int,int> el2 = get(2 * v + 2, mid, r, ql, qr);
        if (el1.first > el2.first) {
            return el1; 
        } else {
            return el2; 
        }
    }

    pair<int,int> get(int ql, int qr) {
        return get(0, 0, n, ql, qr);
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int el; cin >> el; arr.emp(el);
    }
    
    int k; cin >> k; 
    SegTree st(arr); 
    for (int i = 0; i < k; ++i) {
        int l, r; 
        cin >> l >> r; 
        pair<int,int> ans = st.get(l-1, r); 
        cout << ans.first << " " << ans.second + 1 << "\n"; 
    }
}