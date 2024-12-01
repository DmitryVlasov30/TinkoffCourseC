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
    int n, w; cin >> n >> w;
    vector<int> arr, c;
    for (int i = 0; i < n; ++i){
        int el; cin >> el;
        arr.emp(el);
    } 
    for (int i = 0; i < n; ++i){
        int ci; cin >> ci;
        c.emp(ci);
    }
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= w; ++j){
            if (j >= arr[i-1]){
                dp[i][j] = max(dp[i-1][j-arr[i-1]] + c[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int i = n, j = w;
    //cout << dp[n][w] << "ans \n";
    vector<int> ans;
    while (i != 0 && j != 0){
        if (dp[i][j] == dp[i-1][j]){
            --i;
            //cout << dp[i][j] << " " << i <<  "<---\n";
        } else {
            //cout << i << "<====\n";
            ans.emp(i);
            j -= arr[i-1];
            --i;
            //j -= arr[i-1];
        }
    }
    int summ = 0;
    for (int i = 0; i < len(ans); ++i){
        summ += c[ans[i]-1];
    }
    int ost = dp[n][w] - summ;
    for (int i = 0; i < n; ++i){
        if (c[i] == ost){
            ans.emp(i+1);
        }
    } 
    cout << len(ans) << "\n";
    for (int i = 0; i < len(ans); ++i){
        cout << ans[i] << " ";
    }
    
}
