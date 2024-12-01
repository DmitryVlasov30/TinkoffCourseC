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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (i-2 >= 0 && j-1 >= 0){
                dp[i][j] += dp[i-2][j-1];
            } if (i-1 >= 0 && j-2 >= 0){
                dp[i][j] += dp[i-1][j-2];
            }
        }
    }
    cout << dp[--n][--m];
}
