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
    vector<int> t; 

    void build(int v, int s, int e, const vector<int>& a) {
        if (s == e) {
            t[v] = (a[s] == 0) ? 1 : 0;
            return;
        }
        int mid = (s + e) / 2;
        build(2 * v + 1, s, mid, a);
        build(2 * v + 2, mid + 1, e, a);
        t[v] = t[2 * v + 1] + t[2 * v + 2]; 
    }

    SegTree(const vector<int>& a) {
        n = len(a);
        t.resize(4 * n);
        build(0, 0, n-1, a);
    }

    void set(int v, int l, int r, int idx, int val) {
        if (l == r){
            t[v] = (val == 0) ? 1 : 0;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= idx && idx <= mid){
            set(2 * v + 1, l, mid, idx, val);
        } else {
            set(2 * v + 2, mid + 1, r, idx, val);
        }
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void set(int idx, int val) {
        set(0, 0, n-1, idx, val);
    }

    int get(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql){
            return 0;
        } if (ql <= l && r <= qr){
            return t[v];
        } 
        int mid = (l + r) / 2;
        return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 2, mid + 1, r, ql, qr);
    }

    int get(int ql, int qr, int k) {
        int ans = get(0, 0, n-1, ql, qr);
        if (ans < k) {return -1;}


        int left = ql, right = qr;
        while (right > left){
            int mid = (right + left) / 2;
            if (get(0, 0, n-1, ql, mid) < k){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    SegTree st(arr);
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        string com; cin >> com;
        if (com == "s") {
            int l, r, k; cin >> l >> r >> k; 
            int ans = st.get(l-1, r-1, k);
            cout << (ans == -1 ? -1 : ans + 1) << " ";
        } else {
            int idx, val; cin >> idx >> val;
            st.set(idx - 1, val); 
        }
    }
}