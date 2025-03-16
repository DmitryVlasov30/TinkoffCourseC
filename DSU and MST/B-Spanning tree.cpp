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
const int maxn = 2e5 + 1;
const int logn = 20;

struct Edge {
    int a, b, w;
};

vector<Edge> g;
int timer = 0;
vector<int> used(maxn, 0), color(maxn, 0);
vector<int> rk(maxn, 0), p(maxn);

bool comp(Edge a, Edge b){
    return a.w < b.w;
}

int get_root(int i){
    if (p[i] == i){
        return i;
    }
    return p[i] = get_root(p[i]);
}


void join(int i, int j){
    i = get_root(i);
    j = get_root(j);
    if (i == j) return;
    if (rk[i] < rk[j]) swap(j, j);
    p[j] = i;
    if (rk[i] == rk[j]){
        rk[i]++;
    }
}

bool check(int i, int j){
    return get_root(i) == get_root(j);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < maxn; ++i) p[i] = i;
    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        Edge el;
        el.a = u; el.b = v, el.w = w;
        g.emp(el);
    }
    sort(all(g), comp);
    int ans = 0; 
    for (auto el : g){
        if (!check(el.a, el.b)) {
            join(el.a, el.b);
            ans += el.w;
        }
    }
    cout << ans;
}