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
    vector<int> arr;
    int w = 0;
    for(int i = 0; i < n; ++i){
        int el; cin >> el;
        arr.emp(el);
        w += el;
    }
    vector<vector<int>> dp((w/2) + 1, vector<int> (n+1, 0));
    for (int i = 0; i <= n; ++i){
        dp[0][i] = 1;
    }
    if (w % 2 != 0){
        cout << "NO"; return 0;
    }
    for (int i = 1; i <= w/2; ++i){
        for (int j = 1; j <= n; ++j){
            if (i - arr[j-1] >= 0){
                if (dp[i][j-1] == 1 || dp[i-arr[j-1]][j-1] == 1){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    if (dp[w/2][n] == 1){
        cout << "YES";
    } else {
        cout << "NO";
    }
    //cout << dp[w/2][n];
    /*
    for (int i = 0; i < len(dp); ++i){
        for (int j = 0; j < len(dp[i]); ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";   
    }
    */

}
