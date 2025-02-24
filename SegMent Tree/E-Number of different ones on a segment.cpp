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
const int maxn = 1e5;
const int max_el = 41;

vector<int> c(maxn + 1);
vector<int> pred(maxn, -1);
vector<int> t[4 * maxn];
vector<int> arr(maxn);

void build(int v, int l, int r) {
    if(l == r) {
        t[v] = vector<int>(max_el, 0);
        t[v][arr[l]] = 1;
        return;
    }
    
    int mid = (l + r) / 2;
    build(2*v, l, mid);
    build(2*v+1, mid+1, r);
    
    t[v] = vector<int>(max_el, 0);
    for(int i = 1; i < max_el; i++) {
        t[v][i] = t[2*v][i] + t[2*v+1][i];
    }
}

void setter(int v, int l, int r, int idx, int old, int val) {
    if(l > idx || r < idx) return;
    
    t[v][old]--;
    t[v][val]++;
    
    if(l != r) {
        int mid = (l + r) / 2;
        setter(2*v, l, mid, idx, old, val);
        setter(2*v+1, mid+1, r, idx, old, val);
    }
}

vector<int> getter(int v, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) {
        return vector<int>(max_el, 0);
    }
    
    if(ql <= l && r <= qr) {
        return t[v];
    }
    
    int mid = (l + r) / 2;
    vector<int> left = getter(2*v, l, mid, ql, qr);
    vector<int> right = getter(2*v+1, mid+1, r, ql, qr);
    
    vector<int> res(max_el, 0);
    for(int i = 1; i < max_el; i++) {
        res[i] = left[i] + right[i];
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n-1);
    int k; cin >> k;
    for (int q = 0; q < k; ++q) {
        string com; cin >> com;
        
        if(com == "A") {
            int i, val; cin >> i >> val;
            i--;
            int old = arr[i];
            arr[i] = val;
            setter(1, 0, n-1, i, old, val);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            vector<int> result = getter(1, 0, n-1, l, r);
            int count = 0;
            for(int i = 1; i < max_el; i++) {
                if(result[i] > 0) count++;
            }
            cout << count << "\n";
        }
    }
}