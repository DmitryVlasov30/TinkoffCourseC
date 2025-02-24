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

    SegTree (int size_arr) {
        n = size_arr;
        t.resize(4 * n);
    }

    void set(int v, int l, int r, int idx, int val){
        if (r - l == 1){
            t[v] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= idx && idx <= mid){
            set(2 * v + 1, l, mid, idx, val);
        } else {
            set(2 * v + 2, mid, r, idx, val);
        }
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void set(int idx, int val){
        set(0, 0, n, idx, val);
    }

    int get(int v, int l, int r, int ql, int qr){
        if (qr <= l || r <= ql){
            return 0;
        } 
        if (ql <= l && r <= qr){
            return t[v];
        }
        int mid = (l + r) / 2;
        return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 2, mid, r, ql, qr);
    }

    int get(int ql, int qr){
        return get(0, 0, n, ql, qr);
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0; cin >> n;
    SegTree st(n);
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el; arr.emp(el);
    }
    vector<int> sorted_arr = arr;
    sort(all(sorted_arr));
    for (int i = 0; i < n; ++i){
        arr[i] = lower_bound(all(sorted_arr), arr[i]) - sorted_arr.begin();
    }

    for (int i = n - 1; i >= 0; --i){
        ans += st.get(0, arr[i]);
        st.set(arr[i], 1);
    }    
    cout << ans;
}