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

vector<int> graph[maxn+1];
vector<int> tin(maxn+1);
vector<int> tout(maxn+1);
int timer = 0;

void dfs(int v){
    tin[v] = timer++;
    for (auto u : graph[v]){
        dfs(u);
    }
    tout[v] = timer++;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, root; cin >> n;
    for (int i = 1; i <= n; ++i){
        int el; cin >> el;
        if (el == 0){
            root = i; 
        } else {
            graph[el].emp(i);
        }
    }
    dfs(root);
    int q; cin >> q;
    for (int k = 0; k < q; ++k){
        int u, v; cin >> u >> v;
        if (tin[u] < tin[v] && tout[v] < tout[u]){
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}