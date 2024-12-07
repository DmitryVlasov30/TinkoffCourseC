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
    ll n, r, j = 0;
    cin >> n >> r;
    vector<ll> arr;
    for(int i = 0; i < n; ++i){
        ll el;
        cin >> el;
        arr.emplace_back(el);
    }
    ll ans = 0;
    sort(all(arr));
    for (int i = 0; i < n; ++i){
        while(j+1 < n && arr[j] - arr[i] <= r){
            j++;
        }
        ans += ((len(arr)-1)-j);
        if (arr[j] - arr[i] > r){
            ans++;
        }
        //cout << i << " " << j << "\n";
    }
    cout << ans << "\n"; 
}


