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
#include <cstring>
#include <cassert>

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

const int mod = 1e9 + 9;
const int inf = 1e18;
const int maxn = 1e5 + 10;
const int logn = 20;

struct Edge {
    int v, wight;
    Edge (int u, int w){
        v = u; wight = w;
    }
};

vector<int> graf[maxn], gr[maxn];
int timer = 0;
vector<int> used(maxn, 0), color(maxn, 0);
vector<int> output;


void topsort(int v){
    used[v] = 1;
    for (int u : graf[v]){
        if (!used[u]) topsort(u);
    }
    output.emp(v);
}


void condens(int v, int c) {
    used[v] = 1;
    color[v] = c;
    for (int u : gr[v]) {
        if (!used[u]) condens(u, c);
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        if (!v) continue;
        graf[u].emp(v);
        gr[v].emp(u);
    }

    for (int i = 1; i <= n; ++i){
        if (!used[i]) topsort(i);
    }

    for (int i = 0; i < maxn; ++i) { used[i] = 0; }

    reverse(all(output));

    int count = 0;
    for (int v : output){
        if (!used[v]) condens(v, ++count);
    }

    map<int,int> number_vert;
    for (int c : color){
        if (c) number_vert[c]++;
    }

    int count_csc = 0;
    for (auto& el : number_vert){
        if (el.second >= 2) ++count_csc;
    }
    cout << count_csc + count;
}