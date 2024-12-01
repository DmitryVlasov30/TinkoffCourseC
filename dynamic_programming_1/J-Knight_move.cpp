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
    vector<vector<int>> dp(10, vector<int>(n+1, 0));
    for (int i = 0; i < 10; ++i){
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 0; j < 10; ++j){
            if(j == 0){
                dp[0][i] = (dp[4][i-1] + dp[6][i-1]) % mod;
            }
            if (j == 1){
                dp[1][i] = (dp[6][i-1] + dp[8][i-1]) % mod;
            }
            if (j == 2){
                dp[2][i] = (dp[7][i-1] + dp[9][i-1]) % mod;
            }
            if (j == 3){
                dp[3][i] = (dp[8][i-1] + dp[4][i-1]) % mod;
            }
            if (j == 4){
                dp[4][i] = (dp[9][i-1] + dp[3][i-1] + dp[0][i-1]) % mod;
            }
            if (j == 6){
                dp[6][i] = (dp[1][i-1] + dp[7][i-1] + dp[0][i-1]) % mod;
            }
            if (j == 7){
                dp[7][i] = (dp[2][i-1] + dp[6][i-1]) % mod;
            }
            if (j == 8){
                dp[8][i] = (dp[3][i-1] + dp[1][i-1]) % mod;
            }
            if (j == 9){
                dp[9][i] = (dp[2][i-1] + dp[4][i-1]) % mod;
            }
        }

    }
    //cout << len(dp);
    int ans = 0;
    for(int i = 1; i <= 9; ++i){
        if (i != 8){
            ans = (ans + dp[i][n]) % mod;
        }
    }

    cout << ans;

}
