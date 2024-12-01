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
    int n, a, k, b, m; cin >> n >> a >> k >> b >> m;
    vector<int> arr;
    int last_a = a;
    arr.emp(a);
    for (int i = 1; i <= n; ++i){
        a = (k * a + b) % m;
        arr.emp(a);
    }
    vector<int> dp(n+1, inf);
    dp[0] = -inf;
    for (int i = 0; i < n; ++i){
        int idx = lower_bound(all(dp), arr[i]) - dp.begin();
        dp[idx] = arr[i]; 
    }
    int ans = lower_bound(all(dp), inf) - dp.begin() - 1;
    cout << ans;
}
