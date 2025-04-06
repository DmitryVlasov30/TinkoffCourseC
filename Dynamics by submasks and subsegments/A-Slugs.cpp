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
const int maxn = 2e5 + 1;
const int logn = 20;

struct Edge {
    int a, b, w;
};

vector<Edge> g;
vector<int> rk(maxn, 1);
vector<int> p(maxn);


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr, pref(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int el; cin >> el; arr.emp(el);
    }
    for (int i = 0; i < n; ++i){
        pref[i+1] += pref[i] + arr[i];
    }
    vector<vector<int>> dp(n, vector<int> (n, inf));
    for (int i = 0; i < n; ++i){
        dp[i][i] = 0;
    }

    for (int length = 2; length <= n; ++length){
        for (int l = 0; l + length - 1 < n; ++l){
            int r = l + length - 1;
            for (int k = l; k < r; ++k){
                int first_el = dp[l][k], second_el = dp[k+1][r];
                int cost = first_el + second_el + (pref[r+1] - pref[l]);
                dp[l][r] = min(cost, dp[l][r]);
            }

        }
    }
    cout << dp[0][n-1];
}