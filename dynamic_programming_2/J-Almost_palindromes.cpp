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


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 2; i <= n; ++i){
        for (int j = 0; j < n - i + 1; ++j){
            int ij = j + i - 1;
            if (s[j] == s[ij]){
                dp[j][ij] = dp[j+1][ij-1];
            } else {
                dp[j][ij] = dp[j+1][ij-1] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            if (dp[i][j] <= k){
                ans++;
            }
        }
    }
    cout << ans;
     
}   
