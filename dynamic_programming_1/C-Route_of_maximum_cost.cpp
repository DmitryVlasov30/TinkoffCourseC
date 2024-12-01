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
    vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j]; 
        }
    }
    int ans = dp[n][m];
    vector<string> ans_put;
    int i = n, j = m;
    while (i != 1 || j != 1){
        int el1 = dp[i-1][j], el2 = dp[i][j-1];
        if (dp[i][j] - arr[i][j] == el1){
            ans_put.emplace_back("D");
            --i;
        } else if (dp[i][j] - arr[i][j] == el2) {
            --j;
            ans_put.emplace_back("R");
        }

    }
    cout << ans << "\n";
    reverse(all(ans_put));
    for(int i = 0; i < len(ans_put); ++i){
        cout << ans_put[i] << " ";
    }
}
