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

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;
const int maxn = 4e5 + 1;
const int logn = 20;

struct Edge {
    int a, b, w;
};

vector<Edge> g;
vector<int> rk(maxn, 1);
vector<int> p(maxn);

bool comp(Edge a, Edge b){
    return a.w < b.w;
}

int get_root(int i){
    if (p[i] == i) return i;
    return p[i] = get_root(p[i]);
}

void join(int i, int j){
    i = get_root(i);
    j = get_root(j);
    if (i == j) return;
    if (rk[i] < rk[j]) swap(i, j);
    p[j] = i;
    rk[i] += rk[j];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x; cin >> n >> m >> x;
    for (int i = 0; i < m; ++i){
        Edge el{}; cin >> --el.a >> --el.b >> el.w;
        g.emp(el);
    }

    int ans = 0;
    for (int i = 0; i < maxn; ++i) p[i] = i;
    sort(all(g), comp);
    for (Edge edge : g) {
        if (edge.w > x) break;
        if (edge.w == x && get_root(edge.a) != get_root(edge.b)) {
            ans += rk[get_root(edge.a)] * rk[get_root(edge.b)];
        }
        join(edge.a, edge.b);
    }

    cout << ans;
}