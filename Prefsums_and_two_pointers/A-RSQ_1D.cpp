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
    vector<ll> arr;
    vector<ll> pref;
    pref.emplace_back(0);
    for (int i = 1; i <= n; ++i){
        ll el;
        cin >> el;
        pref.emplace_back(el+pref[i-1]);
        arr.emplace_back(el);
    }
    ll q;
    cin >> q;
    vector<ll> ans;
    for(int i = 0; i < q; ++i){
        ll left, right;
        cin >> left >> right;
        ans.emplace_back(pref[right] - pref[left-1]);
    }

    for (auto el : ans){
        cout << el << " ";
    }
}

