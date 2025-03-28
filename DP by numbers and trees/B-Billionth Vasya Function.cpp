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
#include <random>
#include <deque>
#include <cstring>

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
const int maxn = 2e5 + 1;
const int logn = 20;
const int max_d = 10; 
const int max_s = 85; 

int dp[max_d][max_s][2];
string limit = "1000000000";

int solve(int pos, int sum, int tig) {
    if (sum < 0) return 0;
    if (pos == len(limit)) return sum == 0;
    if (dp[pos][sum][tig] != -1) return dp[pos][sum][tig];

    int res = 0;
    int max_digit = tig ? (limit[pos] - '0') : 9;
    for (int d = 0; d <= max_digit; ++d){
        res += solve(pos + 1, sum - d, tig && (d == max_digit));
    }
    return dp[pos][sum][tig] = res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s; cin >> s;
    
    for(int i = 0; i < max_d; ++i) {
        for(int j = 0; j < max_s; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cout << solve(0, s, 1);
}