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
    void build(int v, int l, int r, const vector<int>& a){
        if (r - l == 1){
            t[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid, a);
        build(2 * v + 2, mid, r, a);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegTree (const vector<int>& a){
        n = len(a);
        t.resize(4 * n);
        build(0, 0, n, a);
    }

    void set(int v, int l, int r, int idx, int val){
        if (r - l == 1){
            t[v] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx < mid){
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
    int n, k; cin >> n >> k;
    vector<int> arr(n, 0);
    SegTree st(arr);
    for (int i = 0; i < k; ++i){
        string com; cin >> com;
        int a, b; cin >> a >> b;
        if (com == "A"){
            st.set(a-1, b);
        } else {
            cout << st.get(a-1, b) << "\n";
        }
    }
}