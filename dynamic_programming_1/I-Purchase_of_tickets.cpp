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

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e18;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for (int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1] = a[0];
    if (n > 1){
        dp[2] = min(dp[1]+a[1], b[0]);
    } if (n > 2){
        dp[3] = min(dp[2]+a[2], min(dp[1]+b[1], c[0]));
    }
    for (int i = 4; i <= n; ++i){
        int ans = dp[i-1] + a[i-1];
        ans = min(ans, dp[i-2] + b[i-2]);
        ans = min(ans, dp[i-3] + c[i-3]);
        dp[i] = ans;
    }

    cout << dp[n];
}


