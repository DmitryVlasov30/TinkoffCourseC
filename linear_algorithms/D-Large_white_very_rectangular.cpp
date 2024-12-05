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

#define int long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()
#define ld long double
#define fir first
#define sec second
#define emp emplace_back

using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e7;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            int el; cin >> el;
            if (el == 1){
                dp[i][j] = 0;
            } else {
                if (i == 0){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }
    }
    /*
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    int max_ans = -inf;
    for (int i = n-1; i >= 0; --i){
        vector<int> rez_right, rez_left;
        stack<int> st;
        for (int k = m-1; k >= 0; --k){
            while (!st.empty() && dp[i][st.top() - 1] >= dp[i][k]){
                st.pop();
            }
            if (!st.empty()){
                rez_right.emp(st.top());
            } else {
                rez_right.emp(-1);
            }
            st.push(k+1);
        }
        reverse(all(rez_right));
        while(!st.empty()){st.pop();}
        for (int k = 0; k < m; ++k){
            while (!st.empty() && dp[i][st.top() - 1] >= dp[i][k]){
                st.pop();
            }
            if (!st.empty()){
                rez_left.emp(st.top());
            } else {
                rez_left.emp(-1);
            }
            st.push(k+1);
        }
        vector<int> ans;
        for (int k = 0; k < m; ++k){
            int left = rez_left[k], right = rez_right[k], x = 0;
            if (right == -1 && left == -1){
                x = dp[i][k] * m;
            } else if (right == -1){
                x = dp[i][k] * (m - left);
            } else if (left == -1){
                x = dp[i][k] * (right-1);
            } else {
                x = dp[i][k] * (right - left - 1);
            }
            //cout << right << " " << left << " " << arr[i] << "\n";
            ans.emp(x);
        }
        sort(all(ans));
        max_ans = max(ans[m-1], max_ans);
        /*
        for (int j = 0; j < m; ++j){
            cout << ans[j] << " ";
        }
        cout << "1------\n";
        for (int j = 0; j < m; ++j){
            cout << dop[j] << " ";
        }
        cout << "2-----\n";
        cout << i << " " << max_ans << " " << ans[m-1] << "<--\n";
        */
    }
    cout << max_ans;
}
