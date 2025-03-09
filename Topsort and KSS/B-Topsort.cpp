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
const int logn = 20;

vector<int> graph[maxn];  
vector<int> c(maxn);    
int timer = 0;
vector<int> tin(maxn), tout(maxn);
pair<int,int> up[maxn][logn];
vector<int> used(maxn, 0);
vector<int> output;


void dfs(int u) {
    c[u] = 1; 
    for (int v : graph[u]) {
        if (c[v] == 0) {
            dfs(v);
        } else if (c[v] == 1) { 
            cout << -1; exit(0);
        }
    }
    c[u] = 2;
}


void topsort(int v){
    if (used[v]) return;
    used[v] = 1;
    for (int u : graph[v]){
        topsort(u);
    } 
    output.emp(v);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v; 
        graph[u].emp(v);
    }

    for (int u = 1; u <= n; ++u) {
        if (c[u] == 0) {
            dfs(u);
        }
    }
    
    for (int i = 1; i <= n; ++i){
        topsort(i);
    }
    reverse(all(output));
    for (int el : output){
        cout << el << " ";
    }
}