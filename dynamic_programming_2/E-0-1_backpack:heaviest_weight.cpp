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
    int n, w; cin >> n >> w;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        int el; cin >> el;
        arr.emp(el);
    }
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= w; ++j){
            if (j >= arr[i-1]){
                dp[i][j] = max(dp[i-1][j-arr[i-1]] + arr[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w];
    
}
