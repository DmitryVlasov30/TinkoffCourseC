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
const int maxn = 1e6;
const int logn = 20;

struct Edge {
    int a, b;
    ld w;
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int s, e; cin >> s >> e;
    --s; --e;
    vector<Edge> edges;
    
    for (int i = 0; i < m; ++i){
        Edge el; cin >> el.a >> el.b >> el.w;
        --el.a; --el.b;
        el.w = 1.0 - el.w / 100.0;
        //cout << el.w << "\n";
        edges.emp(el);
    }

    vector<ld> dist(n, 0.0);
    dist[s] = 1.0; 
    for (int i = 0; i < n-1; ++i){
        for (auto& [a, b, w] : edges){
            dist[b] = max(dist[b], dist[a] * w);
            dist[a] = max(dist[a], dist[b] * w);
        }
    }
    cout << fixed << setprecision(6) << 1.0 - dist[e];
}