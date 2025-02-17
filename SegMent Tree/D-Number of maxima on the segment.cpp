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
    
    void build(int v, int l, int r, const vector<int>& arr){
        if (r - l == 1){
            t[v] = {arr[l], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, arr);
        build(2 * v + 2, mid, r, arr);
        if (t[2 * v + 1].first == t[2 * v + 2].first){
            t[v] = {t[2 * v + 1].first, t[2 * v + 1].second + t[2 * v + 2].second};
        } else {
            t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    SegTree(const vector<int>& arr) {
        n = len(arr);
        t.resize(4 * n);
        build(0, 0, n, arr);
    }

    void set(int v, int l, int r, int idx, int val){
        if (r - l == 1){
            t[v] = {val, 1};
            return;
        }
        int mid = (l + r) / 2;
        if (idx < mid){
            set(2 * v + 1, l, mid, idx, val);
        } else {
            set(2 * v + 2, mid, r, idx, val);
        }
        if (t[2 * v + 1].first == t[2 * v + 2].first){
            t[v] = {t[2 * v + 1].first, t[2 * v + 1].second + t[2 * v + 2].second};
        } else {
            t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void set(int idx, int val){
        set(0, 0, n, idx, val);
    }

    pair<int,int> get(int v, int l, int r, int ql, int qr){
        if (qr <= l || r <= ql){
            return {-inf, 0};
        } 
        if (ql <= l && r <= qr){
            return t[v];
        }
        int mid = (l + r) / 2;
        pair<int,int> el = get(2 * v + 1, l, mid, ql, qr);
        pair<int,int> el1 = get(2 * v + 2, mid, r, ql, qr);
        if (el.first == el1.first) {
            return {el.first, el.second + el1.second};
        } else {
            return max(el, el1);
        }
    }

    pair<int,int> get(int ql, int qr){
        return get(0, 0, n, ql, qr);
    }
};


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    SegTree st(arr);
    int q; cin >> q;
    for (int i = 0; i < q; ++i){
        string com; cin >> com;
        int l, r; cin >> l >> r;
        if (com == "A"){
            st.set(l - 1, r);
        } else {
            cout << st.get(l - 1, r).second << " ";
        }
    }
}