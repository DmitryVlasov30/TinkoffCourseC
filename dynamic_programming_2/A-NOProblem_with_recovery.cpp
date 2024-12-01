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
    int n; cin >> n;
    vector<int> arr, arr2;
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        arr.emp(a);
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i){
        int a; cin >> a;
        arr2.emp(a);
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (arr[i-1] == arr2[j-1]){
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            } else {
                dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
            }
        }
    }

    int ans = dp[n][m];
    int i = n, j = m;
    vector<int> res;
    while (i > 0 && j > 0) {
        if (arr[i-1] == arr2[j-1]){
            res.emp(arr[i-1]); 
            --i; --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(all(res));
    cout << ans << "\n";
    for(int i = 0; i < len(res); ++i){
        cout << res[i] << " ";
    }
}
