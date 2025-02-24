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
const int max_el = 41;

vector<int> c(maxn + 1);
vector<int> pred(maxn, -1);
vector<int> t[4 * maxn];
vector<int> arr(maxn);


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> dist(n+1, inf);
    dist[1] = 0;
    bool flag_stop = true;

    while(flag_stop){
        flag_stop = false;
        for (int i = 1; i < n; ++i){
            for (int j = i+1; j <= n; ++j){
                int res = (179 * i + 719 * j) % 1000 - 500;
                if (dist[i] < inf && dist[j] > dist[i] + res){
                    dist[j] = dist[i] + res;
                    flag_stop = true;
                }
            }
        }
    }
    
    cout << dist[n];
}