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
#include <numbers>
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


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, a));
    dp[0][0] = 1;
    for (int k = 0; k < n + m - 1; ++k) {
        int i = max(a, k - m + 1), j = min(k, m - 1);
        while (i < n && j >= 0) {
            if (i+1 < n && j-2 >= 0){
                dp[i][j] += dp[i+1][j-2];
            } if (i-2 >= 0 && j-1 >= 0){
                dp[i][j] += dp[i-2][j-1];
            } if (i-1 >= 0 && j-2 >= 0){
                dp[i][j] += dp[i-1][j-2];
            } if (i-2 >= 0 && j+1 < m){
                dp[i][j] += dp[i-2][j+1];
            }
            ++i;
            --j;
        }
    }
    cout << dp[--n][--m];
}
