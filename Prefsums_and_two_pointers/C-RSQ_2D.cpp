#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n+1, vector<ll>(m+1, 0));
    vector<vector<ll>> pref(n+1, vector<ll>(m+1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> arr[i][j];
            pref[i][j] = ((pref[i-1][j] + pref[i][j-1]) - pref[i-1][j-1]) + arr[i][j];
        }
    }
    ll q;
    cin >> q;
    vector<ll> ans;
    for (int i = 0; i < q; ++i){
        ll i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        ll res = pref[i2][j2] - pref[i1-1][j2] - pref[i2][j1-1] + pref[i1-1][j1-1];
        ans.emplace_back(res);
    }

    for(int i = 0; i < len(ans); ++i){
        cout << ans[i] << " ";
    }
}

