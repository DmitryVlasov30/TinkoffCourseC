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
const int maxn = 2e5;

vector<int> graf[maxn + 2];
vector<int> c(maxn + 2);
void dfs(int u, int n) {
    if (u == n){
        stack<int> path;
        for(int v = n; v != 1; v = c[v]){
            path.push(v);
        }
        cout << 1;
        while(!path.empty()){cout << " " << path.top(); path.pop();}
        exit(0);
    }

    for (int v : graf[u]){
        if (c[v] == 0){
            c[v] = u;
            dfs(v, n);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i = 2; cin >> n;
    for (int u = 0; u < n-1; ++u){
        int v; cin >> v;
        graf[v].emp(i);
        ++i;
    }
    c[1] = -1;
    int cnt = 0;
    dfs(1, n);
}