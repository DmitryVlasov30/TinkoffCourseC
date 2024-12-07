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
    ll n;
    cin >> n;
    stack<pair<ll, ll>> arr;
    vector<ll> all_el(n+1);
    all_el[n] = -1;
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> all_el[i];
    }
    for (int i = 0; i < n; ++i){
        int el = all_el[i];

        if (!arr.empty() && arr.top().first == el){
            arr.top().second++;
        } else {
            arr.push({el, 1});
        }
        while (!arr.empty() && arr.top().second >= 3 && arr.top().first != all_el[i+1]){
            ans += arr.top().second;
            arr.pop();
        }
    }
    cout << ans;
}
