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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<ll>>> pref(n+1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, 0)));
    for (ll x = 1; x <= n; ++x) {
        for (ll y = 1; y <= m; ++y) {
            for (ll z = 1; z <= k; ++z) {
                ll el;
                cin >> el;
                pref[x][y][z] = el
                              + pref[x - 1][y][z]
                              + pref[x][y - 1][z]
                              + pref[x][y][z - 1]
                              - pref[x - 1][y - 1][z]
                              - pref[x - 1][y][z - 1]
                              - pref[x][y - 1][z - 1]
                              + pref[x - 1][y - 1][z - 1];
            }
        }
    }

    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll lx, ly, lz, rx, ry, rz;
        cin >> lx >> ly >> lz >> rx >> ry >> rz;
        ll result = pref[rx][ry][rz]
                    - (pref[lx - 1][ry][rz])
                    - (pref[rx][ly - 1][rz])
                    - (pref[rx][ry][lz - 1])
                    + (pref[lx - 1][ly - 1][rz])
                    + (pref[lx - 1][ry][lz - 1])
                    + (pref[rx][ly - 1][lz - 1])
                    - (pref[lx - 1][ly - 1][lz - 1]);
        cout << result << " ";
    }
}
