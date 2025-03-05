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
#include <cassert>

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

struct Edge {
    int a, b, w;
};


void bfs(int start, vector<vector<int>>& g, vector<int>& reach){
    queue<int> q;
    q.push(start);
    reach[start] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            if(reach[v] != 1){
                reach[v] = 1;
                q.push(v);
            }
        }
    }
}


bool check_cycle(vector<Edge>& edge, vector<int> distance, int n, vector<int>& reach_s, vector<int>& reach_e){
    for (const Edge &edge : edge) {
        if (distance[edge.a] != inf && 
            distance[edge.a] + edge.w < distance[edge.b]) {
            if (reach_s[edge.a] == 1 && reach_e[edge.b] == 1) return true;
        }
    }

    return false;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, start = 0; cin >> n >> m;
    vector<Edge> edges(m);
    vector<vector<int>> g(n), g_rev(n);
    for (auto& [a, b, w] : edges){
        cin >> a >> b >> w;
        --a; --b;
        w = -w;
        g[a].emp(b); g_rev[b].emp(a);
    }

    vector<int> reach_s(n, 0), reach_e(n, 0);

    bfs(start, g, reach_s);
    bfs(n-1, g_rev, reach_e);

    vector<int> dist(n, inf);
    dist[start] = 0;
    for (int i = 0; i < n-1; ++i){
        for (auto& [a, b, w] : edges){
            if (dist[a] != inf && dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
            }
        }
    }

    if (dist[n-1] == inf){
        cout << ":("; return 0;
    }

    if (check_cycle(edges, dist, n, reach_s, reach_e)){
        cout << ":)"; return 0;
    }

    cout << -dist[n-1];
}