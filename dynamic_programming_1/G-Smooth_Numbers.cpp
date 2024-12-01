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
    vector<vector<int>> dp(n+1, vector<int>(10, 0));

    for (int i = 1; i <= 9; ++i){
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i){
        for (int j = 0; j <= 9; ++j){
            if (j != 0){
                dp[i][j] += dp[i-1][j-1];
            }
            if (j != 9){
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] += dp[i-1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; ++i){
        ans += dp[n][i];
    }

    cout << ans;

}
