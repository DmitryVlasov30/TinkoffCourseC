#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <algorithm>

#define ll long long
#define len(x) x.size()
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> arr;
    for (int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        arr.emplace_back(el);
    }
    sort(all(arr));
    for(int i = 0; i < q; ++i){
        ll x;
        cin >> x;
        ll left = 0, right = n;
        while (right - left > 1){
            ll mid = (left+right)/2;
            if (arr[mid] > x){
                right = mid;
            } else {
                left = mid;
            }
        }
        if(arr[right-1] == x){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
