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
vector<int> rk(maxn, 0);
vector<int> p(maxn);
vector<int> sum(maxn);


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
    sum[i] += sum[j];
    if (rk[i] == rk[j]) rk[i]++;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    --s;
    
    vector<int> w_arr;
    for (int i = 0; i < n; ++i){
        int w; cin >> w; w_arr.emp(w);
    }
    
    for (int i = 0; i < n; ++i) {p[i] = i; sum[i] = w_arr[i];} 

    for (int i = 0; i < m; i++){
        Edge el; cin >> el.a >> el.b >> el.w;
        el.a--; el.b--;
        g.emp(el);
    }

    sort(all(g), [](Edge a, Edge b){
        return a.w < b.w;
    });

    int ans = w_arr[s];
    for (auto edge : g){
        if (edge.w > ans) break;
        join(edge.a, edge.b);
        ans = max(ans, sum[get_root(edge.a)]);
    } 
    cout << ans;
}