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
    string s1, s2;
    cin >> s1 >> s2;
    int n = len(s1), m = len(s2);
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for (int i = 0; i <= n; ++i){
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j){
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    cout << dp[n][m];

}
