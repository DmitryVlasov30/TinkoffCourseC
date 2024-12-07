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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> arr(n+2, vector<ll>(m+2, 0));
    for (int i = 0; i < q; ++i){
        ll i1, j1, i2, j2, d;
        cin >> i1 >> j1 >> i2 >> j2 >> d;
        arr[i1][j1] += d;
        arr[i1][j2+1] -= d;
        arr[i2+1][j1] -= d;
        arr[i2+1][j2+1] += d;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            arr[i][j] = ((arr[i-1][j] + arr[i][j-1]) - arr[i-1][j-1]) + arr[i][j];
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
