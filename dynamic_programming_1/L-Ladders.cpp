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
#define mpp(x) make_pair(x)
#define emp emplace_back

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i){
        for (int j = i; j >= 0; --j){
            for (int k = j-1; k >= 0; --k){
                dp[j][i] += dp[k][i-j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i){
        ans += dp[i][n];
    }
    cout << ans;
}
