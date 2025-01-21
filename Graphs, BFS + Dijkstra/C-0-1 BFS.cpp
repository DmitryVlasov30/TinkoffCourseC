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

vector<vector<pair<int,int>>> graf(maxn);
vector<int> c(maxn + 1);

vector<int> bfs(int start, int n, int m){
    vector<int> dist(n+1, inf);

    dist[start] = 0;
    deque<int> q;
    q.push_front(start);
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(auto [v, c] : graf[u]){
            if (dist[v] > dist[u] + c){
                if(c == 0){
                    dist[v] = dist[u];
                    q.push_front(v);
                } else {
                    dist[v] = dist[u] + 1;
                    q.push_back(v);
                }
            }
        }
    }
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < m; ++i){
        int u, v, c; cin >> u >> v >> c;
        graf[u].emp(make_pair(v, c)); graf[v].emp(make_pair(u, c));
    }

    vector<int> ans = bfs(s, n, m);
    for (int i = 1; i <= n; ++i){
        if (ans[i] == inf){
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
}