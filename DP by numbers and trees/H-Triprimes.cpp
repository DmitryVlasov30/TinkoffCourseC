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
const int maxn = 1e4 + 10;
const int logn = 20;

int is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> primes(1e3+1, 0);
    for (int i = 100; i <= 999; ++i){
        primes[i] = is_prime(i);
    }

    vector<vector<vector<int>>> dp(maxn, vector<vector<int>>(10, vector<int>(10, 0)));
    for (int i = 0; i <= 9; ++i){
        for (int j = 0; j <= 9; ++j){
            for (int k = 0; k <= 9; ++k){
                int idx = i * 100 + j * 10 + k;
                if (primes[idx]){
                    dp[3][k][j] += 1;
                    dp[3][k][j] %= mod;
                }
            }
        }
    }

    for (int num = 4; num <= n; ++num){
        for (int i = 0; i <= 9; ++i){
            for (int j = 0; j <= 9; ++j){
                for (int k = 0; k <= 9; ++k){
                    int idx = i * 100 + j * 10 + k;
                    if (primes[idx]){
                        dp[num][k][j] += dp[num - 1][j][i];
                        dp[num][k][j] %= mod;
                    }    
            
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; ++i){
        for (int j = 0; j <= 9; ++j){
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
}